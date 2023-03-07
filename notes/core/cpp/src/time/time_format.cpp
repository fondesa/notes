#include "time/time_format.hpp"
#include <iomanip>

namespace Time::Format {

ISO_8601 format(std::time_t time) {
  // Create a buffer of the same result's size.
  char timeBuffer[sizeof "0000-00-00T00:00:00Z"];
  // Convert the time in seconds to the ISO-8601 format.
  strftime(timeBuffer, sizeof timeBuffer, "%FT%TZ", gmtime(&time));
  return timeBuffer;
}

std::time_t parse(ISO_8601 formattedDate) {
  auto movedDate = std::move(formattedDate);
  tm tm{};
  auto ss = std::istringstream(movedDate);
  // Fill the time struct reading the ISO-8601 time.
  ss >> std::get_time(&tm, "%Y-%m-%dT%TZ");
  // Get the time_t value for the struct.
  return timegm(&tm);
}
}  // namespace Time::Format
