/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:52:50 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 11:40:24 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*sp;
	unsigned char		*dp;

	if (src == dest)
		return (dest);
	i = 0;
	sp = (const unsigned char *)src;
	dp = (unsigned char *)dest;
	while (i < n)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dest);
}
