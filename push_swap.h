/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:15:57 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/07 18:40:41 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft-plus/libft/libft.h"
# include "libft-plus/printf/ft_printf.h"
# include <stdarg.h>
# include <string.h>

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"
# define NB_MAX 2147483647
# define NB_MIN 2147483648

typedef struct s_heap
{
	long			nb;
	int				is_improved;
	struct s_heap	*prev;
	struct s_heap	*next;
}	t_heap;

typedef struct s_data
{
	t_heap		**a_heap;
	t_heap		**b_heap;
	int			nb_numbers;
	int			nb_move;
	int			nb_comb;
	long		nb_max;
	long		nb_min;
	int			size_max;
	int			*comb;
	int			(*move_func[11])(struct s_data *);
	int			(*move_func_rev[11])(struct s_data *);
	float		*med;
}	t_data;

int				ft_really_small_method(t_data *data);
int				ft_return_error(t_data *data);
void			ft_test_is_number(char *nbc, t_data *data);
t_heap			**ft_create_a_list(int ac, char **av, t_data *data);
t_heap			**ft_add_end_heap(t_heap **heap, long nb);
t_heap			*ft_new_heap_element(long nb);
int				ft_sa(t_data *data);
int				ft_sb(t_data *data);
int				ft_ss(t_data *data);
int				ft_heap_empty_or_uniq(t_heap **heap);
t_heap			**ft_add_beg_heap(t_heap **heap, long nb);
void			ft_print_heap(t_heap **heap);
void			ft_print_heap_reverse(t_heap **heap);
int				ft_del_first_from_heap(t_heap **heap);
void			ft_del_last_from_heap(t_heap **heap);
void			ft_del_all_heap(t_heap **heap);
int				ft_pb(t_data *data);
int				ft_pa(t_data *data);
int				ft_ra(t_data *data);
int				ft_rb(t_data *data);
int				ft_rr(t_data *data);
int				ft_rra(t_data *data);
int				ft_rrb(t_data *data);
int				ft_rrr(t_data *data);
int				ft_is_order(t_heap	**heap);
t_data			*ft_init(int ac, char **av);
int				ft_free_end(t_data *data);
int				*ft_brut_force_a(t_data *data);
int				*ft_fb_a_with_n_possilities(t_data *data, int *comb, int n);
int				ft_test_combinaison_a(int *comb, t_data *data, int n, int len);
int				ft_increment_comb(int *comb, int n);
void			ft_reverse_combinaison(int *comb, t_data *data, int n);
int				ft_is_empty(t_heap **heap);
void			ft_display_comb(t_data *data);
void			ft_display_comb_2(t_data *data, int i);
int				ft_increment_more(int *comb, int n);
int				ft_size_heap(t_heap **heap);
int				ft_double_brute_force(t_data *data);
float			*ft_mediane(t_heap **heap);
float			*ft_mediane_from_tab(int *ordered_int, int size);
int				ft_extract_smaller(t_heap **heap, int nb);
long			ft_nb_max(long a, long b);
long			ft_nb_min(long a, long b);
int				*ft_push_above_mediane(t_data *data, int n);
void			ft_add_move(t_data *data, const char *name);
void			ft_display_this_comb(int *comb, int n);
void			ft_init_move_func(t_data *data);
void			ft_init_move_func_rev(t_data *data);
int				ft_free_data(t_data *data);
t_data			*ft_free_data_tdata(t_data *data);
int				ft_free_heap_and_data(t_data *data);
t_data			*ft_free_a_data_tdata(t_data *data);
int				ft_number_is_in_heap(t_heap **a_heap, long nb);
void			ft_error_and_free_a(t_data *data);
t_heap			**ft_free_a_data_theap(t_data *data);
/* RADIX METHOD*/
int				ft_radix_method(t_data *data);
unsigned long	ft_int_to_unsigned_int(int nb);
long			ft_get_nb_max_from_a(t_data *data);
int				ft_size_binary(unsigned long nb);
int				ft_get_comb_nb_radix(t_data *data);
int				ft_get_comb_length(long nb, int size_max);
int				ft_radix_sort(t_data *data);
int				ft_push_all_b_in_a(t_data *data, int k);
void			ft_radix_one_bit(t_data *data, int i, int k);
long			ft_get_nb_min_from_a(t_data *data);
void			ft_iter_a(t_data *data);
void			ft_optimize_a(t_data *data);
int				ft_replace_min_by_k(t_data *data, long min, int k);
int				ft_extract_smaller_improved(t_heap **heap, int nb);

#endif
