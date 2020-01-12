/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:47:49 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:47:50 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, int y)
{
	double temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}
