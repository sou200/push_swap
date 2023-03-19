/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_inc_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:17:41 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 05:06:03 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lis(t_data *data)
{
	t_node	*subseq_node;
	int		a_size;

	subseq_node = data->subseq->top;
	a_size = data->a->size;
	while (a_size--)
	{
		if (subseq_node != NULL && subseq_node->val == data->a->top->val)
		{
			ra(data, 1);
			subseq_node = subseq_node->prev;
		}
		else
			pb(data, 1);
	}
}

static int	get_max_index(int *arr, int len)
{
	int	max_index;
	int	i;

	i = 0;
	max_index = i;
	while (i < len)
	{
		if (arr[i] > arr[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

static void	get_lis(t_data *data)
{
	int		i;
	int		max_len;
	t_node	*node;

	i = get_max_index(data->sub_len, data->a->size);
	max_len = data->sub_len[i];
	while (max_len--)
	{
		node = new_node(get_val_by_index(data->a, i));
		push_node(data->subseq, node);
		i = data->sub_indexes[i];
	}
}

static void	initlis(t_data *data)
{
	data->sub_len = malloc(data->a->size * sizeof(int));
	if (data->sub_len == NULL)
		exit_err_msg(ERR_MSG, data);
	data->sub_indexes = malloc(data->a->size * sizeof(int));
	if (data->sub_indexes == NULL)
		exit_err_msg(ERR_MSG, data);
	if (data->sub_len == NULL || data->sub_indexes == NULL)
		exit_err_msg(ERR_MSG, data);
	set_array(data->sub_len, 1, data->a->size);
}

void	lis(t_data *data)
{
	t_node	*i;
	t_node	*j;

	initlis(data);
	i = data->a->top;
	while (i != NULL)
	{
		j = data->a->top;
		while (j->index < i->index)
		{
			if (j->val < i->val && data->sub_len[j->index]
				+ 1 >= data->sub_len[i->index])
			{
				data->sub_len[i->index] = data->sub_len[j->index] + 1;
				data->sub_indexes[i->index] = j->index;
			}
			j = j->prev;
		}
		i = i->prev;
	}
	get_lis(data);
}
