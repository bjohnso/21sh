/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:51 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:51 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_H
# define SYS_H

# include <unistd.h>

# define STDIN  STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO
# define IS_CHILD(pid) (pid == 0)

char	*ft_getenv(char **env, char *key);
int		ft_isdir(const char *path);
int		ft_unixcase(const char *str);

#endif
