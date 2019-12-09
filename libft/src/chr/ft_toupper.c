int		ft_toupper(int c)
{
	return (((unsigned)c - 97) < 26u ? c - 32 : c);
}
