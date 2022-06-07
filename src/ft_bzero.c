/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:32:10 by yobenali          #+#    #+#             */
/*   Updated: 2021/11/21 02:18:46 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void	*s, size_t n)
{
	ft_memset(s, 0, n);
}

void	ft_ultimate(t_data *data)
{
	if (!ft_sorted(data))
	{
		check_sort(data);
		check_big(data);
	}
}

void	lifo(t_data *data, int i)
{
	if (data->b[0] == data->sorted[*(data->b_count)
			+ *(data->down) - 1])
	{
		sel_push(data, 'a');
	}
	else if (*(data->down) == 0
		|| data->b[0] > data->a[*(data->count) - 1])
	{
		sel_push(data, 'a');
		sel_rotate(data, 'a');
		(*data->down)++;
	}
	else
	{
		if (i > *(data->b_count) / 2)
			sel_rev_rotate(data, 'b');
		else
			sel_rotate(data, 'b');
	}
}

void	push_first(t_data *data)
{
	while (*(data->b_count) <= (*(data->end) - *(data->start)))
	{
		if (data->a[0] >= data->sorted[*(data->start)]
			&& data->a[0] <= data->sorted[*data->end])
		{
			sel_push(data, 'b');
			if (data->b[0] < data->sorted[*(data->mid)])
				sel_rotate(data, 'b');
		}
		else
			sel_rotate(data, 'a');
	}
	*(data->start) -= *(data->offset);
	if (*(data->start) < 0)
		*(data->start) = 0;
	*(data->end) += *(data->offset);
	if (*(data->end) >= *(data->first_in))
		*(data->end) = *(data->first_in) - 1;
}
