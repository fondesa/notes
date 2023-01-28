#include <gtest/gtest.h>
#include "time/clock_impl.hpp"

TEST(ClockImplTest, whenCurrentTimeSecondsIsInvokedThenValidTimeIsReturned) {
    auto clock = Time::ClockImpl();
    std::time_t now;
    time(&now);

    ASSERT_LE(now, clock.currentTimeSeconds());
}