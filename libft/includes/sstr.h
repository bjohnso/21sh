/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:45 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:46 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSTR_H
# define SSTR_H

void	ft_sstrdel(char ***sstr);
void	ft_sstrdelone(char **sstr, int index);
char	**ft_sstrdup(char **sstr);
size_t	ft_sstrlen(char *const sstr[]);
char	**ft_sstrpush(char **sstr, char *str);
void	ft_sstrputs(char **sstr);

#endif
