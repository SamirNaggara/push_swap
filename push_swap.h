/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:15:57 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 14:58:45 by snaggara         ###   ########.fr       */
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
	int		nb_numbers;
	int		nb_move;
	int		nb_comb;
	int		*comb;
	int		(*move_func[11])(struct s_data *);
	int		(*move_func_rev[11])(struct s_data *);
	float	*med;
}	t_data;

int		ft_return_error(void);
void	ft_test_is_number(char *nbc);
t_heap	**ft_create_a_list(int ac, char **av);
t_heap	**ft_add_end_heap(t_heap **heap, int nb);
t_heap	*ft_new_heap_element(int nb);
int		ft_sa(t_data *data);
int		ft_sb(t_data *data);
int		ft_ss(t_data *data);
int		ft_heap_empty_or_uniq(t_heap **heap);
t_heap	**ft_add_beg_heap(t_heap **heap, int nb);
void	ft_print_heap(t_heap **heap);
void	ft_print_heap_reverse(t_heap **heap);
int		ft_del_first_from_heap(t_heap **heap);
void	ft_del_last_from_heap(t_heap **heap);
void	ft_del_all_heap(t_heap **heap);
int		ft_pb(t_data *data);
int		ft_pa(t_data *data);
int		ft_ra(t_data *data);
int		ft_rb(t_data *data);
int		ft_rr(t_data *data);
int		ft_rra(t_data *data);
int		ft_rrb(t_data *data);
int		ft_rrr(t_data *data);
int		ft_is_order(t_heap	**heap);
t_data	*ft_init(int ac, char **av);
int		ft_free_end(t_data *data);
int		*ft_brut_force_a(t_data *data);
int		*ft_fb_a_with_n_possilities(t_data *data, int *comb, int n);
int		ft_test_combinaison_a(int *comb, t_data *data, int n, int len);
int		ft_increment_comb(int *comb, int n);
void	ft_reverse_combinaison(int *comb, t_data *data, int n);
int		ft_is_empty(t_heap **heap);
void	ft_display_comb(t_data *data);
void	ft_display_comb_2(t_data *data, int i);
int		ft_increment_more(int *comb, int n);
int		ft_size_heap(t_heap **heap);
int		ft_double_brute_force(t_data *data);
float	*ft_mediane(t_heap **heap);
float	*ft_mediane_from_tab(int *ordered_int, int size);
int		ft_extract_smaller(t_heap **heap, int nb);
int		ft_nb_max(int a, int b);
int		ft_nb_min(int a, int b);
int		*ft_push_above_mediane(t_data *data, int n);
void	ft_add_move(t_data *data, const char *name);
void	ft_display_this_comb(int *comb, int n);
void	ft_init_move_func(t_data *data);
void	ft_init_move_func_rev(t_data *data);
int		ft_free_data(t_data *data);
t_data	*ft_free_data_tdata(t_data *data);
int		ft_free_heap_and_data(t_data *data);
t_data	*ft_free_a_data_tdata(t_data *data);

#endif
