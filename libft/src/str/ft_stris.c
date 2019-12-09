int	ft_stris(char *str, int (*f)(int))
{
	while (*str)
	{
		if (!f(*str++))
		{
			return (0);
		}
	}
	return (1);
}
