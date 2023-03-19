/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:39:20 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 03:37:36 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_data *data)
{
	t_node	*anode;

	anode = data->a->top;
	while (anode != NULL)
	{
		if (anode->val == data->a->min)
			break ;
		anode = anode->prev;
	}
	if (anode->index > data->a->size / 2)
		iter_move(data, rra, data->a->size - anode->index, 1);
	else
		iter_move(data, ra, anode->index, 1);
	pb(data, 1);
}

void	ultra_lite_sort(t_data *data)
{
	indexing(data->a);
	if (data->a->top->val == data->a->max)
		ra(data, 1);
	else if (data->a->top->prev->val == data->a->max)
		rra(data, 1);
	if (data->a->top->val > data->a->top->prev->val)
		sa(data, 1);
}

void	lite_sort(t_data *data)
{
	t_node	*anode;

	while (data->a->size > 3)
	{
		indexing(data->a);
		push_min_to_b(data);
	}
	ultra_lite_sort(data);
	while (data->b->size > 0)
		pa(data, 1);
}

void	lovely_sort(t_data *data)
{
	lis(data, data->a);
	push_lis(data);
	while (data->b->size > 0)
	{
		set_moves(data);
		do_the_best_move(data);
	}
	min_to_top(data);
}
