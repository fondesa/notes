#include "shared_sqlite_statement.hpp"
#include "database/database_exception.hpp"
#include "sqlite_database_exception.hpp"

namespace Db {

SharedSQLiteCStatement::SharedSQLiteCStatement(sqlite3 *db, const std::string &query)
    : originalStmt(nullptr), refCount(nullptr) {
  int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &originalStmt, nullptr);
  if (rc != SQLITE_OK) {
    throw Db::sqliteException(db);
  }
  if (!originalStmt) {
    // When the query is empty for example, SQLite returns SQLITE_OK without initializing the statement.
    throw Db::Exception("Can't generate any statement from the query \"" + query + "\".");
  }
  // The reference count is 1 since we have to count the object which created this statement.
  refCount = new unsigned int(1);
}

SharedSQLiteCStatement::SharedSQLiteCStatement(const SharedSQLiteCStatement &other)
    : originalStmt(other.originalStmt), refCount(other.refCount) {
  // Increments the reference counter of the `sqlite3_stmt` since it has been copied somewhere else.
  ++(*refCount);
}

SharedSQLiteCStatement::~SharedSQLiteCStatement() {
  // Since "refCount" is initialized in the constructor, dereferencing it without checking is safe.
  if (--(*refCount) == 0) {
    // If the count reaches zero, finalizes the `sqlite3_stmt`, as it's not owned by someone anymore.
    // Since we are in the destructor, there's no need to check the result code of this API because it won't be used.
    sqlite3_finalize(originalStmt);
    // Deletes the reference counter.
    delete refCount;
    refCount = nullptr;
    originalStmt = nullptr;
  }
}

unsigned int SharedSQLiteCStatement::useCount() {
  // We don't need to check the validity of the pointer since this method requires a valid instance of
  // SharedSQLiteCStatement to be invoked and if SharedSQLiteCStatement is initialized then refCount is initialized too.
  return *refCount;
}

SharedSQLiteCStatement::operator sqlite3_stmt *() const {
  return originalStmt;
}
}  // namespace Db