#include "sqlite_statement.hpp"
#include <vector>
#include "sqlite_cursor.hpp"
#include "sqlite_database_exception.hpp"

namespace Db::Sql {

Statement::Statement(sqlite3 *db, const std::string &sql) : db(db), stmt(db, sql) {
}

void Statement::executeVoid() {
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    throw Db::sqliteException(db);
  }
  if (clearBindings() != SQLITE_OK || reset() != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
}

std::optional<int> Statement::executeOptionalInt() {
  int status = sqlite3_step(stmt);
  auto result = std::optional<int>();
  if (status == SQLITE_DONE) {
    // If there are no rows to read, the value is absent.
    return result;
  }
  if (status != SQLITE_ROW) {
    throw Db::sqliteException(db);
  }
  int columnType = sqlite3_column_type(stmt, 0);
  if (columnType != SQLITE_INTEGER) {
    throw Db::Exception("The result should be of type " + std::to_string(SQLITE_INTEGER) + " instead of " +
                        std::to_string(columnType));
  }
  result = sqlite3_column_int(stmt, 0);
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    throw Db::sqliteException(db);
  }
  if (clearBindings() != SQLITE_OK || reset() != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
  return result;
}

int Statement::executeInt() {
  auto result = executeOptionalInt();
  if (!result) {
    throw Db::Exception("The statement didn't return any row.");
  }
  return *result;
}

std::optional<std::string> Statement::executeOptionalString() {
  int status = sqlite3_step(stmt);
  auto result = std::optional<std::string>();
  if (status == SQLITE_DONE) {
    // If there are no rows to read, the value is absent.
    return result;
  }
  if (status != SQLITE_ROW) {
    throw Db::sqliteException(db);
  }
  int columnType = sqlite3_column_type(stmt, 0);
  if (columnType != SQLITE_TEXT) {
    throw Db::Exception("The result should be of type " + std::to_string(SQLITE_TEXT) + " instead of " +
                        std::to_string(columnType));
  }
  auto text = sqlite3_column_text(stmt, 0);
  result = std::string(reinterpret_cast<const char *>(text));
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    throw Db::sqliteException(db);
  }
  if (clearBindings() != SQLITE_OK || reset() != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
  return result;
}

std::shared_ptr<Db::Cursor> Statement::executeCursor() {
  return std::make_shared<SQLiteCursor>(db, stmt);
}

void Statement::bindInt(int colIndex, int value) {
  int rc = sqlite3_bind_int(stmt, colIndex, value);
  if (rc != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
}

void Statement::bindDouble(int colIndex, double value) {
  int rc = sqlite3_bind_double(stmt, colIndex, value);
  if (rc != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
}

void Statement::bindString(int colIndex, std::string value) {
  auto movedValue = std::move(value);
  int rc = sqlite3_bind_text(stmt, colIndex, movedValue.c_str(), -1, SQLITE_TRANSIENT);
  if (rc != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
}

void Statement::bindBool(int colIndex, bool value) {
  int intValue = (value) ? 1 : 0;
  bindInt(colIndex, intValue);
}

int Statement::reset() {
  return sqlite3_reset(stmt);
}

int Statement::clearBindings() {
  return sqlite3_clear_bindings(stmt);
}
}  // namespace Db::Sql