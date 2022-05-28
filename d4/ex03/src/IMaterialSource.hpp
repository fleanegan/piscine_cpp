#ifndef EX03_I_MATERIAL_SOURCE
#define EX03_I_MATERIAL_SOURCE

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //EX03_I_MATERIAL_SOURCE