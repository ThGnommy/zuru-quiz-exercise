#include "Question.h"

string IQuestion::GetQuestionText()
{
  return m_question_text;
}

void IQuestion::PrintAnswers()
{
  for (int i = 0; i < m_answers.size(); ++i)
  {
    std::cout << m_answers[i] << "\n";
  }
}