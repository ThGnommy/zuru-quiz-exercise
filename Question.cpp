#include "Question.h"
#include <algorithm>
using std::shuffle;
#include <random>

string IQuestion::GetQuestionText()
{
  return m_question_text;
}

void QuestionTrueFalse::GetAnswers()
{
  for (int i = 0; i < m_answers.size(); ++i)
  {
    std::cout << m_answers[i] << "\n";
  }
}

void QuestionMulti::GetAnswers()
{

  ShuffleAnswers();
  for (int i = 0; i < m_answers.size(); ++i)
  {
    std::cout << m_answers[i] << "\n";
  }
}

void QuestionMulti::ShuffleAnswers()
{
  shuffle(m_answers.begin(), m_answers.end(), std::random_device());
}