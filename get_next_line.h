/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:32:57 by gpiccion          #+#    #+#             */
/*   Updated: 2022/06/20 18:23:59 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

// Reads one line from the file descriptor 'fd' and returns it.
// Consequent calls to this function will return the next line
// from the file descriptor 'fd'.
char	*get_next_line(int fd);

// Reads from file descriptor 'fd' (in iterations of BUFFER_SIZE) until finding
// a newline character or EOF.
// Returns the string read, or NULL if the file descriptor is closed or an error
// occurs.
char	*read_file(int fd, char *buff);

// Reads a line from a file descriptor.
char	*get_line(char *buff);

// Reads the string 'buff' and returns the last part,
// starting from the first newline character found.
char	*get_remain(char *buff);

// Returns the number of bytes of the NUL-terminated string 'str'.
// Excludes the terminating null byte.
size_t	ft_strlen(const char *str);

// Allocates and returns a new string,
// which is the result of the concatenation of 's1' and 's2'. 
// Returns the new string, or NULL if the allocation fails. 
char	*ft_strjoin(char *s1, char *s2);

// Returns a pointer to the first occurrence of the char 'c' in 'str'.
// If no match is found, returns NULL.
char	*ft_strchr(const char *str, int c);

#endif