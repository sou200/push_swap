/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:39:20 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 02:20:24 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int print)
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
	if (print)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_data *data, int print)
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
	if (print)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_data *data, int print)
{
	sa(data, 0);
	sb(data, 0);
	if (print)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}

void	pa(t_data *data, int print)
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
	if (print)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_data *data, int print)
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
	if (print)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
}
