/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_link_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:54:21 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/24 11:37:48 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_heap_empty_or_uniq(t_heap **heap)
{
	if (!heap || !*heap)
		return (1);
	if (*heap == (*heap)->next)
		return (1);
	return (0);
}

int	ft_size_heap(t_heap **heap)
{
	t_heap	*browse;
	int		i;

	if (!heap || !*heap)
		return (0);
	i = 1;
	browse = *heap;
	while (browse->next != *heap)
	{
		browse = browse->next;
		i++;
	}
	return (i);
}

/*
	Renvoie 1 si la heap est ordonnée
*/
int	ft_is_order(t_heap	**heap)
{
	t_heap	*browse;

	browse = *heap;
	while (browse->next != *heap)
	{
		if (browse->nb >= browse->next->nb)
			return (0);
		browse = browse->next;
	}
	return (1);
}

/*
	Renvoie 1 si la heap est empty
*/
int	ft_is_empty(t_heap **heap)
{
	if (!heap)
		return (1);
	if (!*heap)
		return (1);
	return (0);
}


