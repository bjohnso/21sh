#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

extern char		**g_argv;

void	ft_error_exit(const char *str);
int		ft_perror(char *name);
void	ft_usage(char const *name, char const *str);

#endif
