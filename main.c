/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/24 11:33:10 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_bf(ac, av);
	if (!data)
		return (0);
	if (ft_is_order(data->a_heap))
		return (ft_free_heap_and_data(data));
	
	if (data->nb_numbers <= 4)
	{
		if (!ft_really_small_method(data))
			return (0);
	}
	else
	{
		if (!ft_radix_method(data))
			return (0);
	}
	//printf("a heap : \n");
	//ft_print_heap(data->a_heap);
	ft_free_end(data);

	return (0);
}

int	ft_radix_method(t_data *data)
{
	(void)data;
	ft_printf("aller, on commence");
	return (1);
}

int	ft_really_small_method(t_data *data)
{
	
	data->comb = ft_brut_force_a(data);
	if (!data->comb)
		return (ft_free_heap_and_data(data));
	ft_display_comb(data);
	free(data->comb);
	return (1);
}