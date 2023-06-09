/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:22:38 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 11:43:17 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmpnode;

	while (stack->top != NULL)
	{
		tmpnode = stack->top->prev;
		free(stack->top);
		stack->top = tmpnode;
	}
}

void	term(t_data *data)
{
	free_stack(data->a);
	free_stack(data->b);
}

void	exit_err_msg(char *msg, t_data *data)
{
	if (msg != NULL)
		ft_putstr_fd(msg, 2);
	term(data);
	exit(1);
}

void	free_two_d(char **twod)
{
	int	i;

	i = 0;
	while (twod[i] != NULL)
	{
		free(twod[i]);
		i++;
	}
	free(twod);
}
