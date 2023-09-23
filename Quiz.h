#pragma once

#include "Question.h"
#include <vector>
using std::vector;

class Quiz
{
public:
  Quiz() = default;
  Quiz &operator=(const Quiz &other) = delete;

  vector<Question> *questions = new vector<Question>;

  int score = 0;

  void ShuffleQuestions();
  void CreateQuestions(std::vector<Question> questions);
  void AskQuestions();
  ~Quiz();
};