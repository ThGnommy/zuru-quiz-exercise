#pragma once

#include <vector>
using std::vector;
#include "Question.h"

class Quiz
{
public:
  bool edit_mode = false;
  vector<Question> questions;
  void CreateQuestions();
};