#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

#include <gtest/gtest.h>
#include <libprecision/libprecision.hpp>


TEST(uint128_t, initializer)
{
	ASSERT_NE(uint128_t(123), uint128_t(456));
	ASSERT_EQ(uint128_t(123), uint128_t(0, 123));
}

TEST(uint128_t, equality)
{
	ASSERT_TRUE(uint128_t(123, 456) == uint128_t(123, 456));
	ASSERT_FALSE(uint128_t(123, 456) == uint128_t(789, 0123));
}

TEST(uint128_t, non_equality)
{
	ASSERT_TRUE(uint128_t(123, 456) != uint128_t(789, 0123));
	ASSERT_FALSE(uint128_t(123, 456) != uint128_t(123, 456));
}

TEST(uint128_t, bitwise_and)
{
	ASSERT_EQ(uint128_t(1)&1, uint128_t(1));
}

TEST(uint128_t, bitwise_not)
{
	ASSERT_EQ(~uint128_t((uint64_t)-1, (uint64_t)-1), 0);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}