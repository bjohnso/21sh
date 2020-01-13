/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:42 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 16:01:58 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

t_buffer		*input_reader(void)
{
	t_buffer	*buffer;
	char		c;

	buffer = new_buffer();
	while (1)
	{
		c = ft_getchar();
		if (c != '\n' && c != '\r' && c != '\0' && c != -1)
		{
			buffer_push(buffer, c);
		}
		else
		{
			if (buffer->size > 0)
				return (buffer);
			else
				return (NULL);
		}
	}
}
