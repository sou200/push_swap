/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:15:37 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/17 21:28:46 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
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
	t_stack			*subseq;
	int				*sub_len;
	int				*sub_indexes;
}					t_data;

t_node				*get_first_node(t_stack *stack);
void				push_node(t_stack *stack, t_node *node);
void				add_at_first(t_stack *stack, t_node *node);
t_node				*new_node(int val);
void				indexing(t_stack *stack);

void				pa(t_data *data, int print);
void				pb(t_data *data, int print);
void				sa(t_data *data, int print);
void				sb(t_data *data, int print);
void				ss(t_data *data, int print);
void				ra(t_data *data, int print);
void				rb(t_data *data, int print);
void				rr(t_data *data, int print);
void				rra(t_data *data, int print);
void				rrb(t_data *data, int print);
void				rrr(t_data *data, int print);

void				init(t_data *data, t_stack *a, t_stack *b, t_stack *subseq);
void				parse(int argc, const char *argv[], t_data *data);
int					check_dup(int val, t_data *data);
void				exit_err_msg(char *msg, t_data *data);
void				free_two_d(char **twod);
void				free_stack(t_stack *stack);
void				term(t_data *data);

# define ERR_MSG "Error.\n"

void				lis(t_data *data, t_stack *stack);
void				push_lis(t_data *data);

void				set_moves(t_data *data);
void				do_the_best_move(t_data *data);
void				iter_move(t_data *data, void (*move)(t_data *, int), int n,
						int print);
void				multi_rot(t_data *data);
int					max(int a, int b);
int					min(int a, int b);
t_node				*get_node_to_elevate(t_data *data, t_node *bnode);
void				calc_move(t_data *data, t_node *anode, t_node *bnode);
int					valid_move(t_data *data, t_node *anode, t_node *bnode);
int					is_sorted(t_stack *stack);
void				sort(t_data *data);

void				ultra_lite_sort(t_data *data);
void				lite_sort(t_data *data);
void				lovely_sort(t_data *data);

#endif
