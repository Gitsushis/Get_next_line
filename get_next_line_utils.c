/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:12:09 by cbouyer           #+#    #+#             */
/*   Updated: 2025/01/20 18:12:10 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Gives the length of the string*/
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*Joins, writes and mallocs two strings into a singular string*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_string[i + j] = s2[j];
		j++;
	}
	new_string[i + j] = '\0';
	return (new_string);
}

/*finds the substr in a string, used to find the strings after newline*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	j = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= j)
		len = 0;
	else if (len > j - start)
		len = j - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*Copies a string into a new string while using malloc*/

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*str2;

	i = 0;
	len = ft_strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
		return (NULL);
	while (i < len)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
