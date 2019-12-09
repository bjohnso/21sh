#include "lst.h"
#include <stddef.h>

t_list			*ft_lstfind(t_list *begin_list, void *data, int (*cmp)())
{
	t_list *node;

	node = begin_list;
	while (node)
	{
		if ((cmp)(node->content, data) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
