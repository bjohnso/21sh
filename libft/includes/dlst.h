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
