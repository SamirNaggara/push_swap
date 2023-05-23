/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:42:49 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 14:35:23 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
On reverse rotate les 2 en même temps*/
int	ft_rrr(t_data *data)
{
	if (!*(data->a_heap))
		return (0);
	if (!*(data->b_heap))
		return (0);
	ft_rra(data);
	ft_rrb(data);
	return (1);
}

/*
    Rotate vers le haut
    Suffit de déplacer le pointeur vers le dernier élément
*/
int	ft_rra(t_data *data)
{
	if (!*(data->a_heap))
		return (0);
	*(data->a_heap) = (*(data->a_heap))->prev;
	return (1);
}

/*
    Rotate vers le haut
    Suffit de déplacer le pointeur vers le dernier élément
*/
int	ft_rrb(t_data *data)
{
	if (!*(data->b_heap))
		return (0);
	*(data->b_heap) = (*(data->b_heap))->prev;
	return (1);
}
