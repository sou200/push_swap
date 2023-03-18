/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:50:00 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/02 19:56:26 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*sp;
	unsigned char		*dp;

	if (src >= dest)
		ft_memcpy(dest, src, n);
	else
	{
		sp = (const unsigned char *)(src + n - 1);
		dp = (unsigned char *)(dest + n - 1);
		while (n--)
			*dp-- = *sp--;
	}
	return (dest);
}
