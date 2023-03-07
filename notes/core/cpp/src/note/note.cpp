#include "note/note.hpp"
#include <utility>

Note::Note(int id, std::string title, std::string description, std::time_t lastUpdateTime) {
  this->id = id;
  this->title = std::move(title);
  this->description = std::move(description);
  this->lastUpdateTime = lastUpdateTime;
}

int Note::getId() const {
  return id;
}

std::string Note::getTitle() const {
  return title;
}

std::string Note::getDescription() const {
  return description;
}

std::time_t Note::getLastUpdateTime() const {
  return lastUpdateTime;
}
