/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:47:11 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 03:38:44 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_to_top(t_data *data)
{
	t_node	*a_node;

	indexing(data->a);
	a_node = data->a->top;
	while (a_node->val != data->a->min)
		a_node = a_node->prev;
	if (a_node->index > data->a->size / 2)
		iter_move(data, rra, data->a->size - a_node->index, 1);
	else
		iter_move(data, ra, a_node->index, 1);
}

void	sort(t_data *data)
{
	if (data->a->size == 2)
		min_to_top(data);
	else if (data->a->size == 3)
		ultra_lite_sort(data);
	else if (data->a->size >= 4 && data->a->size <= 5)
		lite_sort(data);
	else
		lovely_sort(data);
}
