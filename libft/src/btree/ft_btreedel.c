#include "btree.h"

void	ft_btreedel(t_btree **root, void (*del)(void *, size_t))
{
	if (root && *root && del)
	{
		ft_btreedel((*root)->left, del);
		ft_btreedel((*root)->right, del);
		ft_btreedelone((*root), del);
	}
}
