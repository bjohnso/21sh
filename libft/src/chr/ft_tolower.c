int		ft_tolower(int c)
{
	return (((unsigned)c - 65) < 26u ? c + 32 : c);
}
