/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:11 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:12 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	qsort_swap(void **v, int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void		ft_qsort(void **v, int left, int right,
										int (*comp)(const void *, const void *))
{
	int i;
	int last;

	if (left >= right)
		return ;
	qsort_swap(v, left, (left + right) / 2);
	last = left;
	i = left + 1;
	while (i <= right)
	{
		if ((*comp)(v[i], v[left]) < 0)
			qsort_swap(v, ++last, i);
		++i;
	}
	qsort_swap(v, left, last);
	ft_qsort(v, left, last - 1, comp);
	ft_qsort(v, last + 1, right, comp);
}
