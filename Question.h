#pragma once

#include <vector>
using std::vector;
#include <string>
using std::string;

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
  string question_text;

  Type type = Type::uknown;
};

class QuestionTrueFalse : public IQuestion
{

public:
  QuestionTrueFalse(string question_text, int correct_answer)
      : correct_answer(correct_answer)
  {
    type = Type::truefalse;
    this->question_text = question_text;
  }

  void GetAnswers() override
  {
    for (auto answer : answers)
    {
      std::cout << answer << "\n";
    }
  };

  string answers[2] = {"True", "False"};
  int correct_answer;
};

class QuestionMulti : public IQuestion
{

public:
  QuestionMulti(string question_text, vector<string> answers, int correct_answer)
      : question_text(question_text),
        answers{},
        correct_answer{}
  {
  }

  // ShuffleQuestion();

  string question_text;
  vector<string> answers[4];
  int correct_answer[2];
};

class QuestionOpen : public IQuestion
{
public:
  QuestionOpen(string question_text, string answer)
      : question_text(question_text),
        answer(answer)
  {
  }

  string question_text;
  string answer;
  int type = 3;
};