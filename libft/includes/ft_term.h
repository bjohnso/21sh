/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:19 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:20 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include <stdbool.h>

void	ft_clrscreen(int rows);
void	ft_cursor_goto(int x, int y);
void	ft_get_win_size(int *x, int *y);
void	ft_highlight(bool set);
void	ft_termcmd(char *str);
void	ft_underline(bool set);

#endif
