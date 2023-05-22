/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:41:53 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/22 13:27:21 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
On rotate les 2 en même temps*/
int	ft_rr(t_data *data)
{
	if (!*(data->a_heap))
		return (0);
	if (!*(data->b_heap))
		return (0);
	ft_ra(data);
	ft_rb(data);
	return (1);
}

/*
    Decale le premier de A a la fin de A.
    Il suffit de déplacer le premier poineur vers le deuxieme element
*/
int	ft_ra(t_data *data)
{
	if (!*(data->a_heap))
		return (0);
	*(data->a_heap) = (*(data->a_heap))->next;
	return (1);
}

/*
    Decale le premier de B a la fin de B.
    Il suffit de déplacer le premier poineur vers le deuxieme element
*/
int	ft_rb(t_data *data)
{
	if (!*(data->b_heap))
		return (0);
	*(data->b_heap) = (*(data->b_heap))->next;
	return (1);
}
