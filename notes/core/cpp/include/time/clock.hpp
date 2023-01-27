#pragma once

#include <ctime>
#include <string>

namespace Time {

class Clock {
   public:
    virtual std::time_t currentTimeSeconds() = 0;
};
}
