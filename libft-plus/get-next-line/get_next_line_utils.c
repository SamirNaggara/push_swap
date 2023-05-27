/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:22:25 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/06 16:19:58 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_memset(result, 0, size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*sbis;

	sbis = (char *)s;
	i = 0;
	while (i < n)
	{
		sbis[i] = c;
		i++;
	}
	return (sbis);
}

int	found_pos_char(const char *big, const char little)
{
	size_t	i;

	if (!big || !*big)
		return (-1);
	i = 0;
	while (big[i] && big[i] != little)
		i++;
	if (big[i] == little)
		return ((int)i);
	return (-1);
}

int	read_once_more(t_buffer *browse, int fd)
{
	t_buffer	*new_data_buffer;
	int			nb_octet;
	char		*the_read;

	the_read = (char *)malloc(sizeof(char) * ((BUFFER_SIZE + 1)));
	if (!the_read)
		return (0);
	ft_memset(the_read, 0, BUFFER_SIZE + 1);
	nb_octet = read(fd, the_read, BUFFER_SIZE);
	if (!nb_octet || nb_octet == -1)
	{
		free(the_read);
		return (0);
	}
	new_data_buffer = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new_data_buffer)
		return (0);
	new_data_buffer->next = NULL;
	new_data_buffer->str = the_read;
	new_data_buffer->pos_n = found_pos_char(new_data_buffer->str, '\n');
	browse->next = new_data_buffer;
	new_data_buffer->nb_octet = browse->nb_octet + nb_octet + 1;
	return (1);
}
