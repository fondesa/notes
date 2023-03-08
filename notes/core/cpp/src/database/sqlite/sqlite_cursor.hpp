#pragma once

#include <string>
#include "database/database_cursor.hpp"
#include "shared_sqlite_statement.hpp"
#include "sqlite3.h"

namespace Db {

class SQLiteCursor : public Db::Cursor {
 public:
  SQLiteCursor(sqlite3 *db, const SharedSQLiteCStatement &stmt);

  bool next() override;

 protected:
  void ensureNextWasInvoked() override;

  void ensureIndexInBounds(int colIndex) override;

  int getInt(int colIndex) override;

  double getDouble(int colIndex) override;

  std::string getString(int colIndex) override;

  bool getBool(int colIndex) override;

  int reset();

  int clearBindings();

 private:
  sqlite3 *db{};
  SharedSQLiteCStatement stmt;
  int columnCount;
  bool hadNext;

  static void ensureColumnType(int columnType, int colIndex, int sqliteType);
};
}  // namespace Db