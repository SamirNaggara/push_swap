/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 12:31:31 by snaggara         ###   ########.fr       */
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
		ft_printf("%d\n", (int)browse->nb);
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
		printf("rien dans cette heap\n");
		return ;
	}
	browse = (*heap)->prev;
	printf("début de la heap :\n");
	while (browse)
	{
		printf("%ld\n", browse->nb);
		browse = browse->prev;
		if (browse == (*heap)->prev)
			break ;
	}
	printf("fin de la heap :\n");
}
