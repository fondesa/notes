#pragma once

#include <optional>
#include "draft.hpp"

class NotesInteractor {
 public:
  virtual ~NotesInteractor() = default;

  virtual std::optional<Draft> getDraft() = 0;
};