/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:31:34 by daniah            #+#    #+#             */
/*   Updated: 2025/01/23 19:39:27 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*get_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}

char	*get_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	i = 0;
	size = get_strlen(s1) + get_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str || !s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[size] = 0;
	free(s1);
	return (str);
}

void	*get_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*p;

	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
		get_bzero(p, b);
	return (p);
}

void	get_bzero(void *s, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *)s;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}
