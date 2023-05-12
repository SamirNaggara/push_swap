/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:15:57 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/12 22:54:58 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libs/ft_printf.h"
# include "libs/libft.h"
# include <stdarg.h>
# include <string.h>

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

typedef struct s_heap
{
	int             *number;
	struct s_heap    *prev;
	struct s_heap    *next;
}   t_heap;

int     returnError();
void    ft_test_is_number(char *nbc);
int ft_create_A_list(int ac, char **av);



#endif
