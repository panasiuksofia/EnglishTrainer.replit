#include "User.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

User::User(const std::string &username) : username(username), points(0) {
  if (username.empty()) {
    throw std::invalid_argument("Username cannot be empty");
  }
}

// Бали
void User::addPoints(int points) {
  if (points < 0) {
    throw std::invalid_argument("Points value must be positive");
  }
  this->points += points;
}

void User::deductPoints(int points) {
  if (points < 0) {
    throw std::invalid_argument("Points value must be positive");
  }
  this->points = std::max(0, this->points - points);
}

int User::getPoints() const { return points; }

// Прогрес
void User::updateProgress(const std::string &lessonName, int percentage) {
  if (percentage < 0 || percentage > 100) {
    throw std::out_of_range("Percentage must be between 0 and 100");
  }
  lessonProgress[lessonName] = percentage;

  if (percentage == 100) {
    addCompletedLesson(lessonName);
  }
}

int User::getProgress(const std::string &lessonName) const {
  auto it = lessonProgress.find(lessonName);
  return (it != lessonProgress.end()) ? it->second : 0;
}

const std::map<std::string, int> &User::getAllProgress() const {
  return lessonProgress;
}

// Завершені уроки
void User::addCompletedLesson(const std::string &lessonName) {
  if (!hasCompletedLesson(lessonName)) {
    completedLessons.push_back(lessonName);
  }
}

bool User::hasCompletedLesson(const std::string &lessonName) const {
  return std::find(completedLessons.begin(), completedLessons.end(),
                   lessonName) != completedLessons.end();
}

const std::vector<std::string> &User::getCompletedLessons() const {
  return completedLessons;
}

// Робота з файлами
bool User::saveToFile(const std::string &filename) const {
  std::ofstream outFile(filename);
  if (!outFile.is_open()) {
    return false;
  }

  // Записуємо основну інформацію
  outFile << "[User]\n";
  outFile << "Username=" << username << "\n";
  outFile << "Points=" << points << "\n";

  // Записуємо прогрес
  outFile << "[Progress]\n";
  for (const auto &[lesson, percent] : lessonProgress) {
    outFile << lesson << "=" << percent << "\n";
  }

  // Записуємо завершені уроки
  outFile << "[CompletedLessons]\n";
  for (const auto &lesson : completedLessons) {
    outFile << lesson << "\n";
  }

  outFile.close();
  return true;
}

bool User::loadFromFile(const std::string &filename) {
  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    return false;
  }

  std::string line;
  std::string currentSection;

  while (std::getline(inFile, line)) {
    if (line.empty())
      continue;

    // Перевірка на нову секцію
    if (line[0] == '[' && line.back() == ']') {
      currentSection = line.substr(1, line.size() - 2);
      continue;
    }

    // Парсинг відповідно до секції
    if (currentSection == "User") {
      size_t delimiterPos = line.find('=');
      if (delimiterPos == std::string::npos)
        continue;

      std::string key = line.substr(0, delimiterPos);
      std::string value = line.substr(delimiterPos + 1);

      if (key == "Username") {
        username = value;
      } else if (key == "Points") {
        try {
          points = std::stoi(value);
        } catch (...) {
          points = 0;
        }
      }
    } else if (currentSection == "Progress") {
      parseProgressLine(line);
    } else if (currentSection == "CompletedLessons") {
      parseCompletedLessonsLine(line);
    }
  }

  inFile.close();
  return true;
}

void User::parseProgressLine(const std::string &line) {
  size_t delimiterPos = line.find('=');
  if (delimiterPos == std::string::npos)
    return;

  std::string lesson = line.substr(0, delimiterPos);
  std::string percentStr = line.substr(delimiterPos + 1);

  try {
    int percent = std::stoi(percentStr);
    lessonProgress[lesson] = percent;
  } catch (...) {
    // Ігноруємо помилки парсингу
  }
}

void User::parseCompletedLessonsLine(const std::string &line) {
  if (!line.empty()) {
    addCompletedLesson(line);
  }
}

// Вивід інформації
void User::displayUserInfo() const {
  std::cout << "=== User Information ===\n";
  std::cout << "Username: " << username << "\n";
  std::cout << "Points: " << points << "\n";
  std::cout << "Completed lessons: " << completedLessons.size() << "\n";
}

void User::displayProgress() const {
  std::cout << "=== Learning Progress ===\n";
  for (const auto &[lesson, percent] : lessonProgress) {
    std::cout << lesson << ": " << percent << "%";
    if (hasCompletedLesson(lesson)) {
      std::cout << " (completed)";
    }
    std::cout << "\n";
  }
}