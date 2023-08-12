#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		static const unsigned int	CAPACITY = 100;

	private:
		std::string	ideas[CAPACITY];

	public:
		Brain(void);
		Brain(const Brain &ref);
		~Brain(void);
		Brain	&operator=(const Brain &ref);

		void		addIdea(const std::string &ref, unsigned int i);
		std::string	getIdea(unsigned int i) const;
		void		showIdeas(void) const;
};


#endif
