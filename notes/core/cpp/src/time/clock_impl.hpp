#pragma once

#include "time/clock.hpp"

namespace Time {

class ClockImpl : public Clock {
public:
    virtual ~ClockImpl() = default;

    std::time_t currentTimeSeconds() override;
};
}
