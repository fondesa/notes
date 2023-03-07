#include "time/time_format.hpp"
#include <gtest/gtest.h>

TEST(TimeFormatTest, givenTimeInSecondsWhenFormatIsInvokedThenISO_8601TimeIsReturned) {
  Time::Format::ISO_8601 formattedTime = Time::Format::format(1572085165);

  ASSERT_EQ("2019-10-26T10:19:25Z", formattedTime);
}

TEST(TimeFormatTest, givenISO_8601TimeWhenParseIsInvokedThenTimeInSecondsIsReturned) {
  time_t time = Time::Format::parse("2019-10-26T10:19:25Z");

  ASSERT_EQ(1572085165, time);
}
