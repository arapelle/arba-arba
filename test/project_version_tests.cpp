#include <arba/arba/version.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

TEST(project_version_tests, test_version_macros)
{
    ASSERT_EQ(ARBA_ARBA_VERSION_MAJOR, 0);
    ASSERT_EQ(ARBA_ARBA_VERSION_MINOR, 27);
    ASSERT_EQ(ARBA_ARBA_VERSION_PATCH, 0);
    ASSERT_STREQ(ARBA_ARBA_VERSION, "0.27.0");
}
