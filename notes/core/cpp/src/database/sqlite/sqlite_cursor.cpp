#include "sqlite_cursor.hpp"
#include "sqlite_database_exception.hpp"

namespace Db {

SQLiteCursor::SQLiteCursor(sqlite3 *db, const SharedSQLiteCStatement &stmt) : db(db), stmt(stmt) {
  columnCount = sqlite3_column_count(stmt);
  hadNext = false;
}

bool SQLiteCursor::next() {
  int rc = sqlite3_step(stmt);
  if (rc == SQLITE_DONE) {
    if (clearBindings() != SQLITE_OK || reset() != SQLITE_OK) {
      throw Db::sqliteException(db);
    }
    return hadNext = false;
  }
  if (rc != SQLITE_ROW) {
    hadNext = false;
    throw Db::sqliteException(db);
  }
  return hadNext = true;
}

void SQLiteCursor::ensureNextWasInvoked() {
  if (!hadNext) {
    throw Db::Exception("The next() method returned false so it's not possible to get the value of the columns");
  }
}

void SQLiteCursor::ensureIndexInBounds(int colIndex) {
  if (colIndex >= columnCount) {
    throw Db::Exception("The column index " + std::to_string(colIndex) + " should be less than " +
                        std::to_string(columnCount));
  }
}

int SQLiteCursor::getInt(int colIndex) {
  int columnType = sqlite3_column_type(stmt, colIndex);
  ensureColumnType(columnType, colIndex, SQLITE_INTEGER);
  return sqlite3_column_int(stmt, colIndex);
}

double SQLiteCursor::getDouble(int colIndex) {
  int columnType = sqlite3_column_type(stmt, colIndex);
  ensureColumnType(columnType, colIndex, SQLITE_FLOAT);
  return sqlite3_column_double(stmt, colIndex);
}

std::string SQLiteCursor::getString(int colIndex) {
  int columnType = sqlite3_column_type(stmt, colIndex);
  ensureColumnType(columnType, colIndex, SQLITE_TEXT);
  auto text = sqlite3_column_text(stmt, colIndex);
  return reinterpret_cast<const char *>(text);
}

bool SQLiteCursor::getBool(int colIndex) {
  return getInt(colIndex) != 0;
}

int SQLiteCursor::reset() {
  return sqlite3_reset(stmt);
}

int SQLiteCursor::clearBindings() {
  return sqlite3_clear_bindings(stmt);
}

void SQLiteCursor::ensureColumnType(int columnType, int colIndex, int sqliteType) {
  if (columnType != sqliteType) {
    throw Db::Exception("The column at index " + std::to_string(colIndex) + " should be of type " +
                        std::to_string(sqliteType) + " instead of " + std::to_string(columnType));
  }
}
}  // namespace Db