#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

/* Constructor && Destructor */
template <typename T>
Array<T>::Array(void):
	data(nullptr),
	length(0)
{}

template <typename T>
Array<T>::Array(unsigned int length):
	data(new T[length]),
	length(length)
{}

template <typename T>
Array<T>::Array(const Array<T> &ref):
	data(nullptr),
	length(0)
{
	*this = ref;
}

template <typename T>
Array<T>::~Array(void)
{
	this->clear();
}


/* OperatorOverload */
template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &ref)
{
	if (this == &ref)
		return (*this);
	this->resize(ref.length);
	for (unsigned int i = 0; i < ref.length; i++)
		this->data[i] = ref.data[i];
	return (*this);
}

template <typename T>
bool	Array<T>::operator==(const Array<T> &ref) const
{
	if (this->length != ref.length)
		return (false);
	for (unsigned int i = 0; i < ref.length; i++)
		if (this->data[i] != ref.data[i])
			return (false);
	return (true);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int i) const
{
	if (i >= this->length)
		throw std::out_of_range("OutOfRange: (" + std::to_string(i) + ") len: " + std::to_string(this->length));
	return (this->data[i]);
}

template <typename T>
T	&Array<T>::operator[](unsigned int i)
{
	const Array<T>	&cref = *this;

	return (const_cast<T &>(cref[i]));
}


/* Getters */
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->length);
}


/* MemberFunctions */
template <typename T>
void	Array<T>::resize(unsigned int newSize)
{
	T	*tmp;

	if (this->length == newSize)
		return ;
	{
		const unsigned int	lenCopy = ((newSize > this->length) ? this->length : newSize);

		tmp = new T[newSize];
		for (unsigned int i = 0; i < lenCopy; i++)
			tmp[i] = this->data[i];
	}
	this->clear();
	this->length = newSize;
	this->data = tmp;
}

template <typename T>
void	Array<T>::clear(void)
{
	delete[] this->data;
	this->data = nullptr;
	this->length = 0;
}

#endif
