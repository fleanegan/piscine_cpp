//
// Created by fleanegan on 12.05.22.
//

#ifndef EX00_FIXED_H
#define EX00_FIXED_H
#define FRACTIONAL_BITS 8
#define DEBUG_ME 0

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
	Fixed(const Fixed& other);
	Fixed & operator = (const Fixed& other);
	~Fixed();

	int     getRawBits() const;
	void    setRawBits(int value);
	int     toInt() const;
	float   toFloat() const;

	void    storeSign(float newValue);

};

std::ostream& operator<< (std::ostream& stream, Fixed &a);


#endif //EX00_FIXED_H
