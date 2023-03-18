/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:39:20 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/16 03:07:20 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_data *data)
{
	if (data->a->size < 2)
		return ;
	data->a->top->next = data->a->top->prev;
	data->a->top->prev = data->a->top->prev->prev;
	if (data->a->size > 2)
		data->a->top->prev->next = data->a->top;
	data->a->top->next->next = NULL;
	data->a->top->next->prev = data->a->top;
	data->a->top = data->a->top->next;
}

void	sb(t_data *data)
{
	if (data->b->size < 2)
		return ;
	data->b->top->next = data->b->top->prev;
	data->b->top->prev = data->b->top->prev->prev;
	if (data->b->size > 2)
		data->b->top->prev->next = data->b->top;
	data->b->top->next->next = NULL;
	data->b->top->next->prev = data->b->top;
	data->b->top = data->b->top->next;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	pa(t_data *data)
{
	t_node	*tmpnode;

	if (data->b->size < 1)
		return ;
	tmpnode = data->b->top->prev;
	if (data->b->top->prev != NULL)
		data->b->top->prev->next = NULL;
	push_node(data->a, data->b->top);
	data->b->top = tmpnode;
	data->b->size--;
}

void	pb(t_data *data)
{
	t_node	*tmptop;

	if (data->a->size < 1)
		return ;
	tmptop = data->a->top->prev;
	if (tmptop != NULL)
		tmptop->next = NULL;
	push_node(data->b, data->a->top);
	data->a->top = tmptop;
	data->a->size--;
}
