#include <sys/stat.h>
#include <unistd.h>

int	ft_isdir(const char *path)
{
	struct stat	sb;

	if (stat(path, &sb))
		return (0);
	return (S_ISDIR(sb.st_mode));
}
