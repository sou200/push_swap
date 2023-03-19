/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:07:05 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 05:48:38 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

typedef struct s_node
{
	int				val;
	int				index;
	int				moves;
	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	int				size;
	int				max;
	int				min;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
}					t_data;

# define ERR_MSG "Error\n"
# define OK_MSG "OK\n"
# define KO_MSG "KO\n"

void				parse(int argc, const char *argv[], t_data *data);
void				init(t_data *data, t_stack *a, t_stack *b);
int					check_dup(int val, t_data *data);

void				pa(t_data *data);
void				pb(t_data *data);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);

void				free_stack(t_stack *stack);
void				free_two_d(char **twod);
void				term(t_data *data);
void				exit_err_msg(char *msg, t_data *data);
void				read_and_move(t_data *data);

void				add_at_first(t_stack *stack, t_node *node);
void				push_node(t_stack *stack, t_node *node);
t_node				*get_first_node(t_stack *stack);
t_node				*new_node(int val);

#endif
