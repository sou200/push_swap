/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:02:44 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 02:19:27 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data, int print)
{
	if (data->a->size < 2)
		return ;
	data->a->top->next = get_first_node(data->a);
	data->a->top->next->prev = data->a->top;
	if (data->a->size > 2)
		data->a->top->next->next->prev = NULL;
	data->a->top->next->next = NULL;
	data->a->top = data->a->top->next;
	if (print)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_data *data, int print)
{
	if (data->b->size < 2)
		return ;
	data->b->top->next = get_first_node(data->b);
	data->b->top->next->prev = data->b->top;
	if (data->b->size > 2)
		data->b->top->next->next->prev = NULL;
	data->b->top->next->next = NULL;
	data->b->top = data->b->top->next;
	if (print)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_data *data, int print)
{
	rra(data, 0);
	rrb(data, 0);
	if (print)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
