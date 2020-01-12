/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:14 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:15 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSTR_H
# define DSTR_H

# include <stddef.h>

# define FT_DSTR_INDEX(d, i) ((d).data[(i)])

typedef struct	s_dstr
{
	size_t				len;
	size_t				cap;
	char				*data;
}				t_dstr;

int				ft_dstr_new(t_dstr *dstr, size_t init_cap);
void			ft_dstr_append(t_dstr *dstr, char *newdata);
void			ft_dstr_resize(t_dstr *dstr, size_t min);
void			ft_dstr_nappend(t_dstr *dstr, char *newdata, size_t n);
void			ft_dstr_free(t_dstr *dstr);

#endif
