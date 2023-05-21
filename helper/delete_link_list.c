/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:49:52 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 09:46:12 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_del_all_heap(t_heap **heap)
{
	if (!heap)
		return ;
	if (!*heap)
	{
		free(heap);
		return ;
	}
	while (*heap)
	{
		ft_del_first_from_heap(heap);
	}
	free(heap);
}

/*
    Pour supprimer le dernier, il faut se déplacer de  un prev, 
	puis supprimer le premier
*/
void	ft_del_last_from_heap(t_heap **heap)
{
	ft_del_first_from_heap(&((*heap)->prev));
}

/*
    Pour supprimer le premier d'une pile.
*/
void	ft_del_first_from_heap(t_heap **heap)
{
	t_heap	*tmp;

	if (!heap || !*heap)
		return ;
	if (*heap == (*heap)->next)
	{
		free(*heap);
		*heap = (t_heap *)0;
		return ;
	}
	(*heap)->prev->next = (*heap)->next;
	(*heap)->next->prev = (*heap)->prev;
	tmp = *heap;
	*heap = (*heap)->next;
	free(tmp);
}
