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
      bool is_question_text = line[0] == 'Q';
      bool is_answer = line[0] == '[';

      // get the question text and the answer number
      if (is_question_text)
      {
        Question current_question;

        current_question.type = (int)line[1] - '0';

        current_question.question_text = line.substr(2, line.size());

        this->questions->push_back(current_question);

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
      }

      else if (is_answer)
      {
        string answer = line.substr(1, line.size() - 2);
        Question current_question = this->questions->back();
        current_question.answers.push_back(answer);
      }
    }
  }
}

Quiz::~Quiz()
{
  delete questions;
  questions = nullptr;
}