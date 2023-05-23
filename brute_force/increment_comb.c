/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_comb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:00:28 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 14:28:31 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Ici on a une combinaison, on va l'incrementer de 1
	Y'a un -1 a la fin pour connaitre sa taille
	Et si on ne peut pas parce qu'on est au max
	On renvoie faux
*/
int	ft_increment_comb(int *comb, int n)
{
	int	i;

	comb[n - 1]++;
	i = n - 1;
	while (i >= 0)
	{
		if (comb[i] == 11)
		{
			if (i == 0)
				return (0);
			comb[i] = 0;
			comb[i - 1]++;
			continue ;
		}
		i--;
	}
	if (!ft_increment_more(comb, n))
		return (0);
	return (1);
}

/* 
	On lis le nombre, et si on vois qu'il a besoin d'une incrementation
	supplementaire
	On renvoie 1
	Par exemple si il finit par un pb, c'est impossible
	Donc on incremente 
*/
int	ft_increment_more(int *comb, int n)
{
	if (comb[0] == 1 || comb[0] == 2 || comb[0] == 3
		|| comb[0] == 6 || comb[0] == 7 || comb[0] == 9
		|| comb[0] == 10)
	{
		if (!ft_increment_comb(comb, n))
			return (0);
	}
	if (comb[n - 1] == 1 || comb[n - 1] == 2 || comb[n - 1] == 4
		|| comb[n - 1] == 6 || comb[n - 1] == 7 || comb[n - 1] == 9
		|| comb[n - 1] == 10)
	{
		if (!ft_increment_comb(comb, n))
			return (0);
	}
	return (1);
}
