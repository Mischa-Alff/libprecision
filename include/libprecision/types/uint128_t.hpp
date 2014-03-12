#include <bitset>
#include <ostream>

class uint128_t
{
private:
	std::bitset<128> bits;
public:
	const std::bitset<128> &get_bits() const;
	void set_bits(const std::bitset<128> &new_bits);
	std::string get_string() const;
	operator std::bitset<128>&();
	uint128_t operator<<(const size_t &pos) const;
	uint128_t &operator<<=(const size_t &pos);
	uint128_t operator>>(const size_t &pos) const;
	uint128_t &operator>>=(const size_t &pos);
	uint128_t &operator&=(const uint128_t &right);
	uint128_t &operator|=(const uint128_t &right);
	uint128_t &operator^=(const uint128_t &right);
	uint128_t operator~();
	const bool operator==(const uint128_t &right) const;
	const bool operator!=(const uint128_t &right) const;
	uint128_t();
	uint128_t(const std::string &str);
	uint128_t(const std::bitset<128> &bitset);
};

uint128_t operator&(const uint128_t &left, const uint128_t &right);
uint128_t operator|(const uint128_t &left, const uint128_t &right);
uint128_t operator^(const uint128_t &left, const uint128_t &right);
std::ostream& operator<<(std::ostream &stream, const uint128_t &obj);