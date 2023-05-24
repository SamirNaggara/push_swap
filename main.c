/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/24 13:46:41 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_init(ac, av);
	if (!data)
		return (0);
	if (ft_is_order(data->a_heap))
		return (ft_free_heap_and_data(data));
	
	if (data->nb_numbers <= 4)
	{
		if (!ft_really_small_method(data))
			return (0);
	}
	else
	{
		if (!ft_radix_method(data))
			return (0);
	}
	//printf("a heap : \n");
	//ft_print_heap(data->a_heap);
	ft_free_end(data);

	return (0);
}

int	ft_radix_method(t_data *data)
{
	(void)data;
	printf("Before sort : \n");
	ft_print_heap(data->a_heap);

	data->nb_max = ft_get_nb_max_from_a(data);
	if (!ft_radix_sort(data))
		return (0);
	printf("nb_max : %ld", data->nb_max);
	printf("After sort : \n");

	return (1);
}

int	ft_radix_sort(t_data *data)
{
	int	size;
	//int	i;

	size = ft_size_binary(data->nb_max);
	printf("Nombre total de move prevu : %ld\n", ft_get_comb_nb_radix(data, size));
	// while (i < size)
	// {
	// if (!comb)
	// 	return ((int *)0);
	// 	if ()
	// 	i++;
	// }
	return (1);

}

/*
	On a besoin de savoir exatement combien de movement on va réaliser
	Donc, on boucle dans la heap a
	Et on determine combien de mouvement va nous couter chaque nombre
*/
long	ft_get_comb_nb_radix(t_data *data, int size_max)
{
	int		first_lap;
	t_heap	*browse;
	long	nb_move;

	nb_move = 0;
	first_lap = 1;
	browse = *(data->a_heap);
	while (first_lap || browse != *(data->a_heap))
	{
		if (first_lap)
			first_lap = 0;
		nb_move += ft_get_comb_length(browse->nb, size_max);
		browse = browse->next;
	}
	return (nb_move);
}

/*
	En fait pour un nombre, a chaque fois qu'il y a un 0 il
	va etre déplacé de 1 (genre juste on le passe quoi, avec ra)
	Ou alors il va etre déplacé de 2 (pb, puis pa)
	Donc là on calcul pour 1 nombre combien de déplacement il va 
	neccessiter
*/
long	ft_get_comb_length(long nb, int size_max)
{
	int		i;
	long	local_nb_move;

	local_nb_move = 0;
	i = 0;
	while (i < size_max)
	{
		if (((nb>>i) & 1) == 0)
			local_nb_move++;
		else
			local_nb_move+=2;
		i++;
	}

	return (local_nb_move);

}


long	ft_get_nb_max_from_a(t_data *data)
{
	long	bigger;
	int		first_lap;
	t_heap	*browse;

	first_lap = 1;
	browse = *(data->a_heap);
	while (first_lap || browse != *(data->a_heap))
	{
		if (first_lap)
		{
			bigger = browse->nb;
			browse = browse->next;
			first_lap = 0;
			continue ;
		}
		bigger = ft_nb_max(bigger, browse->nb);
		browse = browse->next;
	}
	return (bigger);
}

int	ft_size_binary(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (unsigned long)0;
	if (nb == 1)
		return (unsigned long)1;
	while (nb / ft_power(2, i) != 0)
		i++;
	return (i);
}

int	ft_really_small_method(t_data *data)
{
	
	data->comb = ft_brut_force_a(data);
	if (!data->comb)
		return (ft_free_heap_and_data(data));
	ft_display_comb(data);
	free(data->comb);
	return (1);
}