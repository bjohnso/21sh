#ifndef BTREE_H
# define BTREE_H

# include "libft.h"

typedef struct s_btree	t_btree;

struct		s_btree
{
	void	*content;
	size_t	content_size;
	t_btree	*left;
	t_btree	*right;
};

t_btree		*ft_btreenew(void const *content, size_t content_size);

#endif
