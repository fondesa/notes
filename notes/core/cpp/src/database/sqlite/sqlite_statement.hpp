#pragma once

#include <optional>
#include <string>
#include "database/database_statement.hpp"
#include "shared_sqlite_statement.hpp"
#include "sqlite3.h"

namespace Db {

class SQLiteStatement : public Db::Statement {
 public:
  SQLiteStatement(sqlite3 *db, const std::string &sql);

 protected:
  void executeVoid() override;

  std::optional<int> executeOptionalInt() override;

  int executeInt() override;

  std::optional<std::string> executeOptionalString() override;

  std::shared_ptr<Db::Cursor> executeCursor() override;

  void bindInt(int colIndex, int value) override;

  void bindDouble(int colIndex, double value) override;

  void bindString(int colIndex, std::string value) override;

  void bindBool(int colIndex, bool value) override;

  virtual int reset();

  virtual int clearBindings();

 private:
  sqlite3 *db{};
  SharedSQLiteCStatement stmt;
};
}  // namespace Db