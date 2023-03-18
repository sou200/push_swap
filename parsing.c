/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:10 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/17 21:51:51 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	containspc(const char *arg)
{
	int	i;

	i = -1;
	while (arg[++i] != '\0')
		if (arg[i] == ' ')
			return (1);
	return (0);
}

static int	isvalid(const char *arg)
{
	int	i;
	int	digitc;

	i = 0;
	digitc = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
		digitc++;
	}
	if (digitc > 0)
		return (1);
	return (0);
}

static void	getint(t_data *data, const char *arg)
{
	t_node	*node;
	int		val;
	int status;

	if (isvalid(arg))
	{
		val = ft_atoi(arg, &status);
		if(status == 1)
			exit_err_msg(ERR_MSG, data);
		if (check_dup(val, data))
			exit_err_msg(ERR_MSG, data);
		node = new_node(val);
		if (node == NULL)
			exit_err_msg(ERR_MSG, data);
		add_at_first(data->a, node);
	}
	else
		exit_err_msg(ERR_MSG, data);
}

static void	parceonearg(const char *arg, t_data *data)
{
	char	**args;
	int		i;

	if (containspc(arg))
	{
		i = 0;
		args = ft_split(arg, ' ');
		if (args == NULL)
			exit_err_msg(ERR_MSG, data);
		while (args[i] != NULL)
			getint(data, args[i++]);
		free_two_d(args);
	}
	else
		getint(data, arg);
}

void	parse(int argc, const char *argv[], t_data *data)
{
	int	i;

	if (argc < 2)
		exit_err_msg(ERR_MSG, data);
	i = 1;
	while (i < argc)
		parceonearg(argv[i++], data);
}
