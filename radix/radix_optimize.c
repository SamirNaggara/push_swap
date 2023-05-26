/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_optimize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:28:23 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 15:09:08 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_optimize_a(t_data *data)
{
	int		i;
	int		k;
	long	min;

	i = 0;
	k = 0;
	while (i < data->nb_numbers)
	{
		if (i == 0)
			min = ft_extract_smaller_improved(data->a_heap, -1 * NB_MIN);
		else
			min = ft_extract_smaller_improved(data->a_heap, min + 1);
		ft_replace_min_by_k(data, min, k);
		k++;
		i++;
	}
}

int	ft_extract_smaller_improved(t_heap **heap, int nb)
{
	int		smaller;
	int		first_lap;
	t_heap	*browse;

	first_lap = 1;
	browse = *heap;
	while (first_lap || browse != *heap)
	{
		if (browse->nb < nb || browse->is_improved)
		{
			browse = browse->next;
			continue ;
		}
		if (first_lap)
		{
			smaller = browse->nb;
			browse = browse->next;
			first_lap = 0;
			continue ;
		}
		smaller = ft_nb_min(smaller, browse->nb);
		browse = browse->next;
	}
	return (smaller);
}

int	ft_replace_min_by_k(t_data *data, long min, int k)
{
	int		first_lap;
	t_heap	*browse;

	first_lap = 1;
	browse = *(data->a_heap);
	while (first_lap || browse != *(data->a_heap))
	{
		if (first_lap)
			first_lap = 0;
		if (browse->nb == min && !browse->is_improved)
		{
			browse->nb = k;
			browse->is_improved = 1;
			return (1);
		}
		browse = browse->next;
	}
	return (0);
}

void	ft_iter_a(t_data *data)
{
	int		first_lap;
	t_heap	*browse;

	first_lap = 1;
	browse = *(data->a_heap);
	while (first_lap || browse != *(data->a_heap))
	{
		if (first_lap)
			first_lap = 0;
		browse->nb += (data->nb_min) * -1 + 1;
		browse = browse->next;
	}
}
