/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:11:19 by gpiccion          #+#    #+#             */
/*   Updated: 2022/06/22 21:23:51 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Reads from file descriptor 'fd' (in iterations of BUFFER_SIZE) until finding
// a newline character or EOF.
// Returns the string read, or NULL if the file descriptor is closed or an error
// occurs.
char	*read_file(int fd, char *buff)
{
	char	*tmp;
	int		ret;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	ret = 1;
	while (!ft_strchr(buff, '\n') && ret > 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[ret] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	free(tmp);
	return (buff);
}

// Reads the string 'buff' and returns the first line found.
char	*get_line(char *buff)
{
	int		i;
	char	*line;

	if (!buff[0])
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// Reads the string 'buff' and returns the last part,
// starting from the first newline character found.
char	*get_remain(char *buff)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	remain = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!remain)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		remain[j++] = buff[i++];
	remain[j] = '\0';
	free(buff);
	return (remain);
}

// Reads one line from the file descriptor 'fd' and returns it.
// Consequent calls to this function will return the next line
// from each corresponding file descriptor.
char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = get_line(buff[fd]);
	buff[fd] = get_remain(buff[fd]);
	return (line);
}
