/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:38:33 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 11:38:34 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_H
# define OPTS_H

# include <stdbool.h>

typedef long long	t_flag;

typedef struct	s_opt
{
	char		c;
	char		*name;
	char		*help;
	char		*def_val;
	char		*metavar;
	t_flag		flags_on;
	t_flag		flags_off;
	int			(*getarg)();
	int			arg_required:1;
	int			required:1;
}				t_opt;

typedef struct	s_optsdata
{
	char		*prog;
	char		*description;
	char		*epilog;
	char		**argv;
	int			help:1;
	int			usage:1;
	int			required_opts:1;
	t_opt		opt_map[];
}				t_optsdata;

typedef struct	s_optparse
{
	t_flag		flags;
	char		**argv;
}				t_optparser;

typedef struct	s_ohelp
{
	t_opt		*opt;
	char		*opt_name;
	char		*opt_arg;
	int			i;
}				t_ohelp;

t_opt			*ft_opts_getlong(t_opt opt_map[], char *name);
t_opt			*ft_opts_getshort(t_opt opt_map[], char c);
int				ft_opts_long(char ***av, t_optsdata *opts, void *data);
int				ft_opts_short(char ***av, t_optsdata *opts, void *data);
int				ft_opts_help(t_optsdata *optsdata);
int				ft_opts_suggest(t_optsdata *optsdata);
void			ft_opts_parse(t_optsdata *opts, void *data);
int				ft_opts_usage(t_optsdata *opts, t_opt *opt, char *name, char c);
int				ft_opts(char **av, t_optsdata *opts, void *data, bool parse);

#endif
