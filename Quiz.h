#pragma once

#include "Question.h"

class Quiz
{
public:
  Quiz() = default;
  Quiz &operator=(const Quiz &other) = delete;

  vector<Question> *questions = new vector<Question>;

  int score = 0;

  void ShuffleQuestions();
  void CreateQuestionList(std::vector<Question> questions);
  void AskQuestions();

  // utility
  int GetQuestionListSize();

  ~Quiz();
};