#include "iter.hpp"

void	strToUpper(std::string &ele)
{
	// for (size_t i = 0; ele[i] != '\0'; i++)
	// 	ele[i] = toupper(ele[i]);
	iter(&ele[0], ele.size(), ft_toupper);
}

void	strToLower(std::string &ele)
{
	// for (size_t i = 0; ele[i] != '\0'; i++)
	// 	ele[i] = tolower(ele[i]);
	iter(&ele[0], ele.size(), ft_tolower);
}

void	strCapitalize(std::string &ele)
{
	// if (ele.front() == '\0')
	// 	return ;
	// ele.front() = toupper(ele.front());
	// for (size_t i = 1; ele[i] != '\0'; i++)
	// {
	// 	if (isspace(ele[i - 1]))
	// 		ele[i] = toupper(ele[i]);
	// 	else
	// 		ele[i] = tolower(ele[i]);
	// }
	iter(&ele[0], ele.size(), ft_capitalize);
}

void	testStrlist(void)
{
	typedef void	(*StringFunc)(std::string &ele);

	std::string		tellme[] = {
		"[Verse 1]",
		"Katachi no nai kimochi wasurenai you ni",
		"Kimari kitta reiauto wo keshita",
		"Futo kuchi zusanda fureezu wo tsukamaete",
		"Mune ni himeta kotoba nose sora ni toki hanatsu no",
		"",
		"[Chorus]",
		"Kimi ni tsutaetai koto ga",
		"Kimi ni todoketai koto ga",
		"Takusan no ten wa sen ni natte",
		"Tooku kanata e to hibiku",
		"Kimi ni tsutaetai kotoba",
		"Kimi ni todoketai oto ga",
		"Ikutsumo no sen wa en ni natte",
		"Subete tsunagete iku doko ni datte, ah-ah",
		"",
		"[Verse 2]",
		"Masshiro ni sunda hikari wa kimi no you",
		"Kazashita te no sukima wo tsutau koe ga",
		"Futo ugoita yubisaki kizamu rizumu ni",
		"Arittake no kotoba nose sora ni toki hanatsu no",
		"",
		"[Chorus]",
		"Kimi ni tsutaetai koto ga",
		"Kimi ni todoketai koto ga",
		"Takusan no ten wa sen ni natte",
		"Tooku kanata made ugatsu",
		"Kimi ni tsutaetai koto ga",
		"Kimi ni todoketai oto ga",
		"Ikutsumo no sen wa en ni natte",
		"Subete tsunagetе iku doko ni datte",
		"Ah-ah, ah-ah, ah-ah-ah-ah",
		"",
		"[Bridge]",
		"Kanadete ita kawaranai hibi wo utagawazu ni",
		"Asa wa darеka ga kureru mono da to omotte ita",
		"Isshun demo shinjita oto keshiki wo yurasu no",
		"Oshiete yo kimi dake no sekai",
		"",
		"[Chorus]",
		"Kimi ga tsutaetai koto wa",
		"Kimi ga todoketai koto wa",
		"Takusan no ten wa sen ni natte",
		"Tooku kanata e to hibiku",
		"Kimi ga tsutaetai kotoba",
		"Kimi ga todoketai oto wa",
		"Ikutsumono sen wa en ni natte",
		"Subete tsunageteku doko ni datte, ah-ah, ahhh",
	};
	const size_t		size = (sizeof(tellme) / sizeof(tellme[0]));
	const StringFunc	ft_log = showEndl<std::string>;
	const StringFunc	callback[] = {
		ft_log,
		strToLower,
		ft_log,
		strToUpper,
		ft_log,
		strCapitalize,
		ft_log,
	};
	const size_t		sizeCallback = (sizeof(callback) / sizeof(callback[0]));

	for (unsigned int i = 0; i < sizeCallback; i++)
	{
		std::cout << "Callback [" << i << "]" << std::endl;
		iter(tellme, size, callback[i]);
		std::cin.get();
	}
}
