#include <bitset>
#include <ostream>

namespace precision
{
	template<std::size_t N>
	class UnsignedInteger
	{
	private:
		std::bitset<N> bits;
		const std::size_t size = N;

	public:
		const std::bitset<N> &get_bits() const
		{
			return bits;
		}

		void set_bits(const std::bitset<N> &new_bits)
		{
			bits = new_bits;
		}

		std::string get_string() const
		{
			return bits.to_string();
		}

		std::size_t get_size() const
		{
			return size;
		}

		operator std::bitset<N>&()
		{
			return bits;
		}

		UnsignedInteger<N> operator<<(const size_t &pos) const
		{
			return {bits<<pos};
		}

		UnsignedInteger<N> &operator<<=(const size_t &pos)
		{
			bits<<=pos;
			return *this;
		}

		UnsignedInteger<N> operator>>(const size_t &pos) const
		{
			return {bits>>pos};
		}

		UnsignedInteger<N> &operator>>=(const size_t &pos)
		{
			bits>>=pos;
			return *this;
		}

		UnsignedInteger<N> &operator&=(const UnsignedInteger<N> &right)
		{
			bits&=right.get_bits();
			return *this;
		}

		UnsignedInteger<N> &operator|=(const UnsignedInteger<N> &right)
		{
			bits|=right.get_bits();
			return *this;
		}

		UnsignedInteger<N> &operator^=(const UnsignedInteger<N> &right)
		{
			bits^=right.get_bits();
			return *this;
		}

		UnsignedInteger<N> operator~() const
		{
			return {~bits};
		}

		UnsignedInteger<N> &operator+=(const UnsignedInteger<N> &right)
		{
			*this = *this+right;
			return *this;
		}

		UnsignedInteger<N> &operator+=(const unsigned long long &right)
		{
			*this = *this+UnsignedInteger<N>(right);
			return *this;
		}

		UnsignedInteger<N> &operator-=(const UnsignedInteger<N> &right)
		{
			*this = *this-right;
			return *this;
		}

		UnsignedInteger<N> &operator-=(const unsigned long long &right)
		{
			*this = *this-UnsignedInteger<N>(right);
			return *this;
		}

		UnsignedInteger<N> &operator*=(const UnsignedInteger<N> &right)
		{
			*this = *this*right;
			return *this;
		}

		UnsignedInteger<N> &operator*=(const unsigned long long &right)
		{
			*this = *this*UnsignedInteger<N>(right);
			return *this;
		}

		UnsignedInteger<N> &operator/=(const UnsignedInteger<N> &right)
		{
			*this = *this/right;
			return *this;
		}

		UnsignedInteger<N> &operator/=(const unsigned long long &right)
		{
			*this = *this/UnsignedInteger<N>(right);
			return *this;
		}

		UnsignedInteger<N> &operator++()
		{
			*this += 1;
		}

		UnsignedInteger<N> &operator--()
		{
			*this -= 1;
		}

		UnsignedInteger<N> &operator++(int tmp)
		{
			*this += 1;
		}

		UnsignedInteger<N> &operator--(int tmp)
		{
			*this -= 1;
		}

		const bool operator==(const UnsignedInteger<N> &right) const
		{
			return bits==right.get_bits();
		}

		const bool operator==(const unsigned long long &right) const
		{
			return bits==std::bitset<N>(right);
		}

		const bool operator!=(const UnsignedInteger<N> &right) const
		{
			return bits!=right.get_bits();
		}

		const bool operator!=(const unsigned long long &right) const
		{
			return bits!=std::bitset<N>(right);
		}

		UnsignedInteger<N> &operator=(const UnsignedInteger<N> &right)
		{
			bits = right.get_bits();
		}

		UnsignedInteger<N> &operator=(const unsigned long long &right)
		{
			bits = std::bitset<N>(right);
		}

		UnsignedInteger() : bits(), size(N) {}
		UnsignedInteger(const int &a) : bits(a), size(N) {}
		UnsignedInteger(const std::string &str) : bits{str}, size{N} {}
		UnsignedInteger(const unsigned long long &a) : bits(a), size{N} {}
		UnsignedInteger(const std::bitset<N> &bs) : bits{bs}, size{N} {}
	};

