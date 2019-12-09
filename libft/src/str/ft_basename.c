#include "str.h"

char	*ft_basename(const char *path)
{
	char *basename;

	basename = ft_strrchr(path, '/');
	return ((basename) ? basename + 1 : (char *)path);
}
