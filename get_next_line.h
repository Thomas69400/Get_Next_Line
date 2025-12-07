/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:14:23 by tchemin           #+#    #+#             */
/*   Updated: 2025/11/26 18:04:05 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_bzero(char *s, size_t n);
int		ft_memmove(char *dest, char *buf, size_t n);
void	copy(char *dest, char *src, int to_n);
size_t	ft_len_to_n(char *s, int find_n);
char	*get_complete_line(char *buf, int *bytes, int fd, int *trigger);
int		got_n(char *s);
char	*join(char *s, char *buf);
int		is_end_of_file(int bytes, int *trigger);

#endif