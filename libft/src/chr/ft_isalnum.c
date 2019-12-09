int		ft_isalnum(int c)
{
	return ((((unsigned)c | 32) - 97 < 26u) || ((unsigned)c - 48) < 10u);
}
