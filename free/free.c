/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:41:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 10:41:58 by snaggara         ###   ########.fr       */
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