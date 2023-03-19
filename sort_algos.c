/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:39:20 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/18 23:48:25 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ultra_lite_sort(t_data *data)
{
    if(data->a->top->val == data->a->max)
        ra(data, 1);
    else if(data->a->top->prev->val == data->a->max)
        rra(data, 1);
    
    if(data->a->top->val > data->a->top->prev->val)
        sa(data, 1);
}

void				lite_sort(t_data *data)
{
    while (data->a->size > 3)
    {
        
    }
    
}

void    lovely_sort(t_data *data)
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