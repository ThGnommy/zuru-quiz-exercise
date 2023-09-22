#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Quiz.h"
#include "Question.h"

using namespace std;

int main()
{
  Quiz quiz;

  quiz.CreateQuestions();

  vector<Question> question_list = *(quiz.questions);

  std::cout << question_list[0].question_text << std::endl;
  std::cout << question_list[0].answers.size() << std::endl;

  // for (auto q : question_list)
  // {
  //   std::cout << q.question_text << " " << q.type << std::endl;
  //   for (auto a : q.answers)
  //   {
  //     std::cout << a << std::endl;
  //   }
  // }

  return 0;
}

/*

Flow Quiz
Welcome to the quiz!
Press 1 to start the quiz or 2 to edit the questions

press 1 (start the quiz)
if there are 0 questions, return an error and exit.
shuffle() all the questions
in a while loop show the questions
when finish display the score, then ask the user if he/she want retry or exit the program.

*/