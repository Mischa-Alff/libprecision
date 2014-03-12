#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

#include <iostream>
#include <gtest/gtest.h>
#include <libprecision/libprecision.hpp>
#include <bitset>
#include <string>

std::string operator*(const std::string &left, const int &right)
{
	std::string ret;
	for(int i = 0; i < right; ++i)
		ret += left;
	return ret;
}

using namespace prec;

const std::size_t test_precision = 128;

const std::string test_bs_string = std::string("10")*(test_precision/2);
std::bitset<test_precision> test_bs{test_bs_string};

TEST(UnsignedInteger, initializer_bitset)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs).get_bits(),
		test_bs
	);
}

TEST(UnsignedInteger, operator_cast_bitset)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs),
		test_bs
	);
}

TEST(UnsignedInteger, function_get_string)
{
	test_bs = std::bitset<test_precision>(test_bs_string);
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs).get_string(),
		test_bs_string
	);
}

TEST(UnsignedInteger, initializer_string)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs_string).get_string(),
		test_bs_string
	);
}

TEST(UnsignedInteger, function_get_bits)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs).get_bits(),
		test_bs
	);
}

TEST(UnsignedInteger, function_set_bits)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs).get_bits(),
		test_bs
	);
}

TEST(UnsignedInteger, operator_bitwise_shift_left)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs)<<4,
		test_bs<<4
	);
}

TEST(UnsignedInteger, operator_equals_bitwise_shift_left)
{
	UnsignedInteger<test_precision> a(test_bs);
	a<<=4;
	ASSERT_EQ(
		a,
		test_bs<<4
	);
}

TEST(UnsignedInteger, operator_bitwise_shift_right)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs)>>4,
		test_bs>>4
	);
}

TEST(UnsignedInteger, operator_equals_bitwise_shift_right)
{
	UnsignedInteger<test_precision> a(test_bs);
	a>>=4;
	ASSERT_EQ(
		a,
		test_bs>>4
	);
}

TEST(UnsignedInteger, operator_bitwise_and)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs)&123,
		test_bs&std::bitset<test_precision>{123}
	);
}

TEST(UnsignedInteger, operator_equals_bitwise_and)
{
	UnsignedInteger<test_precision> a(test_bs);
	a&=123;
	ASSERT_EQ(
		a,
		test_bs&std::bitset<test_precision>{123}
	);
}

TEST(UnsignedInteger, operator_bitwise_xor)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(test_bs)^UnsignedInteger<test_precision>{"1111111"},
		test_bs^std::bitset<test_precision>{"1111111"}
	);
}

TEST(UnsignedInteger, operator_equals_bitwise_xor)
{
	UnsignedInteger<test_precision> a(test_bs);
	a^=UnsignedInteger<test_precision>{"1111111"};
	ASSERT_EQ(
		a,
		test_bs^std::bitset<test_precision>{"1111111"}
	);
}

TEST(UnsignedInteger, operator_bitwise_not)
{
	ASSERT_EQ(
		~UnsignedInteger<test_precision>(test_bs),
		~test_bs
	);
}

TEST(UnsignedInteger, operator_comparison_equality)
{
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(test_bs) == UnsignedInteger<test_precision>(test_bs)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(test_bs)+1 == UnsignedInteger<test_precision>(test_bs)
	);
}

TEST(UnsignedInteger, operator_comparison_no_equality)
{
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(test_bs)+1 != UnsignedInteger<test_precision>(test_bs)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(test_bs) != UnsignedInteger<test_precision>(test_bs)
	);
}

TEST(UnsignedInteger, operator_comparison_greater)
{
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(1)+1 > UnsignedInteger<test_precision>(1)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(1) > UnsignedInteger<test_precision>(1)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(1)-1 > UnsignedInteger<test_precision>(1)
	);
}

TEST(UnsignedInteger, operator_comparison_greater_equal)
{
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(1)+1 >= UnsignedInteger<test_precision>(1)
	);
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(1) >= UnsignedInteger<test_precision>(1)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(1)-1 >= UnsignedInteger<test_precision>(1)
	);
}

TEST(UnsignedInteger, operator_comparison_less)
{
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(1)-1 < UnsignedInteger<test_precision>(1)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(1) < UnsignedInteger<test_precision>(1)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(1)+1 < UnsignedInteger<test_precision>(1)
	);
}

TEST(UnsignedInteger, operator_comparison_less_equal)
{
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(1)-1 <= UnsignedInteger<test_precision>(1)
	);
	ASSERT_TRUE(
		UnsignedInteger<test_precision>(1) <= UnsignedInteger<test_precision>(1)
	);
	ASSERT_FALSE(
		UnsignedInteger<test_precision>(1)+1 <= UnsignedInteger<test_precision>(1)
	);
}

TEST(UnsignedInteger, operator_arithmetic_addition)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(10)+1234,
		UnsignedInteger<test_precision>(1244)
	);
}

TEST(UnsignedInteger, operator_equals_arithmetic_addition)
{
	UnsignedInteger<test_precision> a(10);
	a += 1234;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(1244)
	);
}

TEST(UnsignedInteger, operator_arithmetic_subtraction)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(1234)-10,
		UnsignedInteger<test_precision>(1224)
	);
}

TEST(UnsignedInteger, operator_equals_arithmetic_subtraction)
{
	UnsignedInteger<test_precision> a(1234);
	a -= 10;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(1224)
	);
}

TEST(UnsignedInteger, operator_arithmetic_multiplication)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(2)*64,
		UnsignedInteger<test_precision>(128)
	);
}

TEST(UnsignedInteger, operator_equals_arithmetic_multiplication)
{
	UnsignedInteger<test_precision> a(64);
	a *= 2;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(128)
	);
}

TEST(UnsignedInteger, operator_arithmetic_division)
{
	ASSERT_EQ(
		UnsignedInteger<test_precision>(128)/2,
		UnsignedInteger<test_precision>(64)
	);
}

TEST(UnsignedInteger, operator_equals_arithmetic_division)
{
	UnsignedInteger<test_precision> a(128);
	a /= 2;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(64)
	);
}

TEST(UnsignedInteger, operator_modifier_increment_prefix)
{
	UnsignedInteger<test_precision> a(1234);
	++a;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(1234)+1
	);
}

TEST(UnsignedInteger, operator_modifier_increment_postfix)
{
	UnsignedInteger<test_precision> a(1234);
	a++;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(1234)+1
	);
}

TEST(UnsignedInteger, operator_modifier_decrement_prefix)
{
	UnsignedInteger<test_precision> a(1234);
	--a;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(1234)-1
	);
}

TEST(UnsignedInteger, operator_modifier_decrement_postfix)
{
	UnsignedInteger<test_precision> a(1234);
	a--;
	ASSERT_EQ(
		a,
		UnsignedInteger<test_precision>(1234)-1
	);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}