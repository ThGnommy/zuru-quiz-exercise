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

      // Find the question text
      int end_of_question = line.find('?');
      current_question.question_text = line.substr(1, end_of_question);

      // Find the question type
      current_question.type = (int)line[0] - '0';

      int right_answer;

      switch (current_question.type)
      {
      case 1: // true false
      {

        current_question.answers.push_back("True");
        current_question.answers.push_back("False");

        right_answer = line[line.size() - 1];
        current_question.correct_answer = (int)right_answer - '0';

        break;
      }
      case 2:

        break;
      case 3:
        break;

      default:
        break;
      }

      this->questions->push_back(current_question);
    }
  }
}

Quiz::~Quiz()
{
  delete questions;
  questions = nullptr;
}