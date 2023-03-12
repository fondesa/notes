#pragma once

#include <string>
#include "notes/core/cpp/src/database/database.hpp"

namespace Db {

class Client {
 public:
  static void create(std::string dbPath);

  static std::shared_ptr<Database> get();

  static void release();

 private:
  Client() = default;

  static std::shared_ptr<Database> databaseInstance;
};
}  // namespace Db