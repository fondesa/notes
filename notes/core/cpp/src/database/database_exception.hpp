#pragma once

#include <exception>
#include <string>

namespace Db {

class Exception : public std::exception {
 public:
  explicit Exception(std::string msg);

  [[nodiscard]] const char *what() const noexcept override;

 private:
  std::string msg;
};
}  // namespace Db