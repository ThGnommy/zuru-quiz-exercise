#include "Quiz.h"
#include "Question.h"

int main()
{
  bool start_quiz = true;

  QuestionTrueFalse q1("Cats have four legs, and one tail?", 0);
  QuestionTrueFalse q2("Elephant can Meow?", 1);
  QuestionMulti q3("Question multi?", {"Answ 1", "Answ 2", "Answ 3", "Answ 4"}, {0, 1});

  Quiz quiz;

  quiz.CreateQuestionList({&q1, &q2, &q3});

  while (start_quiz)
  {
    quiz.ShuffleQuestions();

    std::cout << "--------------------------\n";
    std::cout << "Welcome to the Quiz!\n";
    std::cout << "--------------------------\n\n";

    quiz.AskQuestions();

    std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "\n>>>>>>>>> Great Job! You answered " << quiz.GetScore() << " out of " << quiz.GetQuestionListSize() << " questions correctly! <<<<<<<<< \n\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

    char choice;

    std::cout << "Do you want to retry?\n";
    std::cout << "Insert 'y' to retry or another key to exit: ";
    std::cin >> choice;

    if (choice != 'y')
      start_quiz = false;
  }

  return 0;
}