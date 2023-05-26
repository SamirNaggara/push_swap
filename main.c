/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 15:05:18 by snaggara         ###   ########.fr       */
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
	if (data->nb_numbers <= 5)
	{
		if (!ft_really_small_method(data))
			return (0);
	}
	else
	{
		if (!ft_radix_method(data))
			return (0);
	}
	ft_free_end(data);
	return (0);
}
