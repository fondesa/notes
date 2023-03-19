#pragma once

#include <optional>
#include "draft/draft.hpp"

class DraftsDao {
 public:
  virtual void createSchema() = 0;

  virtual std::optional<Draft> get() = 0;

  virtual void upsert(Draft draft) = 0;

  virtual void clear() = 0;
};