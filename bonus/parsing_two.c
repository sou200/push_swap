/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:10:25 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/15 03:52:57 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_dup(int val, t_data *data)
{
	t_node	*nodepoint;

	nodepoint = data->a->top;
	while (nodepoint != NULL)
	{
		if (nodepoint->val == val)
			return (1);
		nodepoint = nodepoint->prev;
	}
	return (0);
}
