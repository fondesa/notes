#include "notes_database_client.hpp"
#include <iostream>
#include "database/database_exception.hpp"
#include "note/dao/drafts_dao_impl.hpp"

NotesDatabaseClient::NotesDatabaseClient(std::shared_ptr<Db::Database> db) {
  auto version = 1;
  auto readVersionStmt = db->createStatement("PRAGMA user_version");
  auto currentVersion = readVersionStmt->execute<int>();
  if (version == currentVersion) {
    // The database didn't change its version.
    return;
  }

  if (version < currentVersion) {
    throw Db::Exception("Can't downgrade database from version " + std::to_string(currentVersion) +
                        " to version " + std::to_string(version));
  }

  draftsDao = std::make_shared<DraftsDaoImpl>(db);

  db->executeTransaction([&] {
    if (currentVersion == 0) {
      std::cout << "Creating the database schema" << std::endl;
      draftsDao->createSchema();
    }

    auto writeVersionStmt = db->createStatement("PRAGMA user_version = " + std::to_string(version));
    writeVersionStmt->execute<void>();
  });
}

std::shared_ptr<DraftsDao> NotesDatabaseClient::getDraftsDao() {
  return draftsDao;
}
