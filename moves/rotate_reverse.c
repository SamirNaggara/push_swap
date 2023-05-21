/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:42:49 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 09:40:11 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
On reverse rotate les 2 en même temps*/
void	ft_rrr(t_data *data)
{
	ft_rra(data);
	ft_rrb(data);
}

/*
    Rotate vers le haut
    Suffit de déplacer le pointeur vers le dernier élément
*/
void	ft_rra(t_data *data)
{
	if (!*(data->a_heap))
		return ;
	*(data->a_heap) = (*(data->a_heap))->prev;
	ft_add_move(data, "rra");
}

/*
    Rotate vers le haut
    Suffit de déplacer le pointeur vers le dernier élément
*/
void	ft_rrb(t_data *data)
{
	if (!*(data->b_heap))
		return ;
	*(data->b_heap) = (*(data->b_heap))->prev;
	ft_add_move(data, "rrb");
}
