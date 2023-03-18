/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnkd_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:59:16 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/17 21:51:42 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *stack)
{
	t_node	*curr;
	int		i;

	curr = stack->top;
	i = 0;
	if (curr != NULL)
	{
		stack->max = curr->val;
		stack->min = curr->val;
	}
	while (curr != NULL)
	{
		if (curr->val > stack->max)
			stack->max = curr->val;
		if (curr->val < stack->min)
			stack->min = curr->val;
		curr->index = i++;
		curr = curr->prev;
	}
}

void	add_at_first(t_stack *stack, t_node *node)
{
	t_node	*fnode;

	if (stack->top == NULL)
	{
		node->next = NULL;
		stack->top = node;
		node->index = 0;
	}
	else
	{
		fnode = get_first_node(stack);
		node->next = fnode;
		node->index = fnode->index + 1;
		fnode->prev = node;
	}
	node->prev = NULL;
	stack->size++;
}

void	push_node(t_stack *stack, t_node *node)
{
	if (stack->top == NULL)
	{
		node->prev = NULL;
		stack->top = node;
		node->index = 0;
	}
	else
	{
		node->prev = stack->top;
		stack->top->next = node;
		stack->top = node;
		indexing(stack);
	}
	node->next = NULL;
	stack->size++;
}

t_node	*get_first_node(t_stack *stack)
{
	t_node	*currnode;

	currnode = stack->top;
	while (currnode != NULL)
	{
		if (currnode->prev == NULL)
			return (currnode);
		currnode = currnode->prev;
	}
	return (NULL);
}

t_node	*new_node(int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->val = val;
	return (node);
}
