/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:04 by yobenali          #+#    #+#             */
/*   Updated: 2022/05/29 18:37:12 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	simple_sort(t_data *data)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 1;
	while (i < *(data->count))
	{
		if (data->a[tmp] < data->a[i])
			i++;
		else
		{
			tmp = i;
			i++;
		}
	}
	ft_select(data, tmp);
	sel_push(data, 'b');
}

void	low_sort(t_data *data)
{
	int	i;

	if (*(data->count) == 3)
	{
		i = bigger(data);
		if (i == 1)
			sel_rotate(data, 'a');
		else if (i == 2)
			sel_rev_rotate(data, 'a');
		if (data->a[0] > data->a[1])
			sel_swap(data, 'a');
	}
	if (*(data->count) == 2)
	{
		if (data->a[0] > data->a[1])
			sel_swap(data, 'a');
	}
}

void	ft_four(t_data *data)
{
	if (!(ft_sorted(data)))
		simple_sort(data);
	low_sort(data);
	sel_push(data, 'a');
}

void	ft_five(t_data *data)
{
	if (ft_sorted(data))
		exit(0);
	simple_sort(data);
	simple_sort(data);
	low_sort(data);
	sel_push(data, 'a');
	sel_push(data, 'a');
}
