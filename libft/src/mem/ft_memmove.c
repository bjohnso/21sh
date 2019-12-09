#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d_str;
	unsigned char	*s_str;
	int				size;

	size = (int)len;
	d_str = (unsigned char *)dst;
	s_str = (unsigned char *)src;
	if (s_str < d_str)
	{
		while (--size > -1)
			d_str[size] = s_str[size];
	}
	else
	{
		while (size--)
			*d_str++ = *s_str++;
	}
	return (dst);
}
