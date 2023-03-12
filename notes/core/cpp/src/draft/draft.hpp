#pragma once

#include <string>

class Draft {
 public:
  Draft(std::string title, std::string description);

  [[nodiscard]] std::string getTitle() const;

  [[nodiscard]] std::string getDescription() const;

 private:
  std::string title;
  std::string description;
};