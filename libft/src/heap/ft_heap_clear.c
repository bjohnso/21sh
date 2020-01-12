/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:47 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:48 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include <stdlib.h>

int		ft_heap_clear(void)
{
	t_heap_man	*heap_man;
	t_memnode	*memnode;
	t_memnode	*next;

	heap_man = ft_heap_singleton();
	if (heap_man == NULL)
		return (1);
	memnode = heap_man->first;
	while (memnode != NULL)
	{
		next = memnode->next;
		free(memnode);
		memnode = next;
	}
	heap_man->first = NULL;
	heap_man->last = NULL;
	return (0);
}
