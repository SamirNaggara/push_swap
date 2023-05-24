/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:56:54 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/24 12:49:04 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*ft_init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return ((t_data *) 0);
	data->nb_numbers = ac - 1;
	data->nb_move = 0;
	data->a_heap = ft_create_a_list(ac, av, data);
	if (!data->a_heap)
		return (ft_free_data_tdata(data));
	data->b_heap = (t_heap **)malloc(sizeof(t_heap *));
	if (!data->b_heap)
		return (ft_free_a_data_tdata(data));
	*(data->b_heap) = (t_heap *) 0;
	ft_init_move_func(data);
	ft_init_move_func_rev(data);
	return (data);
}

/*
Créé la double liste chainée A au début !*/
t_heap	**ft_create_a_list(int ac, char **av, t_data *data)
{
	int		i;
	long		nb;

	i = 1;
	if (ac <= 1)
		ft_return_error();
	data->a_heap = (t_heap **)malloc(sizeof(t_heap *));
	if (!data->a_heap)
		return ((t_heap **)0);
	*(data->a_heap) = (t_heap *) 0;
	while (i < ac)
	{
		ft_test_is_number(av[i], data);
		if (data->nb_numbers <= 4)
			nb = atoi(av[i]);
		else
			nb = (long)atoi(av[i]) + (long)NB_MIN;
		if (ft_number_is_in_heap(data->a_heap, nb))
			ft_error_and_free_a(data);
		if (!ft_add_end_heap(data->a_heap, nb))
			return (ft_free_a_data_theap(data));
		i++;
	}
	return (data->a_heap);
}

void	ft_error_and_free_a(t_data *data)
{
	ft_del_all_heap(data->a_heap);
	free(data);
	ft_return_error();
}

/*
	Vérifie que le nombre est pas déjà présent dans la heap
*/
int	ft_number_is_in_heap(t_heap **heap, long nb)
{
	t_heap	*browse;
	int		first_lap;

	if (!heap || !*heap)
		return (0);
	first_lap = 1;
	browse = *heap;
	while (first_lap || browse != *heap)
	{
		if (first_lap)
			first_lap = 0;
		if (browse->nb == nb)
			return (1);
		browse = browse->next;
	}
	return (0);
}

/*
Vérifie qu'un nombre est un nombre*/
void	ft_test_is_number(char *nbc, t_data *data)
{
	int	i;
	int	sign;

	sign = 1;
	if (*nbc == '-' || *nbc == '+')
	{
		sign = -1;
		nbc++;
	}
	if (!*nbc)
		ft_error_and_free_a(data);
	while (*nbc == '0')
		nbc++;
	i = 0;
	while (ft_isdigit(nbc[i]))
		i++;
	if (nbc[i])
		ft_error_and_free_a(data);
	if (ft_strlen(nbc) < 10)
		return ;
	if (sign == 1 && ft_strncmp(nbc, INT_MAX, 10) > 0)
		ft_error_and_free_a(data);
	if (sign == -1 && ft_strncmp(nbc, INT_MIN, 10) > 0)
		ft_error_and_free_a(data);
}
