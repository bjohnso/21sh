/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:45:58 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:45:58 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_PRIVATE_H
# define FT_TERM_PRIVATE_H

void	ft_cursor_goto(int x, int y);
void	ft_termcmd(char *str);
void	ft_get_win_size(int *x, int *y);

#endif
