/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_fmt_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:52:37 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:52:37 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_p.h"
#include "libft.h"
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

bool		ft_chk_flags(const char **format, t_info *pfinfo)
{
	const char	flags[] = "-+ 0#";
	size_t		i;

	i = 0;
	while (flags[i] != **format && flags[i])
		i++;
	if (flags[i])
	{
		pfinfo->flags = pfinfo->flags | (1 << i);
		(*format)++;
		return (true);
	}
	return (false);
}

bool		ft_chk_width(const char **format, t_info *pfinfo, va_list ap)
{
	int res;

	res = 0;
	if (**format == '*')
	{
		pfinfo->width = va_arg(ap, int);
		if (pfinfo->width < 0)
		{
			if (!(pfinfo->flags & LFT))
				pfinfo->flags ^= LFT;
			pfinfo->width = pfinfo->width * -1;
		}
		(*format)++;
		return (true);
	}
	if (!ISDIGIT(**format))
		return (false);
	while (ISDIGIT(**format))
	{
		res = res * 10 + (**format - '0');
		(*format)++;
	}
	pfinfo->width = res;
	return (true);
}

bool		ft_chk_prec(const char **format, t_info *pfinfo, va_list ap)
{
	int res;

	res = 0;
	if (**format != '.')
		return (false);
	pfinfo->pset = 1;
	(*format)++;
	if (**format == '*')
	{
		pfinfo->prec = va_arg(ap, int);
		if (pfinfo->prec < -1)
			pfinfo->prec = -1;
		(*format)++;
		return (true);
	}
	while (ISDIGIT(**format))
	{
		res = res * 10 + (**format - '0');
		(*format)++;
	}
	pfinfo->prec = res;
	return (true);
}

bool		ft_chk_len(const char **format, t_info *pfinfo)
{
	const char	lengths[] = "hhlljz";
	int			i;

	i = 0;
	if (ISLENMOD(**format))
	{
		i = ft_findchr(lengths, **format);
		if (i == 0)
		{
			if (*(*format + 1) == 'h')
				++*format;
			else
				i = 1;
		}
		if (i == 2)
			i = (*(*format + 1) == 'l') ? 3 : 2;
		pfinfo->length = MAX(i, pfinfo->length);
		++*format;
		return (true);
	}
	return (false);
}
