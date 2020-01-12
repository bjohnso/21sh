/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:23 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:24 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <stddef.h>

typedef struct s_memnode	t_memnode;
typedef struct s_heap_man	t_heap_man;

struct			s_memnode
{
	void		*ptr;
	t_memnode	*prev;
	t_memnode	*next;
};

struct			s_heap_man
{
	t_memnode	*first;
	t_memnode	*last;
};

/*
** Memory allocation
*/

void			*ft_hmalloc(size_t size);
void			*ft_hmemalloc(size_t size);
void			*ft_hrealloc(void *ptr, size_t src_size, size_t new_size);

/*
** Memory deallocation
*/

int				ft_hfree(void *ptr);
int				ft_heap_clear(void);

/*
** Heap manager
*/

t_heap_man		*ft_heap_singleton(void);

/*
** HSTR functions
*/

char			*ft_hstrdup(char *hstr);
char			*ft_hstrndup(char *hstr, size_t size);

#endif
