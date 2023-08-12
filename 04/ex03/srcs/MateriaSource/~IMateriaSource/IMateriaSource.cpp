#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{}

IMateriaSource::IMateriaSource(const IMateriaSource &ref)
{
	(void)ref;
}

IMateriaSource	&IMateriaSource::operator=(const IMateriaSource &ref)
{
	return (*this);
	(void)ref;
}

IMateriaSource::~IMateriaSource(void)
{}
