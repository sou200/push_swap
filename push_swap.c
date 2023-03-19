/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:06:53 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 04:16:22 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_data *data, t_stack *a, t_stack *b, t_stack *subseq)
{
	a->top = NULL;
	b->top = NULL;
	subseq->top = NULL;
	data->sub_len = NULL;
	data->sub_indexes = NULL;
	a->size = 0;
	b->size = 0;
	subseq->size = 0;
	data->a = a;
	data->b = b;
	data->subseq = subseq;
}

void	f(void)
{
	system("leaks a.out");
}

void	printstack(t_data *data)
{
	t_node	*anode;
	t_node	*bnode;

	anode = data->a->top;
	bnode = data->b->top;
	while (anode != NULL || bnode != NULL)
	{
		if (anode != NULL)
		{
			printf("% 3d ", anode->val);
			anode = anode->prev;
		}
		if (bnode != NULL)
		{
			printf("% 3d % 3d", bnode->val, bnode->moves);
			bnode = bnode->prev;
		}
		printf("\n");
	}
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;
	t_stack	subseq;
	t_data	data;
	//atexit(f);
	init(&data, &a, &b, &subseq);
	parse(argc, argv, &data);
	sort(&data);
	term(&data);
	return (0);
}
