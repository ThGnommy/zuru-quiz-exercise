#pragma once

#include <iostream>
#include <string>
using std::string;
#include <array>
using std::array;
#include <vector>
using std::vector;

class IQuestion
{
public:
  enum class Type
  {
    truefalse = 1, // true - false
    multi,         // A - B - C
    open,          // search in the input string if it includes a specific word
    uknown
  };

  string GetQuestionText();
  void PrintAnswers();

  string m_question_text;
  vector<string> m_answers;
  vector<string> m_correct_answers;

  Type type = Type::uknown;
};

class QuestionTrueFalse : public IQuestion
{

public:
  QuestionTrueFalse(string question_text, vector<string> correct_answers)
  {
    type = Type::truefalse;
    this->m_question_text = question_text;
    this->m_correct_answers = correct_answers;
  }

  vector<string> m_answers = {"A. True", "B. False"};
};

class QuestionMulti : public IQuestion
{

public:
  QuestionMulti(string question_text, vector<string> answers, vector<string> correct_answers)
  {
    type = Type::multi;
    this->m_question_text = question_text;
    this->m_answers = answers;
    this->m_correct_answers = correct_answers;
  }
};

class QuestionOpen : public IQuestion
{
public:
  QuestionOpen(string question_text, vector<string> correct_answers)
  {
    type = Type::open;
    this->m_question_text = question_text;
    this->m_correct_answers = correct_answers;
  }
};