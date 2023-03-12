#pragma once

#include <string>

namespace Db {

class Cursor {
 public:
  virtual ~Cursor() = default;

  virtual bool next() = 0;

  template <typename T>
  T get(int colIndex);

 protected:
  virtual void ensureNextWasInvoked() = 0;

  virtual void ensureIndexInBounds(int colIndex) = 0;

  virtual int getInt(int colIndex) = 0;

  virtual double getDouble(int colIndex) = 0;

  virtual std::string getString(int colIndex) = 0;

  virtual bool getBool(int colIndex) = 0;
};
}  // namespace Db