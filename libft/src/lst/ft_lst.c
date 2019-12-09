#include "lst.h"
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lst(void *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list *)malloc(sizeof(t_list))) == 0)
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = content;
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
