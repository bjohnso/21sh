/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:05 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:10 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

typedef struct s_dlst	t_dlst;

struct		s_dlst
{
	void	*content;
	size_t	content_size;
	t_dlst	*next;
	t_dlst	*prev;
};

#endif
