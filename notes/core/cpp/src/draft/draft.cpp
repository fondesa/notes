#include "draft/draft.hpp"
#include <utility>

Draft::Draft(std::string title, std::string description) {
  this->title = std::move(title);
  this->description = std::move(description);
}

std::string Draft::getTitle() const {
  return title;
}

std::string Draft::getDescription() const {
  return description;
}
