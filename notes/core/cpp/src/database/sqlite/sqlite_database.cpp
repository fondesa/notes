#include "sqlite_database.hpp"
#include <iostream>
#include "sqlite_database_exception.hpp"
#include "sqlite_statement.hpp"

namespace Db {

SQLiteDatabase::SQLiteDatabase(std::string dbPath, int flags) {
  auto movedPath = std::move(dbPath);
  int rc = sqlite3_open_v2(movedPath.c_str(), &db, flags, nullptr);
  if (rc != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
  std::cout << "Opened database successfully" << std::endl;
}

SQLiteDatabase::~SQLiteDatabase() {
  sqlite3_close(db);
  std::cout << "SQLiteDatabase closed" << std::endl;
}

void SQLiteDatabase::executeTransaction(std::function<void()> transact) const {
  auto transaction = std::move(transact);
  int rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
  if (rc != SQLITE_OK) {
    throw Db::sqliteException(db);
  }

  // Executes the transaction.
  transaction();

  rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);
  if (rc != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
}

std::shared_ptr<Db::Statement> SQLiteDatabase::createStatement(std::string sql) const {
  auto movedSql = std::move(sql);
  return std::make_shared<SQLiteStatement>(db, movedSql);
}
}  // namespace Db