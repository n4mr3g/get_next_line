/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:32:55 by gpiccion          #+#    #+#             */
/*   Updated: 2022/06/11 23:39:23 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the number of bytes of the NUL-terminated string 'str'.
// Excludes the terminating null byte.
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Returns a pointer to the first occurrence of the char 'c' in 'str'.
// If no match is found, returns NULL.
char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i] && (char)str[i] != (char)c)
			i++;
		if ((char)str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (NULL);
}

// Allocates and returns a new string,
// which is the result of the concatenation of 's1' and 's2'. 
// Returns the new string, or NULL if the allocation fails. 
char	*ft_strjoin(char *s1, char *s2)
{
	char			*result;
	size_t			len1;
	size_t			len2;
	size_t			i;

	if (!s1)
		s1 = (char *)calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (*s2)
		result[i++] = *s2++;
	result[len1 + len2] = '\0';
	free(s1);
	return (result);
}
