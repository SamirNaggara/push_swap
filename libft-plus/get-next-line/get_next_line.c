/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:12:14 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/07 18:05:22 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int			nb_line;
	t_buffer			**data_buffer;
	t_buffer			*browse;
	char				*to_return;
	static char			memory[BUFFER_SIZE + 1];

	data_buffer = init_and_first_read(&nb_line, memory, fd);
	if (!data_buffer)
		return (NULL);
	(*data_buffer)->pos_n = found_pos_char((*data_buffer)->str, '\n');
	browse = *data_buffer;
	while (browse->pos_n == -1 && read_once_more(browse, fd))
		browse = browse->next;
	if (browse->pos_n != -1)
		cut_str(browse, memory);
	else
		nb_line = -1;
	to_return = all_buffer_concat(data_buffer, browse->nb_octet);
	if (!to_return)
		return (NULL);
	browse = *data_buffer;
	free_list(data_buffer, 0);
	return (to_return);
}

t_buffer	**init_and_first_read(int *nb_line, char *memory, int fd)
{
	t_buffer	**data_buffer;

	if (++(*nb_line) == 0)
		return ((t_buffer **)0);
	data_buffer = (t_buffer **)malloc(sizeof(t_buffer *));
	*data_buffer = (t_buffer *)malloc(sizeof(t_buffer));
	(*data_buffer)->next = NULL;
	(*data_buffer)->str = (char *)malloc(sizeof(char) * ((BUFFER_SIZE + 1)));
	if (!(*data_buffer)->str)
		return ((t_buffer **)0);
	ft_memset((*data_buffer)->str, 0, BUFFER_SIZE + 1);
	if (*nb_line == 1 || (!*memory))
	{
		(*data_buffer)->nb_octet = read(fd, (*data_buffer)->str, BUFFER_SIZE);
		if ((*data_buffer)->nb_octet == 0 || (*data_buffer)->nb_octet == -1)
			return (free_list(data_buffer, 1));
	}
	else
	{
		(*data_buffer)->nb_octet = ft_strlen(memory);
		free((*data_buffer)->str);
		(*data_buffer)->str = ft_strdup(memory);
	}
	ft_memset(memory, 0, BUFFER_SIZE + 1);
	return (data_buffer);
}

t_buffer	**free_list(t_buffer **data_buffer, int what)
{
	t_buffer	*browse;
	t_buffer	*browse_next;

	if (what == 0)
	{
		browse = *data_buffer;
		browse_next = browse->next;
		while (browse_next)
		{
			free(browse->str);
			free(browse);
			browse = browse_next;
			browse_next = browse->next;
		}
		free(browse->str);
		free(browse);
		free(data_buffer);
	}
	else if (what == 1)
	{
		free((*data_buffer)->str);
		free(*data_buffer);
		free(data_buffer);
	}
	return ((t_buffer **)0);
}

char	*all_buffer_concat(t_buffer **data_buffer, int total_octet)
{
	char		*to_return;
	t_buffer	*browse;
	size_t		i;
	size_t		j;

	browse = *data_buffer;
	i = 0;
	to_return = (char *)malloc(sizeof(char) * (total_octet + 1));
	if (!to_return)
		return (NULL);
	while (browse)
	{
		j = 0;
		while (browse->str[j])
		{
			to_return[i] = browse->str[j];
			i++;
			j++;
		}
		if (browse->pos_n != -1)
			to_return[i++] = '\n';
		browse = browse->next;
	}
	to_return[i] = '\0';
	return (to_return);
}

void	cut_str(t_buffer *browse, char *memory)
{
	int	i;

	browse->str[browse->pos_n] = '\0';
	i = 0;
	while (browse->str[browse->pos_n + i + 1])
	{
		memory[i] = browse->str[browse->pos_n + i + 1];
		i++;
	}
	memory[i] = '\0';
}
