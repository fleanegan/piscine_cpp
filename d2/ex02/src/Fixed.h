//
// Created by fleanegan on 12.05.22.
//

#ifndef EX00_FIXED_H
#define EX00_FIXED_H
#define FRACTIONAL_BITS 8

#include <iostream>

class Fixed;

class Fixed {
private:
	static const int    fractionalBits = FRACTIONAL_BITS;
	int                 value;

public:
	Fixed();
	explicit Fixed(int value);
	explicit Fixed(float value);
	Fixed(const Fixed &other);
	Fixed & operator = (const Fixed &other);
	bool operator < (const Fixed &other) const;
	bool operator > (const Fixed &other) const;
	bool operator >= (const Fixed &other) const;
	bool operator <= (const Fixed &other) const;
	bool operator == (const Fixed &other) const;
	bool operator == (float other) const;
	bool operator != (const Fixed &other) const;
	Fixed   operator - (const Fixed &other) const;
	Fixed   operator + (const Fixed &other) const;
	Fixed   operator * (const Fixed &other) const;
	Fixed   operator / (const Fixed &other) const;
	Fixed&  operator ++ ();
	const Fixed   operator ++ (int);
	Fixed&  operator -- ();
	const Fixed   operator -- (int);
	static Fixed&  min (Fixed const &a, Fixed const & b);
	static Fixed&  max (Fixed const &a, Fixed const & b);
	static Fixed&  min (Fixed &a, Fixed & b);
	static Fixed&  max (Fixed &a, Fixed & b);
	~Fixed();

	int     getRawBits() const;
	void    setRawBits(int value);
	int     toInt() const;
	float   toFloat() const;
	void    toBits(float fractionalRest);
	void    storeSign(float newValue);
	float   getFractionalRest(float newValue);
	void    throwIfTooBig(int value) const;

};

std::ostream& operator<< (std::ostream& stream, const Fixed &a);


#endif //EX00_FIXED_H
