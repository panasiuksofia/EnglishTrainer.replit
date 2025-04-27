#ifndef USER_H
#define USER_H

#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>

class User {
public:
  // Конструктор
  explicit User(const std::string &username);

  // Робота з балами
  void addPoints(int points);
  void deductPoints(int points);
  int getPoints() const;

  // Робота з прогресом
  void updateProgress(const std::string &lessonName, int percentage);
  int getProgress(const std::string &lessonName) const;
  const std::map<std::string, int> &getAllProgress() const;

  // Робота з завершеними уроками
  void addCompletedLesson(const std::string &lessonName);
  bool hasCompletedLesson(const std::string &lessonName) const;
  const std::vector<std::string> &getCompletedLessons() const;

  // Робота з файлами
  bool saveToFile(const std::string &filename) const;
  bool loadFromFile(const std::string &filename);

  // Вивід інформації
  void displayUserInfo() const;
  void displayProgress() const;

private:
  std::string username;
  int points;
  std::map<std::string, int> lessonProgress; // Назва уроку -> Прогрес (%)
  std::vector<std::string> completedLessons;

  // Приватні допоміжні методи
  void parseProgressLine(const std::string &line);
  void parseCompletedLessonsLine(const std::string &line);
};

#endif // USER_H
