/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:41:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 09:39:56 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
    Push dans B
*/
void	ft_pb(t_data *data)
{
	if (!*(data->a_heap))
		return ;
	ft_add_beg_heap(data->b_heap, (*(data->a_heap))->nb);
	ft_del_first_from_heap(data->a_heap);
	ft_add_move(data, "pb");
}

/*
    Push dans A
*/
void	ft_pa(t_data *data)
{
	if (!*(data->b_heap))
		return ;
	ft_add_beg_heap(data->a_heap, (*(data->b_heap))->nb);
	ft_del_first_from_heap(data->b_heap);
	ft_add_move(data, "pa");
}
