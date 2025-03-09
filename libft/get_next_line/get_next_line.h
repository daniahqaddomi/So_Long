/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:26:36 by dqaddomi          #+#    #+#             */
/*   Updated: 2025/01/23 19:39:27 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_next(char *buffer);
char	*ft_extract_line(char *buffer);
char	*ft_read_file(int fd, char *buffer);
void	get_bzero(void *s, size_t n);
void	*get_calloc(size_t count, size_t size);
char	*get_strchr(const char *s, int c);
int		get_strlen(const char *s);
char	*get_strjoin(char *s1, char *s2);
char	*ft_read_loop(int fd, char *buffer, char *temp, int r);

#endif
