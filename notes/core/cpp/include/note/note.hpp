#pragma once

#include <string>

class Note {
 public:
  Note(int id, std::string title, std::string description);

  [[nodiscard]] int getId() const;
  [[nodiscard]] std::string getTitle() const;
  [[nodiscard]] std::string getDescription() const;

 private:
  int id;
  std::string title;
  std::string description;
};