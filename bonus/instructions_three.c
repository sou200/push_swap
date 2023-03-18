/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:02:44 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/16 03:05:11 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_data *data)
{
	if (data->a->size < 2)
		return ;
	data->a->top->next = get_first_node(data->a);
	data->a->top->next->prev = data->a->top;
	if (data->a->size > 2)
		data->a->top->next->next->prev = NULL;
	data->a->top->next->next = NULL;
	data->a->top = data->a->top->next;
}

void	rrb(t_data *data)
{
	if (data->b->size < 2)
		return ;
	data->b->top->next = get_first_node(data->b);
	data->b->top->next->prev = data->b->top;
	if (data->b->size > 2)
		data->b->top->next->next->prev = NULL;
	data->b->top->next->next = NULL;
	data->b->top = data->b->top->next;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
