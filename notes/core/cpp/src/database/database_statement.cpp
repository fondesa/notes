#include "database/database_statement.hpp"

namespace Db {

template <>
void Statement::execute() {
  executeVoid();
}

template <>
std::optional<int> Statement::execute() {
  return executeOptionalInt();
}

template <>
int Statement::execute() {
  return executeInt();
}

template <>
std::optional<std::string> Statement::execute() {
  return executeOptionalString();
}

template <>
std::shared_ptr<Cursor> Statement::execute() {
  return executeCursor();
}

template <>
void Statement::bind(int colIndex, int value) {
  bindInt(colIndex, value);
}

template <>
void Statement::bind(int colIndex, double value) {
  bindDouble(colIndex, value);
}

template <>
void Statement::bind(int colIndex, std::string value) {
  bindString(colIndex, std::move(value));
}

template <>
void Statement::bind(int colIndex, bool value) {
  bindBool(colIndex, value);
}
}  // namespace Db