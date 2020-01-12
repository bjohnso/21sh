/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:21 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:22 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "lst.h"
# include <stddef.h>

# define GNL_BUFF_SIZE 1024
# define GNL_CHK(a) if(1){if(a){return(-1);}}

typedef struct	s_gnl
{
	int			fd;
	char		*file_content;
}				t_gnl;

int				get_next_line(const int fd, char **line);
void			ft_gnl_free(void *content, size_t size);
t_list			**ft_gnl_list(void);

#endif
