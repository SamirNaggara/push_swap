/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 14:38:01 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_radix_method(t_data *data)
{
	data->nb_min = ft_get_nb_min_from_a(data);
	ft_optimize_a(data);
	data->nb_max = ft_get_nb_max_from_a(data);
	if (!ft_radix_sort(data))
		return (0);
	ft_display_comb(data);
	free(data->comb);
	return (1);
}

int	ft_radix_sort(t_data *data)
{
	int		i;
	int		j;
	int		k;

	data->size_max = ft_size_binary(data->nb_max);
	data->nb_comb = ft_get_comb_nb_radix(data);
	data->comb = (int *)malloc(sizeof(int) * (data->nb_comb));
	if (!data->comb)
		return (0);
	i = 0;
	k = 0;
	while (i < data->size_max)
	{
		j = 0;
		while (j < data->nb_numbers)
		{
			ft_radix_one_bit(data, i, k);
			j++;
			k++;
		}
		k = ft_push_all_b_in_a(data, k);
		i++;
	}
	return (1);
}
