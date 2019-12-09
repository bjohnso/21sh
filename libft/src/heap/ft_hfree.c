#include "heap.h"
#include <stdlib.h>

static void	mfree_node(t_memnode *memnode)
{
	t_heap_man *heap_man;

	heap_man = ft_heap_singleton();
	if (memnode->prev == NULL)
		heap_man->first = memnode->next;
	else
		memnode->prev->next = memnode->next;
	if (memnode->next == NULL)
		heap_man->last = memnode->prev;
	else
		memnode->next->prev = memnode->prev;
	free(memnode);
}

int			ft_hfree(void *ptr)
{
	t_memnode	*memnode;

	if (ptr == NULL)
		return (1);
	memnode = (t_memnode *)((char *)ptr - sizeof(t_memnode));
	mfree_node(memnode);
	return (0);
}
