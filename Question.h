#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;

class Question
{
  enum class Type
  {
    truefalse = 1, // true - false
    multi,         // A - B - C
    open           // search in the input string if it includes a specific word
  };

public:
  Question(string question_text, vector<string> answers, int correct_answer, int type)
      : question_text(question_text),
        answers(answers),
        correct_answer(correct_answer),
        type(type)
  {
  }

  string question_text;
  vector<string> answers;
  int correct_answer;
  int type;
};