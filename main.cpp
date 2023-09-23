#include <iostream>
#include <string>
#include <vector>
#include "Quiz.h"
#include "Question.h"

using namespace std;

int main()
{
  Quiz quiz;

  bool start_quiz = true;

  Question q1("Cats have five legs.", {"True", "False"}, 0, 1);
  Question q2("This is a question 2", {"True", "False"}, 0, 1);
  Question q3("This is a question 3", {"True", "False"}, 0, 1);
  Question q4("This is a question 4", {"True", "False"}, 0, 1);
  Question q5("This is a question 5", {"True", "False"}, 0, 1);

  quiz.CreateQuestionList({q1, q2, q3, q4, q5});

  while (start_quiz)
  {
    quiz.ShuffleQuestions();

    std::cout << "--------------------------\n";
    std::cout << "Welcome to the Quiz!\n";
    std::cout << "--------------------------\n\n";

    quiz.AskQuestions();

    std::cout << "\n--------------------------\n";
    std::cout << "Great Job! You answered " << quiz.score << " out of " << quiz.GetQuestionListSize() << " questions correctly!\n";
    std::cout << "--------------------------\n\n";

    char choice;

    std::cout << "Do you want to retry?\n";
    std::cout << "Insert 'y' to retry or another key to exit: ";
    std::cin >> choice;

    if (choice != 'y')
      start_quiz = false;
  }

  return 0;
}