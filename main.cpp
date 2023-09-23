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

  std::cout << "--------------------------\n";
  std::cout << "Welcome to the Quiz!\n";
  std::cout << "--------------------------\n\n";
  std::cout << "Press 1 if you want to start the Quiz, or press 2 to enter the Edit mode.\n";

  char choose;

  std::cin >> choose;

  if (choose == '1')
    // quiz.startQuiz();

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