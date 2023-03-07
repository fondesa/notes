#pragma once

#include <functional>
#include <string>
#include "database_statement.hpp"

namespace Db {

class Database {
 public:
  virtual void executeTransaction(std::function<void()> transact) const = 0;

  [[nodiscard]] virtual std::shared_ptr<Statement> createStatement(std::string sql) const = 0;
};
}  // namespace Db