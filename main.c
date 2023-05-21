/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/21 10:53:19 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_init(ac, av);

	if (ft_is_order(data->a_heap))
		ft_printf("liste ordonnée");
	
	

	//ft_printf("Voila les moves : %s\n", data->moves);
	//ft_print_heap(data->a_heap);
	
	return (ft_free_end(data));
}





/*
	Renvoie 1 si la liste est ordonnée
*/
int		ft_is_order(t_heap	**heap)
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