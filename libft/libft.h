/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:56:49 by serhouni          #+#    #+#             */
/*   Updated: 2023/03/15 05:28:43 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_atoi(const char *nptr, int *status);
char	*ft_strtrim(char const *s1, char const *set);
int     ft_isdigit(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);