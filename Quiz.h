#pragma once

#include "Question.h"
#include <vector>
using std::vector;

class Quiz
{
public:
  Quiz() = default;
  Quiz &operator=(const Quiz &other) = delete;

  bool edit_mode = false;
  vector<Question> *questions = new vector<Question>;

  int score = 0;
  void CreateQuestions();
  // void AskQuestion();
  ~Quiz();
};