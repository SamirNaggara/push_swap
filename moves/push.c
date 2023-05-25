/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:41:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/25 13:33:26 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
    Push dans B
	Si ça ne fait rien, il retourne 0
*/
int	ft_pb(t_data *data)
{
	t_heap	*tmp;

	if (!(data->a_heap) || !*(data->a_heap))
		return (0);
	tmp = *(data->a_heap);
	((*(data->a_heap))->prev)->next = (*(data->a_heap))->next;
	((*(data->a_heap))->next)->prev = (*(data->a_heap))->prev;
	if (*(data->a_heap) == (*(data->a_heap))->next)
		*(data->a_heap) = (t_heap *)0;
	else
		*(data->a_heap) = (*(data->a_heap))->next;
	if (!*(data->b_heap))
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *(data->b_heap);
		tmp->prev = (*(data->b_heap))->prev;
		((*(data->b_heap))->prev)->next = tmp;
		(*(data->b_heap))->prev = tmp;
	}
	*(data->b_heap) = tmp;
	return (1);
}

/*
    Push dans A
*/
int	ft_pa(t_data *data)
{
	t_heap	*tmp;

	if (!(data->b_heap) || !*(data->b_heap))
		return (0);
	tmp = *(data->b_heap);
	((*(data->b_heap))->prev)->next = (*(data->b_heap))->next;
	((*(data->b_heap))->next)->prev = (*(data->b_heap))->prev;
	if (*(data->b_heap) == (*(data->b_heap))->next)
		*(data->b_heap) = (t_heap *)0;
	else
		*(data->b_heap) = (*(data->b_heap))->next;
	if (!*(data->a_heap))
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *(data->a_heap);
		tmp->prev = (*(data->a_heap))->prev;
		((*(data->a_heap))->prev)->next = tmp;
		(*(data->a_heap))->prev = tmp;
	}
	*(data->a_heap) = tmp;
	return (1);
}
