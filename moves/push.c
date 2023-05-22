/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:41:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/22 13:27:06 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
    Push dans B
	Si ça ne fait rien, il retourne 0
*/
int	ft_pb(t_data *data)
{
	if (!(data->a_heap) || !*(data->a_heap))
		return (0);
	ft_add_beg_heap(data->b_heap, (*(data->a_heap))->nb);
	if (!ft_del_first_from_heap(data->a_heap))
		return (0);
	return (1);
}

/*
    Push dans A
*/
int	ft_pa(t_data *data)
{
	if (!(data->b_heap) || !*(data->b_heap))
		return (0);
	ft_add_beg_heap(data->a_heap, (*(data->b_heap))->nb);
	if (!ft_del_first_from_heap(data->b_heap))
		return (0);
	return (1);
}
