/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:06:05 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 15:06:21 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*ft_free_data_tdata(t_data *data)
{
	free(data);
	return ((t_data *)0);
}

t_data	*ft_free_a_data_tdata(t_data *data)
{
	ft_del_all_heap(data->a_heap);
	free(data);
	return ((t_data *)0);
}
