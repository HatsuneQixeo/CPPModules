#include <iostream>
#include <fstream>
#include "Strrr.hpp"

#ifndef SHOWASSIGN
# define SHOWASSIGN	0
#endif

#if 0
typedef Strrr		String;
# define LOG(arg)	std::cout << arg << std::endl
#else
typedef std::string	String;

# define LOG(arg)
#endif

String	ft_patsubst(const String &src, const String &find, const String &replace)
{
	LOG("\nFt_Patsubst Start");
	String			subst;
	size_t			start = 0;
	size_t			pos;
	const size_t	len_replaced = find.size();

	pos = src.find(find, 0);
	while (pos != String::npos)
	{
		LOG("LOOP BEGIN");
#if 0
		subst += src.substr(start, pos - start);
		subst += replace;
#else
		subst += src.substr(start, pos - start) + replace;
#endif
		start = pos + len_replaced;
		pos = src.find(find, start);
	}
#if 0 || SHOWASSIGN
	subst += src.substr(start);
	return (subst);
#else
	return (subst + String(src.substr(start)));
#endif
}

int	losersed(const std::string &filename, const String &find, const String &replace)
{
	std::ifstream	srcfile(filename);
	std::ofstream	dstfile(filename + ".replace");
	String			buffer;

	if (!srcfile.is_open())
		perror(filename.c_str());
	else if (!dstfile.is_open())
		perror((filename + ".replace").c_str());
	else
	{
		while (getline(srcfile, buffer))
		{
#	if 0 || SHOWASSIGN
#		if 0 && !SHOWASSIGN /* This still adds additional overhead */
			/*
				It can only optimise during initialisation,
				where the address of the variable has not been decided yet ...is what I assume.
				Never wrote a compiler myself, let alone going into the technical detail of optimisation.
			*/
			buffer = ft_patsubst(buffer, find, replace);
			dstfile << buffer << std::endl;
#		else /* The only case where doing the assignment before returning does not adds additional overhead,
			due to compiler optimisation */
			const std::string	str = ft_patsubst(buffer, find, replace);
			dstfile << str << std::endl;
#		endif
#	else
			dstfile << ft_patsubst(buffer, find, replace) << std::endl;
#	endif
		}
		return (0);
	}
	return (-1);
}

int	main(int argc, const char **argv)
{
	if (argc != 1 + 3)
		std::cout << "Usage: <Filename> <String to be replaced> <String to replace with>" << std::endl;
	else if (losersed(argv[1], argv[2], argv[3]) == 0)
		return (0);
	return (1);
}
