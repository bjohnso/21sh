#include <libft.h>
#include <stddef.h>

t_list	*ft_lstreverse(t_list **head)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	if (head)
	{
		while (*head)
		{
			next = (*head)->next;
			(*head)->next = prev;
			prev = *head;
			*head = next;
		}
		*head = prev;
	}
	return (prev);
}
