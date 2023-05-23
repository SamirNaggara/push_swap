/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaisons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:53:46 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 14:19:02 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_nb_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
