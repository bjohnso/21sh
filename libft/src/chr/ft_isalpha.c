int		ft_isalpha(int c)
{
	return (((unsigned)c | 32) - 97 < 26u);
}
