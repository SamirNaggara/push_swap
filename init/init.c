/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:56:54 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 10:58:42 by snaggara         ###   ########.fr       */
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
	ft_memset(data->moves, 0, BUFFER);
	data->nb_move = 0;
	data->a_heap = ft_create_a_list(ac, av);
	if (!data->a_heap)
		return (((t_data *) 0));
	data->b_heap = (t_heap **)malloc(sizeof(t_heap *));
	if (!data->b_heap)
		return (((t_data *) 0));
	*(data->b_heap) = (t_heap *) 0;
	return (data);
}

/*
Créé la double liste chainée A au début !*/
t_heap	**ft_create_a_list(int ac, char **av)
{
	int		i;
	t_heap	**a_heap;

	i = 1;
	if (ac <= 1)
		ft_return_error();
	a_heap = (t_heap **)malloc(sizeof(t_heap *));
	*a_heap = (t_heap *) 0;
	while (i < ac)
	{
		ft_test_is_number(av[i]);
		ft_add_end_heap(a_heap, atoi(av[i]));
		i++;
	}
	return (a_heap);
}

/*
Vérifie qu'un nombre est un nombre*/
void	ft_test_is_number(char *nbc)
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
		ft_return_error();
	while (*nbc == '0')
		nbc++;
	i = 0;
	while (ft_isdigit(nbc[i]))
		i++;
	if (nbc[i])
		ft_return_error();
	if (ft_strlen(nbc) < 10)
		return ;
	if (sign == 1 && ft_strncmp(nbc, INT_MAX, 10) > 0)
		ft_return_error();
	if (sign == -1 && ft_strncmp(nbc, INT_MIN, 10) > 0)
		ft_return_error();
}
