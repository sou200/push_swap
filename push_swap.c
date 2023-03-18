/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:06:53 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/18 01:24:01 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_data *data, t_stack *a, t_stack *b, t_stack *subseq)
{
	a->top = NULL;
	b->top = NULL;
	subseq->top = NULL;
	a->size = 0;
	b->size = 0;
	data->a = a;
	data->b = b;
	data->subseq = subseq;
}

// int	is_sorted(t_stack *stack)
// {
// 	t_node	*curr;
// 	int		pval;

// 	curr = stack->top;
// 	pval = curr->val;
// 	while (curr != NULL)
// 	{
// 		if (curr->val < pval)
// 			return (0);
// 		pval = curr->val;
// 		curr = curr->prev;
// 	}
// 	return (1);
// }

void f()
{
	system("leaks my_checker");
}

int main(int argc, char const *argv[])
{
    t_stack	a;
	t_stack	b;
	t_stack subseq;
	t_data	data;
	//atexit(f);
	t_node *node;
    init(&data, &a, &b, &subseq);
	parse(argc,argv,&data);
	node = data.a->top;
	while (node != NULL)
	{
		printf("%d ", node->val);
		node = node->prev;
	}
	printf("\n");
	lis(&data, data.a);
	push_lis(&data);
	node = data.a->top;
	while (node != NULL)
	{
		printf("%d ", node->val);
		node = node->prev;
	}
	printf("\n");
	node = data.b->top;
	while (node != NULL)
	{
		printf("%d ", node->val);
		node = node->prev;
	}
	printf("\n");
	node = data.subseq->top;
	while (node != NULL)
	{
		printf("%d ", node->val);
		node = node->prev;
	}
	printf("\n");
	term(&data);
    return 0;
}