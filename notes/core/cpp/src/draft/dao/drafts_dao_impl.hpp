#pragma once

#include "database/database.hpp"
#include "drafts_dao.hpp"

class DraftsDaoImpl : public DraftsDao {
 public:
  DraftsDaoImpl(std::shared_ptr<Db::Database> db);

  void createSchema() override;

  std::optional<Draft> get() override;

  void upsert(Draft draft) override;

  void clear() override;

 private:
  std::shared_ptr<Db::Database> db;
};