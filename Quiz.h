#pragma once

#include <vector>
using std::vector;
#include "Question.h"

class Quiz
{
public:
  Quiz() = default;
  Quiz(const Quiz &other) = delete;
  Quiz &operator=(const Quiz &other) = delete;
  ~Quiz();

  vector<IQuestion *> *questions = new vector<IQuestion *>;

  void ShuffleQuestions();
  void CreateQuestionList(std::vector<IQuestion *> questions);
  void AskQuestions();
  void UpdateScore();

  // utility
  int GetQuestionListSize();
  int GetScore();

private:
  int score{0};
};