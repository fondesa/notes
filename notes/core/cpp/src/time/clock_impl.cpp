#include "time/clock_impl.hpp"

namespace Time {

std::time_t ClockImpl::currentTimeSeconds() {
  std::time_t now;
  return time(&now);
}
}  // namespace Time
