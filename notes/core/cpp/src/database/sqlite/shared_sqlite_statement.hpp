#pragma once

#include <string>
#include "sqlite3.h"

namespace Db {

/**
 * A shared pointer implementation of the `sqlite3_stmt` C API.
 * This class initializes the reference counter in the constructor and finalizes the `sqlite3_stmt` in the destructor
 * when the ref counter reaches 0.
 */
class SharedSQLiteCStatement {
 public:
  SharedSQLiteCStatement(sqlite3 *db, const std::string &query);

  SharedSQLiteCStatement(const SharedSQLiteCStatement &other);

  ~SharedSQLiteCStatement();

  /**
   * Returns the number of the owners of this object.
   */
  unsigned int useCount();

  /**
   * The cast operator returns the pointer to the `sqlite3_stmt`.
   * This is useful to use this type directly with the SQLite C api.
   */
  operator sqlite3_stmt *() const;

 private:
  // Points to the original statement.
  sqlite3_stmt *originalStmt;
  // Points to the heap allocated reference counter of the `sqlite3_stmt`.
  // It's used to make the owning object to live longer than the object which originally created it.
  // e.g. Db::Cursor should live longer than the Db::Statement which created it.
  unsigned int *refCount;
  // Avoids any assignments making the assignment operator private.
  SharedSQLiteCStatement &operator=(const SharedSQLiteCStatement &other);
};
}  // namespace Db