/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_comb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:56:40 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/25 16:05:03 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_display_comb(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_comb)
	{
		if (data->comb[i] == 0)
			printf("%s\n", "sa");
		else if (data->comb[i] == 1)
			printf("%s\n", "sb");
		else if (data->comb[i] == 2)
			printf("%s\n", "ss");
		else if (data->comb[i] == 3)
			printf("%s\n", "pa");
		else if (data->comb[i] == 4)
			printf("%s\n", "pb");
		else if (data->comb[i] == 5)
			printf("%s\n", "ra");
		else if (data->comb[i] == 6)
			printf("%s\n", "rb");
		ft_display_comb_2(data, i);
		i++;
	}
}

void	ft_display_comb_2(t_data *data, int i)
{
	if (data->comb[i] == 7)
		printf("%s\n", "rr");
	else if (data->comb[i] == 8)
		printf("%s\n", "rra");
	else if (data->comb[i] == 9)
		printf("%s\n", "rrb");
	else if (data->comb[i] == 10)
		printf("%s\n", "rrr");
}
// void	ft_display_this_comb(int *comb, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (comb[i] == 0)
// 			printf("%s\n", "sa");
// 		else if (comb[i] == 1)
// 			printf("%s\n", "sb");
// 		else if (comb[i] == 2)
// 			printf("%s\n", "ss");
// 		else if (comb[i] == 3)
// 			printf("%s\n", "pa");
// 		else if (comb[i] == 4)
// 			printf("%s\n", "pb");
// 		else if (comb[i] == 5)
// 			printf("%s\n", "ra");
// 		else if (comb[i] == 6)
// 			printf("%s\n", "rb");
// 		else if (comb[i] == 7)
// 			printf("%s\n", "rr");
// 		else if (comb[i] == 8)
// 			printf("%s\n", "rra");
// 		else if (comb[i] == 9)
// 			printf("%s\n", "rrb");
// 		else if (comb[i] == 10)
// 			printf("%s\n", "rrr");
// 		i++;
// 	}
// }
