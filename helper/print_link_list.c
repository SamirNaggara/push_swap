/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 09:39:15 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_heap(t_heap **heap)
{
	t_heap	*browse;

	if (!heap || !*heap)
	{
		ft_printf("rien dans cette heap\n");
		return ;
	}
	browse = *heap;
	ft_printf("début de la heap :\n");
	while (browse)
	{
		ft_printf("%d\n", browse->nb);
		browse = browse->next;
		if (browse == *heap)
			break ;
	}
	ft_printf("fin de la heap :\n");
}

void	ft_print_heap_reverse(t_heap **heap)
{
	t_heap	*browse;

	if (!heap || !*heap)
	{
		ft_printf("rien dans cette heap\n");
		return ;
	}
	browse = (*heap)->prev;
	ft_printf("début de la heap :\n");
	while (browse)
	{
		ft_printf("%d\n", browse->nb);
		browse = browse->prev;
		if (browse == (*heap)->prev)
			break ;
	}
	ft_printf("fin de la heap :\n");
}
