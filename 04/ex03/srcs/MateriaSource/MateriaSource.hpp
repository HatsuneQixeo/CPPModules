#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		static const unsigned int	STORAGE_SIZE = 4;

	private:
		AMateria	*storage[STORAGE_SIZE];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &ref);
		~MateriaSource(void);
		MateriaSource	&operator=(const MateriaSource &ref);

		void		learnMateria(AMateria *materia);
		AMateria	*createMateria(const std::string &type);
};

#endif
