/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:04:52 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 02:21:59 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	set_array(int *arr, int val, int len)
{
	while (len--)
		arr[len] = val;
}

int	get_val_by_index(t_stack *stack, int index)
{
	t_node	*node;

	node = stack->top;
	while (node != NULL)
	{
		if (node->index == index)
			return (node->val);
		node = node->prev;
	}
	return (0);
}
