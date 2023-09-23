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
  for (auto question : question_list)
  {
    int user_choice;

    std::cout << question.question_text << "\n";

    for (auto answer : question.answers)
    {
      std::cout << answer << "\n";
    }

    std::cout << "Your choice: ";
    std::cin >> user_choice;

    if (user_choice == question.correct_answer)
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