//
// Created by fleanegan on 12.05.22.
//

#ifndef EX00_FIXED_H
#define EX00_FIXED_H

class Fixed;

class Fixed {
private:
public:
	Fixed(const Fixed& other);
	Fixed & operator = (const Fixed& other);
	~Fixed();
	Fixed();
};


#endif //EX00_FIXED_H
