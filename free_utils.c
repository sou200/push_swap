/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:22:38 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 03:46:46 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free_stack(data->subseq);
	if (data->sub_len != NULL)
		free(data->sub_len);
	if (data->sub_indexes != NULL)
		free(data->sub_indexes);
}

void	exit_err_msg(char *msg, t_data *data)
{
	term(data);
	ft_putstr_fd(msg, 2);
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
