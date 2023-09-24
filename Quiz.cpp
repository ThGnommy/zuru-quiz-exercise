#include <iostream>
#include <algorithm>
using std::shuffle;
#include <random>
#include "Quiz.h"

void Quiz::CreateQuestionList(std::vector<Question> questions)
{
  this->questions->insert(this->questions->end(), questions.begin(), questions.end());
}

void Quiz::ShuffleQuestions()
{
  shuffle(this->questions->begin(), this->questions->end(), std::random_device());
}

int Quiz::GetQuestionListSize()
{
  vector<Question> question_list = *(this->questions);
  return question_list.size();
}

void Quiz::AskQuestions()
{
  vector<Question> question_list = *(this->questions);
  for (int i = 0; i < question_list.size(); ++i)
  {
    int user_choice;

    std::cout << "Question " << i + 1 << ".\n";
    std::cout << "------------\n";
    std::cout << question_list[i].question_text << "\n";
    std::cout << "(Insert 0 for True, or 1 for False)\n\n";

    for (auto answer : question_list[i].answers)
    {
      std::cout << answer << "\n";
    }

    std::cout << "Your choice: ";
    std::cin >> user_choice;
    std::cout << "\n\n";
    if (user_choice == question_list[i].correct_answer)
    {
      this->score += 1;
    }
  }
}

Quiz::~Quiz()
{
  delete questions;
  questions = nullptr;
}