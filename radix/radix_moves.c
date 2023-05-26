/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:30:38 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 15:08:43 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push_all_b_in_a(t_data *data, int k)
{
	while ((data->b_heap) && (*(data->b_heap)))
	{
		data->comb[k] = 3;
		ft_pa(data);
		k++;
	}
	return (k);
}

/*
	Si un bit est 0, alors on on le laisse la, on fait un ra
	Si c'est un 1, on le pb
*/
void	ft_radix_one_bit(t_data *data, int i, int k)
{
	int		nb;

	nb = (*(data->a_heap))->nb;
	if (((nb >> i) & 1) == 1)
	{
		data->comb[k] = 5;
		ft_ra(data);
	}
	else
	{
		data->comb[k] = 4;
		ft_pb(data);
	}
}

/*
	On a besoin de savoir exatement combien de movement on va réaliser
	Donc, on boucle dans la heap a
	Et on determine combien de mouvement va nous couter chaque nombre
*/
int	ft_get_comb_nb_radix(t_data *data)
{
	int		first_lap;
	t_heap	*browse;
	long	nb_move;

	nb_move = 0;
	first_lap = 1;
	browse = *(data->a_heap);
	while (first_lap || browse != *(data->a_heap))
	{
		if (first_lap)
			first_lap = 0;
		nb_move += ft_get_comb_length(browse->nb, data->size_max);
		browse = browse->next;
	}
	return (nb_move);
}
