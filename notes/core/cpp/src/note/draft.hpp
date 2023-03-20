#pragma once

#include <string>

class Draft {
 public:
  Draft();
  Draft(std::string title, std::string description);

  [[nodiscard]] std::string getTitle() const;

  [[nodiscard]] std::string getDescription() const;

  void setTitle(std::string newTitle);

  void setDescription(std::string newDescription);

 private:
  std::string title;
  std::string description;
};