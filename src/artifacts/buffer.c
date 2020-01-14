/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:55:12 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/14 13:20:42 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

t_buffer		*new_buffer(void)
{
	t_buffer	*buffer;

	buffer = (t_buffer *)malloc(sizeof(t_buffer));
	buffer->size = 0;
	return (buffer);
}

void			buffer_push(t_buffer *buffer, char c)
{
	char	*temp_str;
	size_t	counter;

	if (buffer->size > 0)
	{
		temp_str = (char *)malloc(sizeof(char) * (buffer->size + 2));
		counter = -1;
		while (++counter < buffer->size)
		{
			temp_str[counter] = buffer->str[counter];
		}
		temp_str[buffer->size] = c;
		temp_str[buffer->size + 1] = '\0';
		free(buffer->str);
		buffer->str = temp_str;
		buffer->size++;
	}
	else
	{
		buffer->str = (char *)malloc(sizeof(char) + 1);
		buffer->str[0] = c;
		buffer->str[1] = '\0';
		buffer->size = 1;
	}
}

void			buffer_destroy(t_buffer *buffer)
{
	if (buffer->size > 0)
		free(buffer->str);
	free(buffer);
	buffer = NULL;
}
