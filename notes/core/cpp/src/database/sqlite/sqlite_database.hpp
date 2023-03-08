#pragma once

#include "database/database.hpp"
#include "database/database_statement.hpp"
#include "sqlite3.h"

namespace Db {

class SQLiteDatabase : public Db::Database {
 public:
  SQLiteDatabase(std::string dbPath, int flags);

  ~SQLiteDatabase();

  void executeTransaction(std::function<void()> transact) const override;

  [[nodiscard]] std::shared_ptr<Db::Statement> createStatement(std::string sql) const override;

 private:
  sqlite3 *db{};
};
}  // namespace Db