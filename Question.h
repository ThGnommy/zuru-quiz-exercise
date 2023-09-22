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
  int type;
  string question_text;
  vector<string> answers;
  int correct_answer;
};