/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:06:53 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 11:42:56 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init(t_data *data, t_stack *a, t_stack *b)
{
	a->top = NULL;
	b->top = NULL;
	a->size = 0;
	b->size = 0;
	data->a = a;
	data->b = b;
}

int	is_sorted(t_stack *stack)
{
	t_node	*curr;
	int		pval;

	curr = stack->top;
	if (curr == NULL)
		return (0);
	pval = curr->val;
	while (curr != NULL)
	{
		if (curr->val < pval)
			return (0);
		pval = curr->val;
		curr = curr->prev;
	}
	return (1);
}

void	check_sort(t_stack *stack)
{
	if (is_sorted(stack))
		ft_putstr_fd(OK_MSG, STDOUT_FILENO);
	else
		ft_putstr_fd(KO_MSG, STDOUT_FILENO);
}

void	f(void)
{
	system("leaks my_checker");
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;
	t_data	data;

	//atexit(f);
	init(&data, &a, &b);
	parse(argc, argv, &data);
	read_and_move(&data);
	check_sort(data.a);
	term(&data);
	return (0);
}
