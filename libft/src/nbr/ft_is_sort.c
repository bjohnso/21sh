/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:47:59 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:47:59 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *array, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	if (length == 0 || length == 1)
		return (1);
	while (i < length - 1)
	{
		if (f(array[i], array[i + 1]) <= 0)
			i++;
		else
			break ;
	}
	if (i == length - 1)
		return (1);
	return (0);
}
