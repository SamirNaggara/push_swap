/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:44:13 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/22 13:49:28 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_ss(t_data *data)
{
	if (!data->a_heap || !*data->a_heap)
		return (0);
	if (*data->a_heap == (*(data->a_heap))->next)
		return (0);
	if (!data->b_heap || !*data->b_heap)
		return (0);
	if (*data->b_heap == (*(data->b_heap))->next)
		return (0);
	ft_sa(data);
	ft_sb(data);
	return (1);
}

int	ft_sb(t_data *data)
{
	int	tmp;

	if (!data->b_heap || !*data->b_heap)
		return (0);
	if (*data->b_heap == (*(data->b_heap))->next)
		return (0);
	tmp = (*(data->b_heap))->nb;
	(*(data->b_heap))->nb = (*(data->b_heap))->next->nb;
	(*(data->b_heap))->next->nb = tmp;
	return (1);
}

int	ft_sa(t_data *data)
{
	int	tmp;

	if (!data->a_heap || !*data->a_heap)
		return (0);
	if (*data->a_heap == (*(data->a_heap))->next)
		return (0);
	tmp = (*(data->a_heap))->nb;
	(*(data->a_heap))->nb = (*(data->a_heap))->next->nb;
	(*(data->a_heap))->next->nb = tmp;
	return (1);
}
