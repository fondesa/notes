#pragma once

#include <string>
#include <ctime>

namespace Time::Format {

typedef std::string ISO_8601;

ISO_8601 format(std::time_t time);

std::time_t parse(ISO_8601 formattedTime);
}
