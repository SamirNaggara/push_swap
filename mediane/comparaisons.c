/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaisons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:53:46 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/24 13:00:31 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_nb_max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

long	ft_nb_min(long a, long b)
{
	if (a < b)
		return (a);
	return (b);
}
