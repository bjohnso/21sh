int		ft_countwords(char const *s, char c)
{
	int words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			words++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (words);
}
