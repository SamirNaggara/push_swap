/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_link_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:54:21 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 09:39:20 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_heap_empty_or_uniq(t_heap **heap)
{
	if (!heap)
		return (1);
	if (*heap == (*heap)->next)
		return (1);
	return (0);
}
