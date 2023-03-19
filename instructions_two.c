/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:02:37 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 02:19:45 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int print)
{
	t_node	*tmplast;

	if (data->a->size < 2)
		return ;
	tmplast = data->a->top->prev;
	data->a->top->next = get_first_node(data->a);
	data->a->top->next->prev = data->a->top;
	if (data->a->size > 2)
		data->a->top->prev->next = NULL;
	data->a->top->prev = NULL;
	data->a->top = tmplast;
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_data *data, int print)
{
	t_node	*tmplast;

	if (data->b->size < 2)
		return ;
	tmplast = data->b->top->prev;
	data->b->top->next = get_first_node(data->b);
	data->b->top->next->prev = data->b->top;
	if (data->b->size > 2)
		data->b->top->prev->next = NULL;
	data->b->top->prev = NULL;
	data->b->top = tmplast;
	if (print)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_data *data, int print)
{
	ra(data, 0);
	rb(data, 0);
	if (print)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}
