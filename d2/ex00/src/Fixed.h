//
// Created by fleanegan on 12.05.22.
//

#ifndef EX00_FIXED_H
#define EX00_FIXED_H
#define FRACTIONAL_BITS 8
#define DEBUG_ME 0

#include <iostream>
#include <cmath>

class Fixed;

class Fixed {
private:
	static const int    fractionalBits = FRACTIONAL_BITS;
	int                 rawBits;
public:

	Fixed(const Fixed& other);
	Fixed & operator = (const Fixed& other);
	~Fixed();
	Fixed();

	int     getRawBits() const;
	void    setRawBits(const int & value);
};


#endif //EX00_FIXED_H
