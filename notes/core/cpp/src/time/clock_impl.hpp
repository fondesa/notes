#pragma once

#include "time/clock.hpp"

namespace Time {

class ClockImpl : public Clock {
   public:
    std::time_t currentTimeSeconds() override;
};
}
