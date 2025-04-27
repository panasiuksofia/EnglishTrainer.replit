#ifndef LESSON_H
#define LESSON_H

#include <chrono>
#include <string>
#include <vector>

class Lesson {
public:
  Lesson(const std::string &title, const std::string &theory,
         const std::vector<std::string> &tasks,
         const std::vector<std::string> &correctAnswers, int pointsReward = 10);

  void conduct();
  void evaluate();

  // Додано явне оголошення getTitle()
  const std::string &getTitle() const { return title; }
  const std::string &getTheory() const;
  const std::vector<std::string> &getTasks() const;
  const std::vector<std::string> &getUserAnswers() const;
  const std::vector<std::string> &getCorrectAnswers() const;

  int getScore() const;
  int getMaxScore() const;
  double getSuccessPercentage() const;
  int getPointsReward() const;
  bool isCompleted() const;
  std::chrono::seconds getTimeSpent() const;

  void displayTheory() const;
  void displayTasks() const;
  void displayResults() const;
  void displayFeedback() const;

  bool saveProgress(const std::string &filename) const;

private:
  std::string title;
  std::string theory;
  std::vector<std::string> tasks;
  std::vector<std::string> correctAnswers;
  std::vector<std::string> userAnswers;
  std::vector<bool> results;

  int pointsReward;
  bool completed;
  std::chrono::time_point<std::chrono::system_clock> startTime;
  std::chrono::time_point<std::chrono::system_clock> endTime;

  void startTimer();
  void stopTimer();
  void checkAnswers();
  void calculateResults();
};

#endif // LESSON_H
