void	ft_striter(char *s, void (*f)(char *))
{
	if (!s)
		return ;
	while (*s && *f)
		f(s++);
}
