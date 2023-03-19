/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:21:05 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/19 11:40:35 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **worlds, int index)
{
	while (index >= 0)
	{
		free(worlds[index]);
		index--;
	}
	free(worlds);
}

static int	getlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			len++;
			s++;
		}
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	return (len);
}

static char	*getword(char **s, char c)
{
	int		wordlen;
	char	*word;
	int		i;

	wordlen = 0;
	while ((*s)[wordlen] != c && (*s)[wordlen] != '\0')
		wordlen++;
	i = 0;
	word = ft_substr(*s, 0, wordlen);
	if (word == 0)
		return (0);
	while (i < wordlen)
	{
		word[i] = **s;
		(*s)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fillresult(char **res, char *s, char c, int sl)
{
	char	*word;
	int		i;

	i = 0;
	while (i < sl)
	{
		word = getword(&s, c);
		if (word == 0)
		{
			freeall(res, i - 1);
			return (0);
		}
		res[i] = word;
		i++;
		while (*s == c)
			s++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	*trimed;
	char	**result;
	int		i;
	int		sl;

	if (s == 0)
		return (0);
	trimed = ft_strtrim(s, (char []){c, '\0'});
	if (trimed == 0)
		return (0);
	sl = getlen(trimed, c);
	i = 0;
	result = (char **)malloc((sl + 1) * sizeof(char *));
	if (result == 0)
	{
		free(trimed);
		return (0);
	}
	result = fillresult(result, trimed, c, sl);
	free(trimed);
	if (result == 0)
		return (0);
	return (result);
}
