#pragma once

#include <iostream>
#include <string>
using std::string;
#include <array>
using std::array;

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
  virtual void GetAnswers() = 0;

  string m_question_text;

  Type type = Type::uknown;
};

class QuestionTrueFalse : public IQuestion
{

public:
  QuestionTrueFalse(string question_text, int correct_answer)
      : m_correct_answer(correct_answer)
  {
    type = Type::truefalse;
    this->m_question_text = question_text;
  }

  void GetAnswers() override;

  array<string, 2> m_answers = {"A. True", "B. False"};
  int m_correct_answer;
};

class QuestionMulti : public IQuestion
{

public:
  QuestionMulti(string question_text, array<string, 4> answers, array<int, 2> correct_answers)
      : m_answers(answers),
        m_correct_answers(correct_answers)
  {
    type = Type::multi;
    this->m_question_text = question_text;
  }

  void ShuffleAnswers();
  void GetAnswers() override;

  array<string, 4> m_answers;
  array<int, 2> m_correct_answers;
};

class QuestionOpen : public IQuestion
{
public:
  QuestionOpen(string question_text, string answer)
      : question_text(question_text),
        answer(answer)
  {
    type = Type::open;
    this->m_question_text = question_text;
  }

  string question_text;
  string answer;
};