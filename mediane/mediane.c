/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:53:22 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:15 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	On parcours la double liste chainee sur n caractere
	Si c'est supérieur a la mediane on pousse
	Sinon on rotate
*/
int	*ft_push_above_mediane(t_data *data, int n)
{
	int		i;
	int		*comb;

	comb = (int *)malloc(sizeof(int) * n);
	if (!comb)
		return ((int *)0);
	i = 0;
	while (i < n)
	{
		if ((*(data->a_heap))->nb > *(data->med))
		{
			ft_pb(data);
			comb[i] = 4;
		}
		else
		{
			ft_ra(data);
			comb[i] = 5;
		}
		i++;
	}
	return (comb);
}

float	*ft_mediane(t_heap **heap)
{
	int		*ordered_int;
	int		size_heap;
	int		i;
	float	*med;

	if (!heap || !*heap)
		return ((float *)0);
	size_heap = ft_size_heap(heap);
	ordered_int = (int *)malloc(sizeof(int) * size_heap);
	if (!ordered_int)
		return ((float *)0);
	i = 0;
	while (i < size_heap)
	{
		if (i == 0)
			ordered_int[i++] = ft_extract_smaller(heap, -2147483648);
		else
			ordered_int[i] = ft_extract_smaller(heap, ordered_int[i - 1] + 1);
		i++;
	}
	ft_print_heap(heap);
	med = ft_mediane_from_tab(ordered_int, size_heap);
	free(ordered_int);
	return (med);
}

float	*ft_mediane_from_tab(int *ordered_int, int size)
{
	float	*med;

	med = (float *)malloc(sizeof(float));
	if (!med)
		return (NULL);
	printf("size / 2: %d\n", size / 2);
	printf("Orderded int de 3 : %d\n", ordered_int[3]);
	if (size % 2 == 0)
	{
		*med = ((float)ordered_int[size / 2 - 1]
				+ (float)ordered_int[size / 2]) / 2;
	}
	else
		*med = ((float)ordered_int[size / 2]);
	return (med);
}

/*
	On cherche le plus petit nombre contenu dans la heap
	MAIS attention, on cherche a partir de nb, nb inclus !
*/
int	ft_extract_smaller(t_heap **heap, int nb)
{
	int		smaller;
	int		first_lap;
	t_heap	*browse;

	first_lap = 1;
	browse = *heap;
	while (first_lap || browse != *heap)
	{
		if (browse->nb < nb)
		{
			browse = browse->next;
			continue ;
		}
		if (first_lap)
		{
			smaller = browse->nb;
			browse = browse->next;
			first_lap = 0;
			continue ;
		}
		smaller = ft_nb_min(smaller, browse->nb);
		browse = browse->next;
	}
	return (smaller);
}
