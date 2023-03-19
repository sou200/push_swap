/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:42:48 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 11:39:48 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getstart(char const *s, char const *set, int setlen)
{
	int	start;
	int	found;
	int	i;

	start = 0;
	found = 1;
	while (found)
	{
		i = 0;
		found = 0;
		while (i < setlen)
		{
			if (s[start] == set[i])
			{
				found = 1;
				start++;
				break ;
			}
			i++;
		}
	}
	return (start);
}

static int	getend(char const *s, char const *set, int setlen, int slen)
{
	int	end;
	int	found;
	int	start;
	int	i;

	end = slen - 1;
	found = 1;
	start = getstart(s, set, setlen);
	while (found && end >= start)
	{
		i = 0;
		found = 0;
		while (i < setlen)
		{
			if (s[end] == set[i])
			{
				found = 1;
				end--;
				break ;
			}
			i++;
		}
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;
	int		setlen;

	if (s1 == 0 || set == 0)
		return (0);
	setlen = ft_strlen(set);
	start = getstart(s1, set, setlen);
	end = getend(s1, set, setlen, ft_strlen(s1));
	p = ft_substr(s1, start, end - start + 1);
	if (p == 0)
		return (0);
	return (p);
}
