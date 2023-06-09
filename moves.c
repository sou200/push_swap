/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:08:18 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 03:33:55 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node_to_elevate(t_data *data, t_node *bnode)
{
	t_node	*a_node;

	a_node = data->a->top;
	while (!valid_move(data, a_node, bnode))
		a_node = a_node->prev;
	return (a_node);
}

int	valid_move(t_data *data, t_node *anode, t_node *bnode)
{
	t_node	*next_node;

	next_node = anode->next;
	if (anode->next == NULL)
		next_node = get_first_node(data->a);
	if (bnode->val < anode->val && bnode->val > next_node->val)
		return (1);
	else if ((bnode->val < data->a->min || bnode->val > data->a->max)
		&& anode->val == data->a->min)
		return (1);
	return (0);
}

void	iter_move(t_data *data, void (*move)(t_data *, int), int n, int print)
{
	while (n--)
		move(data, print);
}

int	calc_move(t_data *data, t_node *anode, t_node *bnode)
{
	int	moves;

	moves = 0;
	if ((anode->index > data->a->size / 2) == (bnode->index > data->b->size
			/ 2))
	{
		if (anode->index > data->a->size / 2)
			moves = max(data->a->size - anode->index, data->b->size
					- bnode->index);
		else
			moves = max(anode->index, bnode->index);
	}
	else
	{
		if (bnode->index > data->b->size / 2)
			moves = data->b->size - bnode->index;
		else
			moves = bnode->index;
		if (anode->index > data->a->size / 2)
			moves += data->a->size - anode->index;
		else
			moves += anode->index;
	}
	return (moves);
}

void	set_moves(t_data *data)
{
	t_node	*anode;
	t_node	*bnode;

	bnode = data->b->top;
	indexing(data->a);
	indexing(data->b);
	while (bnode != NULL)
	{
		anode = data->a->top;
		while (!valid_move(data, anode, bnode))
			anode = anode->prev;
		bnode->moves = calc_move(data, anode, bnode);
		bnode = bnode->prev;
	}
}
