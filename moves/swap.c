/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:44:13 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 09:47:56 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
}

void	ft_sb(t_data *data)
{
	int	tmp;

	if (ft_heap_empty_or_uniq(data->b_heap))
		return ;
	tmp = (*(data->b_heap))->nb;
	(*(data->b_heap))->nb = (*(data->b_heap))->next->nb;
	(*(data->b_heap))->next->nb = tmp;
	ft_add_move(data, "sb");
	return ;
}

void	ft_sa(t_data *data)
{
	int	tmp;

	if (ft_heap_empty_or_uniq(data->a_heap))
		return ;
	tmp = (*(data->a_heap))->nb;
	(*(data->a_heap))->nb = (*(data->a_heap))->next->nb;
	(*(data->a_heap))->next->nb = tmp;
	ft_add_move(data, "sa");
	return ;
}
