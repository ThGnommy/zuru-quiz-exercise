#include <iostream>
#include <fstream>
#include "Quiz.h"

void Quiz::CreateQuestions()
{
  std::fstream question_file;

  int line_count = 0;

  question_file.open("questions.txt", std::ios::in);

  if (question_file.is_open())
  {
    string line;
    while (getline(question_file, line))
    {
      Question current_question;

      current_question.type = (int)line[0] - '0';

      // Find the question text

      int end_of_question = line.find('?');
      current_question.question_text = line.substr(1, end_of_question);

      char right_answer;

      // get the question type
      // switch (current_question.type)
      // {
      // case '1':
      //   break;
      // case '2':
      //   break;
      // case '3':
      //   break;

      // default:
      //   break;
      // }

      this->questions->push_back(current_question);
    }
  }
}

Quiz::~Quiz()
{
  delete questions;
  questions = nullptr;
}