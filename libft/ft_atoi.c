/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:07:01 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/15 03:43:04 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

static void	preatoi(int *sign, const char *nptr, int *i)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == ' ')
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr, int *status)
{
	int			result;
	int			presult;
	int			sign;
	int			i;

	i = 0;
	result = 0;
	*status = 0;
	sign = 1;
	preatoi(&sign, nptr, &i);
	while (ft_isdigit(nptr[i]))
	{
		presult = result;
		result = result * 10 + nptr[i] - '0';
		if ((result / 10) != presult)
		{
			*status = 1;
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (sign * result);
}