#include <bitset>

class uint128_t
{
private:
	std::bitset<128> bits;
public:
	const std::bitset<128> &get_bits() const
	{
		return bits;
	}

	void set_bits(const std::bitset<128> &new_bits)
	{
		bits = new_bits;
	}

	std::string get_string() const
	{
		return bits.to_string();
	}

	operator std::bitset<128>&()
	{
		return bits;
	}

	uint128_t operator<<(const size_t &pos) const
	{
		return {bits<<pos};
	}

	uint128_t &operator<<=(const size_t &pos)
	{
		bits<<=pos;
		return *this;
	}

	uint128_t operator>>(const size_t &pos) const
	{
		return {bits>>pos};
	}

	uint128_t &operator>>=(const size_t &pos)
	{
		bits>>=pos;
		return *this;
	}

	uint128_t &operator&=(const uint128_t &right)
	{
		bits&=right.get_bits();
		return *this;
	}

	uint128_t &operator|=(const uint128_t &right)
	{
		bits|=right.get_bits();
		return *this;
	}

	uint128_t &operator^=(const uint128_t &right)
	{
		bits^=right.get_bits();
		return *this;
	}

	uint128_t operator~()
	{
		return {~bits};
	}

	const bool operator==(const uint128_t &right) const
	{
		return bits==right.get_bits();
	}

	const bool operator!=(const uint128_t &right) const
	{
		return bits!=right.get_bits();
	}

	uint128_t() : bits() {}

	uint128_t(const std::string &str) : bits{str} {}

	uint128_t(const std::bitset<128> &bitset) : bits{bitset} {}

};

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