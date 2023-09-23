#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Quiz.h"
#include "Question.h"

using namespace std;

enum class Type
{
  truefalse = 1, // true - false
  multi,         // A - B - C
  open           // search in the input string if it includes a specific word
};

int main()
{
  Quiz quiz;

  Question q1("This is a question 1", {"True", "False"}, 0, 1);
  Question q2("This is a question 2", {"True", "False"}, 0, 1);
  Question q3("This is a question 3", {"True", "False"}, 0, 1);
  Question q4("This is a question 4", {"True", "False"}, 0, 1);
  Question q5("This is a question 5", {"True", "False"}, 0, 1);

  quiz.CreateQuestions({q1, q2, q3, q4, q5});
  quiz.ShuffleQuestions();

  std::cout << "--------------------------\n";
  std::cout << "Welcome to the Quiz!\n";
  std::cout << "--------------------------\n\n";

  quiz.AskQuestions();

  std::cout << "\n--------------------------\n";
  std::cout << "Great Job! Your score is " << quiz.score << "\n";
  std::cout << "--------------------------\n\n";

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