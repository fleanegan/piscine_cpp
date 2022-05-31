#ifndef EX03_A_MATERIA_HPP
#define EX03_A_MATERIA_HPP

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	const std::string type;

	AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
public:
	explicit AMateria(std::string const & type);
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif // EX03_A_MATERIA_HPP