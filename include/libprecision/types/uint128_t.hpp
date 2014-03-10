class uint128_t
{
private:
	uint64_t upper, lower;
	static constexpr uint8_t size_bits_half = sizeof(uint64_t)*8;
	static constexpr uint8_t size_bits = sizeof(uint64_t)*8*2;
public:

	uint128_t operator&(const uint8_t bit) const
	{
		if(bit < size_bits_half)
			return lower&bit;

		else
			return {upper&(bit-size_bits_half), lower};

		return 0;
	}

	uint128_t operator~() const
	{
		return {~upper, ~lower};
	}

	bool operator==(const uint128_t &right) const
	{
		return (upper == right.upper) && (lower == right.lower);
	}

	bool operator==(const uint64_t &right) const
	{
		return (lower == right) && (upper == 0);
	}

	bool operator!=(const uint128_t &right) const
	{
		return (upper != right.upper) || (lower != right.lower);
	}

	bool operator!=(const uint64_t &right) const
	{
		return (lower != right) || (upper != 0);
	}

	uint128_t(uint64_t src_upper, uint64_t src_lower)
	{
		upper = src_upper;
		lower = src_lower;
	}

	uint128_t(uint64_t src_lower)
	{
		upper = 0;
		lower = src_lower;
	}
};