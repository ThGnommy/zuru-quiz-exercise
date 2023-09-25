#pragma once

#include <variant>
#include "Question.h"
class Quiz
{
public:
  Quiz() = default;
  Quiz(const Quiz &other) = delete;
  Quiz &operator=(const Quiz &other) = delete;
  ~Quiz();

  vector<IQuestion *> *questions = new vector<IQuestion *>;

  int score = 0;

  void ShuffleQuestions();
  void CreateQuestionList(std::vector<IQuestion *> questions);
  void AskQuestions();

  // utility
  int GetQuestionListSize();
};