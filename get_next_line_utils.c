/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:07:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/14 16:13:11 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) + start) < len)
		len = ft_strlen(s) + start;
	substr = malloc(sizeof(*s) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) + start) < len)
		len = ft_strlen(s) + start;
	substr = malloc(sizeof(*s) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	free(s);
	return (substr);
}

int	lf_count(char *str)
{
	int	position;

	position = 0;
	while (str[position])
	{
		if (str[position] == '\n')
		{
			return (position);
		}
		position++;
	}
	return (-1);
}
