#include "database/database_client.hpp"
#include <iostream>
#include <memory>
#include "database/database_exception.hpp"
#include "database/sqlite/sqlite_database.hpp"

namespace Db {

void Client::create(std::string dbPath) {
  if (databaseInstance != nullptr) {
    std::cout << "WARNING: the database is already created." << std::endl;
    return;
  }
  // We just ignore the lint error to avoid to cast both flags to unsigned.
  databaseInstance = std::make_shared<SQLiteDatabase>(std::move(dbPath));
}

std::shared_ptr<Database> Client::get() {
  if (databaseInstance == nullptr) {
    throw Db::Exception("The database should be created before.");
  }
  return databaseInstance;
}

void Client::release() {
  if (databaseInstance != nullptr) {
    databaseInstance.reset();
  }
}

std::shared_ptr<Database> Client::databaseInstance;
}  // namespace Db
