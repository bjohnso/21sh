#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <stdarg.h>

/*
**  Libc Functions
*/

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_asprintf(char **ret, const char *format, ...);

/*
**   Other main functions
*/

int				ft_strprintf(char **ret, const char *format, va_list ap);

#endif
