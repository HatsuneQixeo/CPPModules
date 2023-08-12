#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		unsigned int	data1;
		unsigned int	data2;
	public:
		/* Constructor && Destructor */
		Data(unsigned int data1, unsigned int data2);
		Data(const Data &ref);
		~Data(void);

		/* OperatorOverload */
		Data	&operator=(const Data &ref);

		/* Getters */
		unsigned int	getData1(void) const;
		unsigned int	getData2(void) const;

		/* MemberFunctions */

};

std::ostream	&operator<<(std::ostream &stream, const Data &data);

#endif
