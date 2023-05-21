/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:41:53 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 09:40:26 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
On rotate les 2 en même temps*/
void	ft_rr(t_data *data)
{
	ft_ra(data);
	ft_rb(data);
}

/*
    Decale le premier de A a la fin de A.
    Il suffit de déplacer le premier poineur vers le deuxieme element
*/
void	ft_ra(t_data *data)
{
	if (!*(data->a_heap))
		return ;
	*(data->a_heap) = (*(data->a_heap))->next;
	ft_add_move(data, "ra");
}

/*
    Decale le premier de B a la fin de B.
    Il suffit de déplacer le premier poineur vers le deuxieme element
*/
void	ft_rb(t_data *data)
{
	if (!*(data->b_heap))
		return ;
	*(data->b_heap) = (*(data->b_heap))->next;
	ft_add_move(data, "rb");
}
