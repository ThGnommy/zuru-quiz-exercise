#include "Quiz.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <fstream>
using std::fstream;
using std::shuffle;
using std::string;
using std::vector;

namespace
{
  string ToUpperCase(string &str)
  {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
  }

  void ClearScreen()
  {
    printf("\33c\e[3J");
  }

  // edit mode
  string AddNewQuestion(string &title, string &answer)
  {
  }

}

void Quiz::CreateQuestionList()
{
  fstream question_file;
  question_file.open("questions.txt", std::ios::in);

  string line;

  QuestionFactory factory;

  while (getline(question_file, line))
  {
    int question_line_type = atoi(line.c_str());
    QuestionType qt = static_cast<QuestionType>(question_line_type);

    IQuestion *new_question = factory.build(qt);
    if (new_question != nullptr)
    {
      new_question->ParseQuestion(line);
      questions.push_back(new_question);
    }
  }
}

void Quiz::ShuffleQuestions()
{
  shuffle(questions.begin(), questions.end(), std::random_device());
}

void Quiz::UpdateScore()
{
  score += 1;
}

int Quiz::GetScore() const
{

  return score;
}

void Quiz::ResetScore()
{
  score = 0;
}

void Quiz::AskQuestions()
{
  for (int i = 0; i < questions.size(); ++i)
  {
    string user_choice;

    std::cout << "Question " << i + 1 << ".\n";
    std::cout << "------------\n";

    questions[i]->PrintQuestionText();
    questions[i]->PrintHint();
    questions[i]->PrintAnswers();

    std::cout << "Your choice: ";
    std::cin >> user_choice;

    std::cout << "\n\n";

    string choice_uppercase = ToUpperCase(user_choice);

    questions[i]->GivePoints(choice_uppercase);
  }
}

void Quiz::EditMode()
{
  std::cout << "- Edit Mode - "
            << "\n";
  std::cout << "1 - Add a new question"
            << "\n";
  std::cout << "2 - Delete a question"
            << "\n";

  string choice;

  std::cout << "Choice: ";
  std::cin >> choice;

  ClearScreen();

  bool add_question = atoi(choice.c_str()) == 1;

  if (add_question)
  {
    string question_type;
    string question_text;
    string answer;

    vector<string> answers_list;
    vector<string> correct_answers;

    std::cout << "\nChoose a question type: "
              << "\n";
    std::cout << "1 - Question True False"
              << "\n";
    std::cout << "2 - Question Multi"
              << "\n";
    std::cout << "3 - Question Open"
              << "\n\n";

    std::cout << "Choose the question type: ";

    std::cin >> question_type;

    int selected_type = atoi(question_type.c_str());

    fstream question_file;
    question_file.open("questions.txt", std::ios::app);

    switch (selected_type)
    {
    case 1:

      std::cout << "Insert the question text: ";
      std::cin >> question_text;

      std::cout << "Insert the correct answer: ";
      std::cin >> answer;

      question_file << '\n'
                    << question_text + answer;

      break;

    case 2:

      break;

    case 3:

      break;

    default:
      break;
    }
  }
}

Quiz::~Quiz()
{
  for (IQuestion *question : questions)
  {
    delete question;
  }
}