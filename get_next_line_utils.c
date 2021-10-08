/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:05:14 by piboidin          #+#    #+#             */
/*   Updated: 2021/10/08 12:24:40 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *next_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!next_str)
	{
		next_str = (char *)malloc(1 * sizeof(char));
		next_str[0] = '\0';
	}
	if (!next_str || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(next_str) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (next_str)
		while (next_str[++i] != '\0')
			str[i] = next_str[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(next_str) + ft_strlen(buffer)] = '\0';
	free(next_str);
	return (str);
}