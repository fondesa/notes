#include "sqlite_drafts_dao.hpp"

SQLiteDraftsDao::SQLiteDraftsDao(std::shared_ptr<Db::Database> db) : db(std::move(db)) {
}

void SQLiteDraftsDao::createSchema() {
  db->createStatement(
        "CREATE TABLE drafts ("
        "id INTEGER PRIMARY KEY DEFAULT 0 CHECK (id = 0)"
        "title TEXT NOT NULL, "
        "description TEXT NOT NULL"
        ")")
      ->execute<void>();
}

std::optional<Draft> SQLiteDraftsDao::get() {
  auto stmt = db->createStatement(
      "SELECT title, description "
      "FROM drafts "
      "LIMIT 1");

  auto draft = std::optional<Draft>();
  auto cursor = stmt->execute<std::shared_ptr<Db::Cursor>>();
  if (cursor->next()) {
    auto title = cursor->get<std::string>(0);
    auto description = cursor->get<std::string>(1);
    draft = Draft(title, description);
  }
  return draft;
}

void SQLiteDraftsDao::upsert(Draft draft) {
  auto stmt = db->createStatement(
      "INSERT INTO drafts (title, description) "
      "VALUES (?, ?) "
      "ON CONFLICT(id) "
      "DO UPDATE SET title = ?, description = ?");

  auto title = draft.getTitle();
  auto description = draft.getDescription();

  stmt->bind(1, title);
  stmt->bind(2, description);
  stmt->bind(3, title);
  stmt->bind(4, description);

  stmt->execute<void>();
}

void SQLiteDraftsDao::clear() {
  db->createStatement("DELETE FROM drafts")->execute<void>();
}
