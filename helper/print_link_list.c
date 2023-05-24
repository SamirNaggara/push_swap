/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/24 12:52:00 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_heap(t_heap **heap)
{
	t_heap	*browse;

	if (!heap || !*heap)
	{
		printf("rien dans cette heap\n");
		return ;
	}
	browse = *heap;
	printf("début de la heap :\n");
	while (browse)
	{
		printf("%ld\n", browse->nb);
		browse = browse->next;
		if (browse == *heap)
			break ;
	}
	printf("fin de la heap :\n");
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
