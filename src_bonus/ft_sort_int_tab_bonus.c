/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:44:30 by yobenali          #+#    #+#             */
/*   Updated: 2021/08/09 17:01:47 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_sort_int_tab(t_data *data, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (data->sorted[i] > data->sorted[j])
			{
				temp = data->sorted[i];
				data->sorted[i] = data->sorted[j];
				data->sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
}
