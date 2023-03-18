/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_do_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:13:34 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/16 03:03:38 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <string.h>

static int ft_strcmp(const char *a, const char *b)
{
    int i;

    i = 0;
    while (a[i] != '\0')
    {
        if (a[i] != b[i])
            break;
        i++;
    }
    return a[i] - b[i];
}

static int is_valid_inst(char *move)
{
    if(!ft_strcmp("sa\n", move) || !ft_strcmp("sb\n", move))
        return 1;
    else if (!ft_strcmp("pa\n", move) || !ft_strcmp("pb\n", move))
        return 1;
    else if (!ft_strcmp("ra\n", move) || !ft_strcmp("rb\n", move))
        return 1;
    else if (!ft_strcmp("ss\n", move) || !ft_strcmp("rr\n", move))
        return 1;
    else if (!ft_strcmp("rra\n", move) || !ft_strcmp("rrb\n", move))
        return 1;
    else if(!ft_strcmp("rrr\n", move))
        return 1;
    return 0;
}

static void do_the_move(t_data *data, char *move)
{
    if(!ft_strcmp("sa\n", move))
        sa(data);
    else if(!ft_strcmp("sb\n", move))
        sb(data);
    else if(!ft_strcmp("ss\n", move))
        ss(data);
    else if(!ft_strcmp("pa\n", move))
        pa(data);
    else if(!ft_strcmp("pb\n", move))
        pb(data);
    else if(!ft_strcmp("ra\n", move))
        ra(data);
    else if(!ft_strcmp("rb\n", move))
        rb(data);
    else if(!ft_strcmp("rr\n", move))
        rr(data);
    else if(!ft_strcmp("rra\n", move))
        rra(data);
    else if(!ft_strcmp("rrb\n", move))
        rrb(data);
    else if(!ft_strcmp("rrr\n", move))
        rrr(data);
}

void read_and_move(t_data *data)
{
    char *move;

    move = get_next_line(STDIN_FILENO);
    while (move != NULL)
    {
        if(is_valid_inst(move))
            do_the_move(data, move);
        else
            exit_err_msg(ERR_MSG, data);
        free(move);
        move = get_next_line(STDIN_FILENO);
    }
}