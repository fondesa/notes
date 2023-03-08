#pragma once

#include "database/database_exception.hpp"

namespace Db {

Db::Exception sqliteException(sqlite3 *db) {
  return Db::Exception("SQLite error: " + std::string(sqlite3_errmsg(db)));
}
}  // namespace Db