#include "Quiz.h"
#include "Question.h"

int main()
{
  bool start_quiz = true;

  QuestionTrueFalse q1("Cats have four legs, and one tail?", {"B"});
  QuestionTrueFalse q2("Elephant can Meow?", {"A"});
  QuestionMulti q3("Question multi?", {"A. Answ 1", "B. Answ 2", "C. Answ 3", "D. Answ 4"}, {"A", "D"});
  QuestionOpen q4("What is the capital of France?", {"Paris"});
  Quiz quiz;

  quiz.CreateQuestionList({&q1, &q2, &q3, &q4});

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
    {
      start_quiz = false;
    }
    else if (choice == 'y')
    {
      quiz.ResetScore();
    }
  }

  return 0;
}