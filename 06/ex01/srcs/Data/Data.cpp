#include "Data.hpp"

/* Constructor && Destructor */
Data::Data(unsigned int data1, unsigned int data2):
	data1(data1),
	data2(data2)
{}

Data::Data(const Data &ref)
{
	*this = ref;
}

Data::~Data(void)
{}


/* Operator Overload */
Data	&Data::operator=(const Data &ref)
{
	this->data1 = ref.data1;
	this->data2 = ref.data2;
	return (*this);
}


/* Getters */
unsigned int	Data::getData1(void) const
{
	return (this->data1);
}

unsigned int	Data::getData2(void) const
{
	return (this->data2);
}


/* Log */
std::ostream	&operator<<(std::ostream &stream, const Data &data)
{
	stream << "data1: " << data.getData1() 
		<< ", data2: " << data.getData2();
	return (stream);
}
