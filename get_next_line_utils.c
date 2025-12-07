/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:14:02 by tchemin           #+#    #+#             */
/*   Updated: 2025/11/24 14:48:20 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy(char *dest, char *src, int to_n)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (src[i] == '\n' && to_n)
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	if (n == 0 || !s)
		return ;
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

size_t	ft_len_to_n(char *s, int find_n)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && find_n)
			return (i);
		i++;
	}
	return (i);
}

int	got_n(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_end_of_file(int bytes, int *trigger)
{
	if (bytes < BUFFER_SIZE || bytes == 0)
	{
		*trigger = 1;
		return (1);
	}
	return (0);
}
