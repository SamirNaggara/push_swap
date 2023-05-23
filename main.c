/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 15:09:40 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_init(ac, av);
	if (!data)
		return (0);
	if (ft_is_order(data->a_heap))
		return (ft_free_heap_and_data(data));
	if (data->nb_numbers <= 4)
	{
		data->comb = ft_brut_force_a(data);
		if (!data->comb)
			return (ft_free_heap_and_data(data));
		ft_display_comb(data);
		free(data->comb);
	}
	else if (data->nb_numbers <= 10)
	{
		ft_free_end(data);
		ft_return_error();
	}
	else
	{
		ft_free_end(data);
		ft_return_error();
	}
	//printf("a heap : \n");
	//ft_print_heap(data->a_heap);
	ft_free_end(data);
	return (0);
}
