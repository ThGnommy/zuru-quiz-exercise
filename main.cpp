#include "Quiz.h"
#include "Question.h"

int main(int argc, char *argv[])
{
  Quiz quiz;

  if (strcmp(argv[1], "edit") == 0)
  {
    quiz.EditMode();
    return 0;
  }

  bool start_quiz = true;

  quiz.CreateQuestionList();

  while (start_quiz)
  {
    quiz.ShuffleQuestions();

    std::cout << "--------------------------\n";
    std::cout << "Welcome to the Quiz!\n";
    std::cout << "--------------------------\n\n";

    quiz.AskQuestions();

    std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "\n>>>>>>>>> Great Job! You have a score of " << quiz.GetScore() << " points! <<<<<<<<< \n\n";
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