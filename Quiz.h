#pragma once

#include <vector>
#include "Question.h"

class Quiz
{
public:
  Quiz() = default;
  Quiz(const Quiz &other) = delete;
  Quiz &operator=(const Quiz &other) = delete;
  ~Quiz();

  std::vector<IQuestion *> questions;

  void ShuffleQuestions();
  void CreateQuestionList();
  void AskQuestions();
  void UpdateScore();
  void EditMode();

  // utility

  int GetScore() const;
  void ResetScore();

  inline static int score = 0;
};