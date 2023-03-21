#pragma once

#include <ctime>
#include <string>

class Note {
 public:
  Note(int id, std::string title, std::string description, std::time_t lastUpdateTime);

  [[nodiscard]] int getId() const;
  [[nodiscard]] std::string getTitle() const;
  [[nodiscard]] std::string getDescription() const;
  [[nodiscard]] std::time_t getLastUpdateTime() const;

 private:
  int id;
  std::string title;
  std::string description;
  std::time_t lastUpdateTime;
};