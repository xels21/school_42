/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshvydka <dshvydka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:14:08 by dshvydka          #+#    #+#             */
/*   Updated: 2024/12/10 15:27:08 by dshvydka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// finds 1st occurrence of the character c in the string s
char	*ft_strchr(const char *str, int chr)
{
	char	ch;

	ch = (char)chr;
	while (*str)
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == ch)
	{
		return ((char *)str);
	}
	return (NULL);
}

// returns length of string
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// allocates and returns a concat of s1&s2 as a new string
char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	size_t			total_size;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_size + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[total_size] = 0;
	return (res);
}

// allocates memory for an array of num elements of size bytes each.
// the memory is set to zero.
void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;

	ptr = malloc(size * num);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * num);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
