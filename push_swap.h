/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:15:57 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 10:40:41 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libs/ft_printf.h"
# include "libs/libft.h"
# include <stdarg.h>
# include <string.h>

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"
# define BUFFER 4096

typedef struct s_heap
{
	int				nb;
	struct s_heap	*prev;
	struct s_heap	*next;
}	t_heap;

typedef struct s_data
{
	t_heap	**a_heap;
	t_heap	**b_heap;
	int		nb_move;
	char	moves[BUFFER];
}	t_data;

int		ft_return_error(void);
void	ft_test_is_number(char *nbc);
t_heap	**ft_create_a_list(int ac, char **av);
t_heap	**ft_add_end_heap(t_heap **heap, int nb);
t_heap	*ft_new_heap_element(int nb);
void	ft_sa(t_data *data);
void	ft_sb(t_data *data);
void	ft_ss(t_data *data);
int		ft_heap_empty_or_uniq(t_heap **heap);
t_heap	**ft_add_beg_heap(t_heap **heap, int nb);
void	ft_print_heap(t_heap **heap);
void	ft_print_heap_reverse(t_heap **heap);
void	ft_del_first_from_heap(t_heap **heap);
void	ft_del_last_from_heap(t_heap **heap);
void	ft_del_all_heap(t_heap **heap);
void	ft_add_move(t_data *data, const char *name);
void	ft_pb(t_data *data);
void	ft_pa(t_data *data);
void	ft_ra(t_data *data);
void	ft_rb(t_data *data);
void	ft_rr(t_data *data);
void	ft_rra(t_data *data);
void	ft_rrb(t_data *data);
void	ft_rrr(t_data *data);
int		ft_is_order(t_heap	**heap);
t_data	*ft_init(int ac, char **av);
int	ft_free_end(t_data *data);

#endif
