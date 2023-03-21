#pragma once

#include <memory>
#include "database/database.hpp"
#include "note/dao/drafts_dao.hpp"

class NotesDatabaseClient {
 public:
  NotesDatabaseClient(std::shared_ptr<Db::Database> db);

  std::shared_ptr<DraftsDao> getDraftsDao();

 private:
  std::shared_ptr<DraftsDao> draftsDao;
};