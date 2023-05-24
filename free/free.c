/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:41:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/24 09:17:23 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_free_end(t_data *data)
{
	ft_del_all_heap(data->a_heap);
	ft_del_all_heap(data->b_heap);
	free(data);
	return (0);
}

int	ft_free_data(t_data *data)
{
	free(data);
	return (0);
}

t_data	*ft_free_data_tdata(t_data *data)
{
	free(data);
	return ((t_data *)0);
}

int	ft_free_heap_and_data(t_data *data)
{
	ft_del_all_heap(data->a_heap);
	ft_del_all_heap(data->b_heap);
	free(data);
	return (0);
}

t_data	*ft_free_a_data_tdata(t_data *data)
{
	ft_del_all_heap(data->a_heap);
	free(data);
	return ((t_data *)0);
}

t_heap	**ft_free_a_data_theap(t_data *data)
{
	ft_del_all_heap(data->a_heap);
	free(data);
	return ((t_heap **)0);
}
