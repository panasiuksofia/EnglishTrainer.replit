#include "Lesson.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

Lesson::Lesson(const std::string &title, const std::string &theory,
               const std::vector<std::string> &tasks,
               const std::vector<std::string> &correctAnswers, int pointsReward)
    : title(title), theory(theory), tasks(tasks),
      correctAnswers(correctAnswers), pointsReward(pointsReward),
      completed(false) {

  if (title.empty()) {
    throw std::invalid_argument("Lesson title cannot be empty");
  }
  if (tasks.size() != correctAnswers.size()) {
    throw std::invalid_argument("Tasks and answers count mismatch");
  }
  if (pointsReward < 0) {
    throw std::invalid_argument("Points reward must be non-negative");
  }
}

void Lesson::conduct() {
  startTimer();
  completed = false;
  userAnswers.clear();
  results.clear();

  displayTheory();
  displayTasks();

  for (size_t i = 0; i < tasks.size(); ++i) {
    std::string answer;
    std::cout << "Відповідь " << i + 1 << "/" << tasks.size() << ": ";
    std::getline(std::cin, answer);

    answer.erase(answer.begin(),
                 std::find_if(answer.begin(), answer.end(),
                              [](int ch) { return !std::isspace(ch); }));
    answer.erase(std::find_if(answer.rbegin(), answer.rend(),
                              [](int ch) { return !std::isspace(ch); })
                     .base(),
                 answer.end());

    userAnswers.push_back(answer);
  }

  stopTimer();
  evaluate();
}

void Lesson::evaluate() {
  checkAnswers();
  calculateResults();
  completed = true;
}

const std::string &Lesson::getTheory() const { return theory; }

const std::vector<std::string> &Lesson::getTasks() const { return tasks; }

const std::vector<std::string> &Lesson::getUserAnswers() const {
  return userAnswers;
}

const std::vector<std::string> &Lesson::getCorrectAnswers() const {
  return correctAnswers;
}

int Lesson::getScore() const {
  return std::count(results.begin(), results.end(), true);
}

int Lesson::getMaxScore() const { return tasks.size(); }

double Lesson::getSuccessPercentage() const {
  if (tasks.empty()) {
    return 0.0;
  }
  return (static_cast<double>(getScore()) / getMaxScore()) * 100;
}

int Lesson::getPointsReward() const {
  return completed
             ? static_cast<int>(pointsReward * getSuccessPercentage() / 100)
             : 0;
}

bool Lesson::isCompleted() const { return completed; }

std::chrono::seconds Lesson::getTimeSpent() const {
  if (!completed)
    return std::chrono::seconds(0);
  return std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
}

void Lesson::displayTheory() const {
  std::cout << "\n=== " << title << " ===\n";
  std::cout << theory << "\n";
}

void Lesson::displayTasks() const {
  std::cout << "\n=== Завдання (" << tasks.size() << ") ===\n";
  for (size_t i = 0; i < tasks.size(); ++i) {
    std::cout << i + 1 << ". " << tasks[i] << "\n";
  }
  std::cout << std::endl;
}

void Lesson::displayResults() const {
  if (!completed) {
    std::cout << "Урок ще не завершено.\n";
    return;
  }

  std::cout << "\n=== Результати: " << title << " ===\n";
  std::cout << "Правильних відповідей: " << getScore() << "/" << getMaxScore()
            << "\n";
  std::cout << "Успішність: " << std::fixed << std::setprecision(1)
            << getSuccessPercentage() << "%\n";
  std::cout << "Витрачено часу: " << getTimeSpent().count() << " сек.\n";
  std::cout << "Отримано балів: " << getPointsReward() << "\n";
}

void Lesson::displayFeedback() const {
  if (!completed)
    return;

  std::cout << "\n=== Розбір відповідей ===\n";
  for (size_t i = 0; i < tasks.size(); ++i) {
    std::cout << "\nЗавдання " << i + 1 << ": " << tasks[i] << "\n";
    std::cout << "Ваша відповідь: " << userAnswers[i] << "\n";
    std::cout << "Правильна відповідь: " << correctAnswers[i] << "\n";
    std::cout << (results[i] ? "✓ Правильно" : "✗ Неправильно") << "\n";
  }
}

bool Lesson::saveProgress(const std::string &filename) const {
  if (!completed)
    return false;

  std::ofstream file(filename, std::ios::app);
  if (!file.is_open())
    return false;

  auto timeSpent = getTimeSpent();

  file << "[Lesson]\n";
  file << "Title=" << title << "\n";
  file << "Score=" << getScore() << "/" << getMaxScore() << "\n";
  file << "Percentage=" << std::fixed << std::setprecision(1)
       << getSuccessPercentage() << "\n";
  file << "TimeSpent=" << timeSpent.count() << "\n";
  file << "PointsEarned=" << getPointsReward() << "\n";
  file << "Completed=" << (completed ? "true" : "false") << "\n\n";

  file.close();
  return true;
}

void Lesson::startTimer() { startTime = std::chrono::system_clock::now(); }

void Lesson::stopTimer() { endTime = std::chrono::system_clock::now(); }

void Lesson::checkAnswers() {
  results.reserve(userAnswers.size());
  for (size_t i = 0; i < userAnswers.size(); ++i) {
    results.push_back(userAnswers[i] == correctAnswers[i]);
  }
}

void Lesson::calculateResults() {
  // Додаткова логіка для аналізу результатів
}
