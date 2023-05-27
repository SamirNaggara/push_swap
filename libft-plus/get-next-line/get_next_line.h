/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:29:30 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/07 17:39:16 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100 
# endif

typedef struct s_buffer
{
	char			*str;
	int				nb_octet;
	int				pos_n;
	struct s_buffer	*next;
}t_buffer;

char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
char		*all_buffer_concat(t_buffer **data_buffer, int total_octet);
void		cut_str(t_buffer *browse, char *memory);
int			read_once_more(t_buffer *browse, int fd);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
int			found_pos_char(const char *big, const char little);
t_buffer	**free_list(t_buffer **data_buffer, int what);
t_buffer	**init_and_first_read(int *nb_line, char *memory, int fd);

#endif
