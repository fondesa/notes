#pragma once

#include <optional>
#include "draft.hpp"

class NotesInteractor {
 public:
  virtual std::optional<Draft> getDraft() = 0;
};