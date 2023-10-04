#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class QuestionType
{
  truefalse = 1, // true - false
  multi,         // A - B - C
  open,          // search in the input std::string if it includes a specific word
};

class IQuestion

{
public:
  IQuestion() = default;
  virtual ~IQuestion() = default;
  IQuestion(const IQuestion &other) = delete;
  IQuestion &operator=(const IQuestion &other) = delete;

  void PrintAnswers() const;
  void PrintQuestionText() const;
  virtual void PrintHint() const = 0;
  virtual void GivePoints(std::string &user_choice);

  virtual void ParseQuestion(std::string &line);

  std::string m_question_text;
  std::vector<std::string> m_answers;
  std::vector<std::string> m_correct_answers;

  QuestionType type = QuestionType::truefalse;
};

class QuestionTrueFalse : public IQuestion
{

public:
  QuestionTrueFalse()
  {
    type = QuestionType::truefalse;
  }

  void PrintHint() const override;
};

class QuestionMulti : public IQuestion
{

public:
  QuestionMulti()
  {
    type = QuestionType::multi;
  }

  void ParseQuestion(std::string &line) override;
  void PrintHint() const override;
  void GivePoints(std::string &user_choice) override;
};

class QuestionOpen : public IQuestion
{

public:
  QuestionOpen()
  {
    type = QuestionType::open;
  }
  void PrintHint() const override;
};

class QuestionFactory
{
public:
  IQuestion *build(QuestionType &type)
  {
    switch (type)
    {
    case QuestionType::truefalse:
      return new QuestionTrueFalse();
    case QuestionType::multi:
      return new QuestionMulti();
    case QuestionType::open:
      return new QuestionOpen();
    default:
      return nullptr;
    }
  }
};
