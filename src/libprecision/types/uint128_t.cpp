#include <libprecision/types/uint128_t.hpp>

const std::bitset<128> &uint128_t::get_bits() const
{
	return bits;
}

void uint128_t::set_bits(const std::bitset<128> &new_bits)
{
	bits = new_bits;
}

std::string uint128_t::get_string() const
{
	return bits.to_string();
}

uint128_t::operator std::bitset<128>&()
{
	return bits;
}

uint128_t uint128_t::operator<<(const size_t &pos) const
{
	return {bits<<pos};
}

uint128_t &uint128_t::operator<<=(const size_t &pos)
{
	bits<<=pos;
	return *this;
}

uint128_t uint128_t::operator>>(const size_t &pos) const
{
	return {bits>>pos};
}

uint128_t &uint128_t::operator>>=(const size_t &pos)
{
	bits>>=pos;
	return *this;
}

uint128_t &uint128_t::operator&=(const uint128_t &right)
{
	bits&=right.get_bits();
	return *this;
}

uint128_t &uint128_t::operator|=(const uint128_t &right)
{
	bits|=right.get_bits();
	return *this;
}

uint128_t &uint128_t::operator^=(const uint128_t &right)
{
	bits^=right.get_bits();
	return *this;
}

uint128_t uint128_t::operator~()
{
	return {~bits};
}

const bool uint128_t::operator==(const uint128_t &right) const
{
	return bits==right.get_bits();
}

const bool uint128_t::operator!=(const uint128_t &right) const
{
	return bits!=right.get_bits();
}

uint128_t::uint128_t() : bits() {}

uint128_t::uint128_t(const std::string &str) : bits{str} {}

uint128_t::uint128_t(const std::bitset<128> &bitset) : bits{bitset} {}



uint128_t operator&(const uint128_t &left, const uint128_t &right)
{
	return {left.get_bits()&right.get_bits()};
}

uint128_t operator|(const uint128_t &left, const uint128_t &right)
{
	return {left.get_bits()|right.get_bits()};
}

uint128_t operator^(const uint128_t &left, const uint128_t &right)
{
	return {left.get_bits()^right.get_bits()};
}

std::ostream& operator<<(std::ostream &stream, const uint128_t &obj)
{
	return stream << obj.get_bits();
}