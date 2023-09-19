#include <iostream>
#include <fstream>
#include "Quiz.h"

void Quiz::CreateQuestions()
{
  std::fstream question_file;

  question_file.open("questions.txt", std::ios::in);

  if (question_file.is_open())
  {
    string line;
    while (getline(question_file, line))
    {
      Question current_question;

      bool is_question_text = line[0] == 'Q';

      // get the question text
      if (is_question_text)
      {
        current_question.question_text = line.substr(3, line.size());
        this->questions.push_back(current_question);
      }

      // get the question type
      // get the answers
    }
  }
}