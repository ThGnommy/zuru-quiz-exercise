#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;

class Question
{

public:
  Question(string question_text, vector<string> answers, int correct_answer, int type)
      : question_text(question_text), answers(answers), correct_answer(correct_answer), type(type)
  {
  }

  string question_text;
  vector<string> answers;
  int correct_answer;
  int type;
};