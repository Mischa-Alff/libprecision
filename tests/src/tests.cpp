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

#include "UnsignedInteger.hpp"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}