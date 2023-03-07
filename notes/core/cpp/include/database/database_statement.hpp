#pragma once

#include <memory>
#include <optional>
#include <string>
#include "database_cursor.hpp"

namespace Db {

class Statement {
 public:
  template <typename T>
  void bind(int colIndex, T value);

  template <typename T>
  T execute();

 protected:
  virtual void executeVoid() = 0;

  virtual std::optional<int> executeOptionalInt() = 0;

  virtual int executeInt() = 0;

  virtual std::optional<std::string> executeOptionalString() = 0;

  virtual std::shared_ptr<Cursor> executeCursor() = 0;

  virtual void bindInt(int colIndex, int value) = 0;

  virtual void bindDouble(int colIndex, double value) = 0;

  virtual void bindString(int colIndex, std::string value) = 0;

  virtual void bindBool(int colIndex, bool value) = 0;
};
}  // namespace Db