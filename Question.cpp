#include "Question.h"
#include "Quiz.h"
#include <sstream>
using std::string;
using std::vector;

namespace
{
  string GetSubString(const string &str, const char &ch)
  {
    string substring = "";

    size_t end_pos = str.find(ch);

    if (end_pos != std::string::npos)
    {
      substring = str.substr(0, end_pos);
    }
    return substring;
  }

  void SplitAndPush(string &str, char delimiter, vector<string> &v)
  {
    if (str.empty())
      return;

    std::stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
    {
      v.push_back(token);
    }
  }
}

void IQuestion::PrintQuestionText() const
{
  std::cout << m_question_text << "\n";
}

void IQuestion::PrintAnswers() const
{
  for (string answer : m_answers)
  {
    std::cout << answer << "\n";
  }
}

void IQuestion::ParseQuestion(string &line)
{
  // get the question text
  string question_start = line.substr(2);
  m_question_text = GetSubString(question_start, '|');

  // get the answers
  size_t answers_start_pos = line.find("|");
  string answers = line.substr(answers_start_pos + 1);

  m_correct_answers.push_back(answers);
}

void IQuestion::GivePoints(string &user_choice)
{

  Quiz quiz;
  auto answer_finded = find(m_correct_answers.begin(), m_correct_answers.end(), user_choice);

  if (answer_finded != m_correct_answers.end())
  {
    quiz.UpdateScore();
  }
}

void QuestionTrueFalse::PrintHint() const
{
  std::cout << "(Insert True or False)\n\n";
}

void QuestionMulti::ParseQuestion(string &line)
{
  // get the question text
  string question_start = line.substr(2);
  string question_text = GetSubString(question_start, '|');
  m_question_text = question_text;

  // get the answers
  size_t answers_start_pos = line.find("|");
  string answers = line.substr(answers_start_pos + 1);

  string answers_list = GetSubString(answers, '$');
  SplitAndPush(answers_list, '_', m_answers);

  string correct_answers = answers.substr(answers.find('$') + 1);

  for (char &answer : correct_answers)
  {
    string s(1, answer);
    m_correct_answers.push_back(s);
  }
}

void QuestionMulti::PrintHint() const
{
  std::cout << "(Insert A, B, C, or D. There can be multiple correct answers)\n\n";
}

void QuestionMulti::GivePoints(string &user_choice)
{

  Quiz quiz;

  for (char answer : user_choice)
  {

    string s = string(1, answer);
    auto answer_finded = find(m_correct_answers.begin(), m_correct_answers.end(), s);

    if (answer_finded != m_correct_answers.end())
    {
      quiz.UpdateScore();
    }
  }
}

void QuestionOpen::PrintHint() const
{
  std::cout << "(Insert the correct answer)\n\n";
}
