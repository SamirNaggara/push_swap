/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:50:22 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/26 15:11:02 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_heap	**ft_add_beg_heap(t_heap **heap, long nb)
{
	t_heap	*new;

	new = ft_new_heap_element(nb);
	if (!new)
		return ((t_heap **)0);
	if (!(*heap))
	{
		new->next = new;
		new->prev = new;
		*heap = new;
		return (heap);
	}
	(*heap)->prev->next = new;
	new->prev = (*heap)->prev;
	new->next = *heap;
	(*heap)->prev = new;
	*heap = new;
	return (heap);
}

t_heap	**ft_add_end_heap(t_heap **heap, long nb)
{
	t_heap	*new;

	new = ft_new_heap_element(nb);
	if (!new)
		return ((t_heap **)0);
	if (!(*heap))
	{
		new->next = new;
		new->prev = new;
		*heap = new;
		return (heap);
	}
	((*heap)->prev)->next = new;
	new->prev = (*heap)->prev;
	new->next = *heap;
	(*heap)->prev = new;
	return (heap);
}

t_heap	*ft_new_heap_element(long nb)
{
	t_heap	*new;

	new = (t_heap *)malloc(sizeof(t_heap));
	if (!new)
		return ((t_heap *)0);
	new->next = NULL;
	new->prev = NULL;
	new->nb = nb;
	new->is_improved = 0;
	return (new);
}
