/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:27:05 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/17 22:24:14 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// static t_node	*get_best_move_node(t_data *data)
// {
// 	t_node	*nodetomove;
// 	t_node	*currnode;

// 	nodetomove = data->b->top;
// 	currnode = data->b->top;
// 	while (currnode != NULL)
// 	{
// 		if (currnode->moves < nodetomove->moves)
// 			nodetomove = currnode;
// 		currnode = currnode->prev;
// 	}
// 	return (nodetomove);
// }

// static void	rot_a_and_b(t_data *data, t_node *anode, t_node *bnode, int adown)
// {
// 	if (adown)
// 	{
// 		iter_move(data, rrr, min(data->a->size - anode->index, data->b->size
// 				- bnode->index), 1);
// 		if (data->a->size - anode->index > data->b->size - bnode->index)
// 			iter_move(data, rra, data->a->size - anode->index - (data->b->size
// 					- bnode->index), 1);
// 		else
// 			iter_move(data, rrb, data->b->size - bnode->index - (data->a->size
// 					- anode->index), 1);
// 	}
// 	else
// 	{
// 		iter_move(data, rr, min(anode->index, bnode->index), 1);
// 		if (anode->index > bnode->index)
// 			iter_move(data, ra, anode->index - bnode->index, 1);
// 		else
// 			iter_move(data, rb, bnode->index - anode->index, 1);
// 	}
// }

// static void	rot_a_or_b(t_data *data, t_node *anode, t_node *bnode)
// {
// 	int		adown;
// 	int		bdown;

// 	adown = anode->index > data->a->size / 2;
// 	bdown = bnode->index > data->b->size / 2;
// 	if (adown)
// 		iter_move(data, rra, data->a->size - anode->index, 1);
// 	else
// 		iter_move(data, ra, anode->index, 1);
// 	if (bdown)
// 		iter_move(data, rrb, data->b->size - bnode->index, 1);
// 	else
// 		iter_move(data, rb, bnode->index, 1);
// }

// void	do_the_best_move(t_data *data)
// {
// 	t_node	*bnode;
// 	t_node	*anode;
// 	int		adown;
// 	int		bdown;

// 	bnode = get_best_move_node(data);
// 	anode = get_node_to_elevate(data, bnode);
// 	adown = anode->index > data->a->size / 2;
// 	bdown = bnode->index > data->b->size / 2;
// 	if (adown == bdown)
// 		rot_a_and_b(data, anode, bnode, adown);
// 	else
// 		rot_a_or_b(data, anode, bnode);
// 	pa(data, 1);
// }
