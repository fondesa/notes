#include "database_cursor.hpp"

namespace Db {

template <>
int Cursor::get(int colIndex) {
  ensureNextWasInvoked();
  ensureIndexInBounds(colIndex);

  return getInt(colIndex);
}

template <>
double Cursor::get(int colIndex) {
  ensureNextWasInvoked();
  ensureIndexInBounds(colIndex);

  return getDouble(colIndex);
}

template <>
std::string Cursor::get(int colIndex) {
  ensureNextWasInvoked();
  ensureIndexInBounds(colIndex);

  return getString(colIndex);
}

template <>
bool Cursor::get(int colIndex) {
  ensureNextWasInvoked();
  ensureIndexInBounds(colIndex);

  return getBool(colIndex);
}
}  // namespace Db