	template<std::size_t N>
	UnsignedInteger<N> operator&(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		return {left.get_bits()&right.get_bits()};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator&(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return {left.get_bits()&std::bitset<N>(right)};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator|(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		return {left.get_bits()|right.get_bits()};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator|(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return {left.get_bits()|std::bitset<N>(right)};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator^(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		return {left.get_bits()^right.get_bits()};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator^(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return {left.get_bits()^std::bitset<N>(right)};
	}

	template<std::size_t N>
	const bool operator> (const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		if(left == right)
			return false;
		for(std::size_t i = left.get_bits().size()-1; i >= 0; --i)
		{
			if(left.get_bits()[i] != right.get_bits()[i])
			{
				if(right.get_bits()[i])
					return false;
				else
					return true;
			}
		}
		return false;
	}

	template<std::size_t N>
	const bool operator> (const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left>UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	const bool operator>=(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		if(left == right)
			return true;
		for(std::size_t i = left.get_bits().size()-1; i >= 0; --i)
		{
			if(left.get_bits()[i] != right.get_bits()[i])
			{
				if(right.get_bits()[i])
					return false;
				else
					return true;
			}
		}
		return true;
	}

	template<std::size_t N>
	const bool operator>=(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left>=UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	const bool operator< (const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		if(left == right)
			return false;
		for(std::size_t i = left.get_bits().size()-1; i >= 0; --i)
		{
			if(left.get_bits()[i] != right.get_bits()[i])
			{
				if(right.get_bits()[i])
					return true;
				else
					return false;
			}
		}
		std::cout<<left.get_string()<<"\n";
		std::cout<<right.get_string()<<"\n";
		return false;
	}

	template<std::size_t N>
	const bool operator< (const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left<UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	const bool operator<=(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		if(left == right)
			return true;
		for(std::size_t i = left.get_bits().size()-1; i >= 0; --i)
		{
			if(left.get_bits()[i] != right.get_bits()[i])
			{
				if(right.get_bits()[i])
					return true;
				else
					return false;
			}
		}
		return true;
	}

	template<std::size_t N>
	const bool operator<=(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left<=UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	UnsignedInteger<N> operator+(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		std::bitset<N> ret;
		bool carry = false;

		for(std::size_t i = 0; i < ret.size(); ++i)
		{
			if(left.get_bits()[i] && right.get_bits()[i])
			{
				ret[i] = carry;
				carry = true;
			}
			else if(left.get_bits()[i] || right.get_bits()[i])
			{
				ret[i] = !carry;
			}
			else
			{
				ret[i] = carry;
				carry = false;
			}
		}

		return {ret};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator+(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left+UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	UnsignedInteger<N> operator-(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		std::bitset<N> ret;
		bool carry = false;

		for(std::size_t i = 0; i < ret.size(); ++i)
		{
			if(left.get_bits()[i] && right.get_bits()[i])
			{
				ret[i] = carry;
			}
			else if(left.get_bits()[i] || right.get_bits()[i])
			{
				ret[i] = !carry;
				carry = right.get_bits()[i];
			}
			else
			{
				ret[i] = carry;
			}
		}

		return {ret};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator-(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left-UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	UnsignedInteger<N> operator*(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		std::bitset<N> ret;

		for(std::size_t i = 0; i < right.get_bits().size(); ++i)
		{
			std::bitset<N> tmp;
			for(std::size_t j = 0; j < tmp.size(); ++j)
			{
				tmp[j] = (right.get_bits()[i] && left.get_bits()[j]);
			}

			ret = UnsignedInteger<N>(ret)+UnsignedInteger<N>(tmp<<i);
		}

		return {ret};
	}

	template<std::size_t N>
	UnsignedInteger<N> operator*(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left*UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	UnsignedInteger<N> operator/(const UnsignedInteger<N> &left, const UnsignedInteger<N> &right)
	{
		UnsignedInteger<N> result, tmp = left;
		while(tmp >= right)
		{
			++result;
			tmp -= right;
		}
		return result;
	}

	template<std::size_t N>
	UnsignedInteger<N> operator/(const UnsignedInteger<N> &left, const unsigned long long &right)
	{
		return left/UnsignedInteger<N>(right);
	}

	template<std::size_t N>
	std::ostream& operator<<(std::ostream &stream, const UnsignedInteger<N> &obj)
	{
		return stream << obj.get_bits();
	}

	typedef UnsignedInteger<128> uint128_t;
} // namespace precision