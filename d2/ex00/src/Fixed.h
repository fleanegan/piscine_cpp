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

	Fixed(const Fixed& other);
	Fixed & operator = (const Fixed& other);
	~Fixed();
	Fixed();
	int     getRawBits() const;
	void    setRawBits(int value);
};


#endif //EX00_FIXED_H
