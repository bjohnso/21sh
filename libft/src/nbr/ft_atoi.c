/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:48:03 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:48:04 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	result;
	int					i;
	int					sign;

	i = 0;
	result = 0;
	while (ISSPACE(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (ISDIGIT(str[i]))
		result = result * 10 + str[i++] - '0';
	if (i > 19 || result > 9223372036854775807)
		return ((sign == 1) ? -1 : 0);
	return ((int)result * sign);
}
