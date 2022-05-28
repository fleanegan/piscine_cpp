#ifndef EX03_A_MATERIA_HPP
#define EX03_A_MATERIA_HPP

#include "ICharacter.hpp"

//todo: wtf do we need this
class ICharacter;

class AMateria
{
protected:
	const std::string type;
public:
	explicit AMateria(std::string const & type);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif // EX03_A_MATERIA_HPP