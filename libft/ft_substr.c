/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:24:49 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 11:40:50 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getalloclen(size_t slen, unsigned int start, size_t len)
{
	size_t	flen;

	flen = 0;
	while ((start + flen) < slen && flen < len)
		flen++;
	return (flen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	sl;
	size_t	flen;

	if (s == 0)
		return (0);
	sl = ft_strlen(s);
	flen = getalloclen(sl, start, len);
	p = (char *)malloc((flen + 1) * sizeof(char));
	if (p == 0)
		return (0);
	ft_memmove(p, (s + start), flen);
	p[flen] = '\0';
	return (p);
}
