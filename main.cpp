#include "Lesson.h"
#include "User.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Створення користувача
  User user("EnglishLearner");

  // Теорії
  string theoryPresentSimple =
      "Tense: Present Simple\n\n"
      "Usage:\n"
      "1. To express habits and routines.\n"
      "   Example: She goes to school every day.\n"
      "2. To express general truths and facts.\n"
      "   Example: The sun rises in the east.\n"
      "3. To express fixed arrangements or timetables.\n"
      "   Example: The train leaves at 6 p.m.\n"
      "\nForm:\n"
      "- Affirmative: Subject + base verb (+s/es for he/she/it)\n"
      "  Example: He plays football.\n"
      "- Negative: Subject + do/does not + base verb\n"
      "  Example: They do not like coffee.\n"
      "- Interrogative: Do/Does + subject + base verb?\n"
      "  Example: Do you speak English?\n"
      "\nTime Expressions:\n"
      "- always, usually, often, sometimes, never, every day/week, on Mondays";

  string theoryPresentContinuous =
      "Tense: Present Continuous\n\n"
      "Usage:\n"
      "1. To describe actions happening right now.\n"
      "   Example: She is reading a book.\n"
      "2. To describe temporary situations.\n"
      "   Example: I am staying with my friend this week.\n"
      "3. To describe future plans or arrangements.\n"
      "   Example: We are meeting them tomorrow.\n"
      "\nForm:\n"
      "- Affirmative: Subject + am/is/are + verb-ing\n"
      "  Example: I am working. / He is watching TV. / They are studying.\n"
      "- Negative: Subject + am/is/are + not + verb-ing\n"
      "  Example: She is not sleeping. / We are not going out.\n"
      "- Interrogative: Am/Is/Are + subject + verb-ing?\n"
      "  Example: Are you listening? / Is he coming?\n"
      "\nTime Expressions:\n"
      "- now, right now, at the moment, currently, today, this week";

  string theoryPresentPerfect =
      "Tense: Present Perfect\n\n"
      "Usage:\n"
      "1. To express actions that happened at an unspecified time in the "
      "past.\n"
      "   Example: I have seen that movie.\n"
      "2. To describe actions that started in the past and continue to the "
      "present.\n"
      "   Example: She has lived here for five years.\n"
      "\nForm:\n"
      "- Affirmative: Subject + has/have + past participle\n"
      "  Example: He has finished his homework.\n"
      "- Negative: Subject + has/have + not + past participle\n"
      "  Example: They have not arrived yet.\n"
      "- Interrogative: Has/Have + subject + past participle?\n"
      "  Example: Have you eaten yet?\n"
      "\nTime Expressions:\n"
      "- just, already, yet, ever, never, since, for";

  string theoryPresentPerfectContinuous =
      "Tense: Present Perfect Continuous\n\n"
      "Usage:\n"
      "1. To describe actions that began in the past and are still "
      "continuing.\n"
      "   Example: I have been reading for two hours.\n"
      "2. To express the duration of an action.\n"
      "   Example: She has been working all day.\n"
      "\nForm:\n"
      "- Affirmative: Subject + has/have + been + verb-ing\n"
      "  Example: We have been waiting for an hour.\n"
      "- Negative: Subject + has/have + not + been + verb-ing\n"
      "  Example: He has not been studying.\n"
      "- Interrogative: Has/Have + subject + been + verb-ing?\n"
      "  Example: Has she been working?\n"
      "\nTime Expressions:\n"
      "- since, for, how long";

  string theoryPastSimple = "Tense: Past Simple\n\n"
                            "Usage:\n"
                            "1. To describe completed actions in the past.\n"
                            "   Example: He visited Paris last year.\n"
                            "\nForm:\n"
                            "- Affirmative: Subject + past form of the verb\n"
                            "  Example: She played tennis yesterday.\n"
                            "- Negative: Subject + did not + base verb\n"
                            "  Example: They did not go to the party.\n"
                            "- Interrogative: Did + subject + base verb?\n"
                            "  Example: Did you see that movie?\n"
                            "\nTime Expressions:\n"
                            "- yesterday, last week, in 2000, two days ago";

  string theoryPastContinuous =
      "Tense: Past Continuous\n\n"
      "Usage:\n"
      "1. To describe actions happening at a specific time in the past.\n"
      "   Example: He was reading at 8 p.m. yesterday.\n"
      "2. To describe two actions happening at the same time in the past.\n"
      "   Example: I was cooking while she was studying.\n"
      "\nForm:\n"
      "- Affirmative: Subject + was/were + verb-ing\n"
      "  Example: They were playing football.\n"
      "- Negative: Subject + was/were + not + verb-ing\n"
      "  Example: She was not watching TV.\n"
      "- Interrogative: Was/Were + subject + verb-ing?\n"
      "  Example: Were you sleeping?\n"
      "\nTime Expressions:\n"
      "- while, when";

  string theoryPastPerfect =
      "Tense: Past Perfect\n\n"
      "Usage:\n"
      "1. To describe an action completed before another past action.\n"
      "   Example: He had finished his homework before the movie started.\n"
      "\nForm:\n"
      "- Affirmative: Subject + had + past participle\n"
      "  Example: They had eaten before I arrived.\n"
      "- Negative: Subject + had + not + past participle\n"
      "  Example: I had not seen that movie.\n"
      "- Interrogative: Had + subject + past participle?\n"
      "  Example: Had you met her before?\n"
      "\nTime Expressions:\n"
      "- before, after, by the time";

  string theoryPastPerfectContinuous =
      "Tense: Past Perfect Continuous\n\n"
      "Usage:\n"
      "1. To describe an action that was happening before another past "
      "action.\n"
      "   Example: She had been studying for two hours before the exam.\n"
      "2. To express the duration of an action before a past moment.\n"
      "   Example: He had been working all day";

  // Завдання та відповіді
  vector<string> tasksPresentSimple = {"1. She ___ to school every day. (go)",
                                       "2. They ___ breakfast at 7 a.m. (have)",
                                       "3. I ___ like coffee. (not like)"};
  vector<string> answersPresentSimple = {"goes", "have", "do not like"};

  vector<string> tasksPresentContinuous = {
      "1. I ___ a book right now. (read)",
      "2. They ___ to the park at the moment. (go)",
      "3. We ___ dinner at 8 p.m. (have)"};
  vector<string> answersPresentContinuous = {"am reading", "are going",
                                             "are having"};

  vector<string> tasksPresentPerfect = {
      "1. She ___ that movie. (see)", "2. I ___ my homework yet. (not finish)",
      "3. We ___ to Paris. (be)"};
  vector<string> answersPresentPerfect = {"has seen", "have not finished",
                                          "have been"};

  vector<string> tasksPresentPerfectContinuous = {
      "1. He ___ for an hour. (study)", "2. They ___ for two hours. (wait)",
      "3. I ___ for my keys. (look)"};
  vector<string> answersPresentPerfectContinuous = {
      "has been studying", "have been waiting", "have been looking"};

  vector<string> tasksPastSimple = {
      "1. I ___ to the store yesterday. (go)",
      "2. She ___ a book last week. (read)",
      "3. They ___ to the concert last night. (not go)"};
  vector<string> answersPastSimple = {"went", "read", "did not go"};

  vector<string> tasksPastContinuous = {
      "1. I ___ dinner when the phone rang. (have)",
      "2. They ___ a movie at 8 p.m. last night. (watch)",
      "3. We ___ to the park when it started raining. (walk)"};
  vector<string> answersPastContinuous = {"was having", "were watching",
                                          "were walking"};

  vector<string> tasksPastPerfect = {
      "1. By the time I arrived, they ___ the meeting. (finish)",
      "2. She ___ her homework before dinner. (do)",
      "3. They ___ to the concert before I called them. (go)"};
  vector<string> answersPastPerfect = {"had finished", "had done", "had gone"};

  vector<string> tasksPastPerfectContinuous = {
      "1. They ___ for two hours before the meeting started. (wait)",
      "2. I ___ for an hour when my friend called. (run)",
      "3. He ___ all day when the rain started. (work)"};
  vector<string> answersPastPerfectContinuous = {
      "had been waiting", "had been running", "had been working"};

  // Створення уроків
  vector<Lesson> lessons = {
      Lesson("Present Simple", theoryPresentSimple, tasksPresentSimple,
             answersPresentSimple, 15),
      Lesson("Present Continuous", theoryPresentContinuous,
             tasksPresentContinuous, answersPresentContinuous, 15),
      Lesson("Present Perfect", theoryPresentPerfect, tasksPresentPerfect,
             answersPresentPerfect, 15),
      Lesson("Present Perfect Continuous", theoryPresentPerfectContinuous,
             tasksPresentPerfectContinuous, answersPresentPerfectContinuous,
             15),
      Lesson("Past Simple", theoryPastSimple, tasksPastSimple,
             answersPastSimple, 15),
      Lesson("Past Continuous", theoryPastContinuous, tasksPastContinuous,
             answersPastContinuous, 15),
      Lesson("Past Perfect", theoryPastPerfect, tasksPastPerfect,
             answersPastPerfect, 15),
      Lesson("Past Perfect Continuous", theoryPastPerfectContinuous,
             tasksPastPerfectContinuous, answersPastPerfectContinuous, 15)};

  // Навчальний цикл
  for (auto &lesson : lessons) {
    cout << "\n\033[1;34m=== Початок уроку: " << lesson.getTitle()
         << " ===\033[0m\n";

    lesson.conduct();
    lesson.displayResults();
    lesson.displayFeedback();

    user.updateProgress(lesson.getTitle(), lesson.getSuccessPercentage());
    user.addPoints(lesson.getPointsReward());

    lesson.saveProgress("lessons_progress.txt");
    user.saveToFile("user_progress.txt");

    cout << "\n\033[1;35m----------------------------------------\033[0m\n";
  }

  // Фінальний звіт
  cout << "\n\033[1;32m=== Навчання завершено! ===\033[0m\n";
  cout << "Усього уроків: " << lessons.size() << endl;
  cout << "Зароблено балів: " << user.getPoints() << endl;
  cout << "Загальний прогрес:\n";
  user.displayProgress();

  return 0;
}