#include "libft.h"
#include <stddef.h>

char	*ft_getenv(char **env, char *key)
{
	if (!env)
		return (NULL);
	while (*env)
	{
		if (ft_strcmp(*env, key) == '=' &&
			ft_strlen(key) == ft_strlenchr(*env, '='))
			return (*env + ft_strlen(key) + 1);
		env++;
	}
	return (NULL);
}
