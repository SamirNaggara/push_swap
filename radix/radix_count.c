/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:32:23 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 15:10:31 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	En fait pour un nombre, a chaque fois qu'il y a un 0 il
	va etre déplacé de 1 (genre juste on le passe quoi, avec ra)
	Ou alors il va etre déplacé de 2 (pb, puis pa)
	Donc là on calcul pour 1 nombre combien de déplacement il va 
	neccessiter
*/
int	ft_get_comb_length(long nb, int size_max)
{
	int		i;
	int		local_nb_move;

	local_nb_move = 0;
	i = 0;
	while (i < size_max)
	{
		if (((nb >> i) & 1) == 1)
			local_nb_move++;
		else
			local_nb_move += 2;
		i++;
	}
	return (local_nb_move);
}

long	ft_get_nb_max_from_a(t_data *data)
{
	long	bigger;
	int		first_lap;
	t_heap	*browse;

	first_lap = 1;
	browse = *(data->a_heap);
	while (first_lap || browse != *(data->a_heap))
	{
		if (first_lap)
		{
			bigger = browse->nb;
			browse = browse->next;
			first_lap = 0;
			continue ;
		}
		bigger = ft_nb_max(bigger, browse->nb);
		browse = browse->next;
	}
	return (bigger);
}

long	ft_get_nb_min_from_a(t_data *data)
{
	long	smaller;
	int		first_lap;
	t_heap	*browse;

	first_lap = 1;
	browse = *(data->a_heap);
	while (first_lap || browse != *(data->a_heap))
	{
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

int	ft_size_binary(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return ((int)0);
	if (nb == 1)
		return ((int)1);
	while (nb / ft_power(2, i) != 0)
		i++;
	return (i);
}
