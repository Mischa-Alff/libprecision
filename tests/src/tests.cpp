#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

#include <iostream>
#include <gtest/gtest.h>
#include <libprecision/libprecision.hpp>
#include <bitset>
#include <string>

std::string bs_string =
	"1010101010101010101010101010101010101010101010101010101010101010"
	"1010101010101010101010101010101010101010101010101010101010101010";

std::bitset<128> bs{bs_string};

TEST(uint128_t, initialize_bitset)
{
	ASSERT_EQ(uint128_t(bs).get_bits(), bs);
}

TEST(uint128_t, function_get_string)
{
	ASSERT_EQ(
		uint128_t(bs).get_string(),
		"1010101010101010101010101010101010101010101010101010101010101010"
		"1010101010101010101010101010101010101010101010101010101010101010"	
	);
}

TEST(uint128_t, initialize_string)
{
	ASSERT_EQ(
		uint128_t(
			"1010101010101010101010101010101010101010101010101010101010101010"
			"1010101010101010101010101010101010101010101010101010101010101010"
		).get_string(),
		"1010101010101010101010101010101010101010101010101010101010101010"
		"1010101010101010101010101010101010101010101010101010101010101010"
	);
}

TEST(uint128_t, function_get_set_bits)
{
	uint128_t a;
	a.set_bits(bs);

	ASSERT_EQ(
		a.get_bits(),
		bs
	);
}

TEST(uint128_t, operator_bitset)
{
	ASSERT_EQ(uint128_t(bs), bs);
}

TEST(uint128_t, operator_bitwise_shift_left)
{
	bs = std::bitset<128>(bs_string);
	uint128_t a(bs);
	for(int i = 0; i < bs.size(); i++)
		ASSERT_EQ(a<<i, bs<<i);
}

TEST(uint128_t, operator_equals_bitwise_shift_left)
{
	bs = std::bitset<128>(bs_string);
	uint128_t a(bs);
	for(int i = 0; i < bs.size(); i++)
		ASSERT_EQ(a<<=i, bs<<=i);
}

TEST(uint128_t, operator_bitwise_shift_right)
{
	bs = std::bitset<128>(bs_string);
	uint128_t a(bs);
	for(int i = 0; i < bs.size(); i++)
		ASSERT_EQ(a>>i, bs>>i);
}

TEST(uint128_t, operator_equals_bitwise_shift_right)
{
	bs = std::bitset<128>(bs_string);
	uint128_t a(bs);
	for(int i = 0; i < bs.size(); i++)
		ASSERT_EQ(a>>=i, bs>>=i);
}

TEST(uint128_t, operator_bitwise_and)
{
	bs = std::bitset<128>(bs_string);
	ASSERT_EQ(
		(uint128_t(bs)&std::bitset<128>("111111")),
		(bs&std::bitset<128>("111111"))
	);
}

TEST(uint128_t, operator_equals_bitwise_and)
{
	bs = std::bitset<128>(bs_string);
	uint128_t a(bs);
	ASSERT_EQ(
		(a &=std::bitset<128>("111111")),
		(bs&=std::bitset<128>("111111"))
	);
}

TEST(uint128_t, operator_bitwise_or)
{
	bs = std::bitset<128>(bs_string);
	ASSERT_EQ(
		(uint128_t(bs)|std::bitset<128>("111111")),
		(bs|std::bitset<128>("111111"))
	);
}

TEST(uint128_t, operator_equals_bitwise_or)
{
	bs = std::bitset<128>(bs_string);
	uint128_t a(bs);
	ASSERT_EQ(
		(a |=std::bitset<128>("111111")),
		(bs|=std::bitset<128>("111111"))
	);
}

TEST(uint128_t, operator_bitwise_xor)
{
	bs = std::bitset<128>(bs_string);
	ASSERT_EQ(
		(uint128_t(bs)^std::bitset<128>("111111")),
		(bs^std::bitset<128>("111111"))
	);
}

TEST(uint128_t, operator_equals_bitwise_xor)
{
	bs = std::bitset<128>(bs_string);
	uint128_t a(bs);
	ASSERT_EQ(
		(a ^=std::bitset<128>("111111")),
		(bs^=std::bitset<128>("111111"))
	);
}

TEST(uint128_t, operator_bitwise_not)
{
	bs = std::bitset<128>(bs_string);
	ASSERT_EQ(
		(~uint128_t(bs)),
		(~bs)
	);
}

TEST(uint128_t, operator_equality)
{
	bs = std::bitset<128>(bs_string);
	ASSERT_TRUE(
		uint128_t(bs) == uint128_t(bs)
	);

	ASSERT_FALSE(
		uint128_t(bs) == uint128_t()
	);
}

TEST(uint128_t, operator_no_equality)
{
	bs = std::bitset<128>(bs_string);
	ASSERT_TRUE(
		uint128_t(bs) != uint128_t()
	);

	ASSERT_FALSE(
		uint128_t(bs) != uint128_t(bs)
	);
}

TEST(uint128_t, operator_addition)
{
	ASSERT_EQ(uint128_t(10)+uint128_t(11), uint128_t(21));
}

TEST(uint128_t, operator_subtraction)
{
	ASSERT_EQ(uint128_t(11)-uint128_t(10), uint128_t(1));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}