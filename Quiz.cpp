#include <iostream>
#include <algorithm>
using std::shuffle;
#include <random>
#include "Quiz.h"

void Quiz::CreateQuestionList(std::vector<IQuestion *> questions)
{
  this->questions->insert(this->questions->end(), questions.begin(), questions.end());
}

void Quiz::ShuffleQuestions()
{
  shuffle(questions->begin(), questions->end(), std::random_device());
}

void Quiz::UpdateScore()
{
  score += 1;
}

int Quiz::GetQuestionListSize()
{
  return questions->size();
}

int Quiz::GetScore()
{
  return score;
}

void Quiz::AskQuestions()
{
  vector<IQuestion *> &question_list = *(this->questions);
  for (int i = 0; i < question_list.size(); ++i)
  {
    int user_choice;

    std::cout << "Question " << i + 1 << ".\n";
    std::cout << "------------\n";
    std::cout << question_list[i]->GetQuestionText() << "\n";
    std::cout << "(Insert 0 for True, or 1 for False)\n\n";
    question_list[i]->GetAnswers();

    std::cout << "Your choice: ";
    std::cin >> user_choice;
    std::cout << "\n\n";

    if (user_choice == question_list[i]->m_correct_answers)
    {
      UpdateScore();
    }
  }
}

Quiz::~Quiz()
{
  delete questions;
  questions = nullptr;
}