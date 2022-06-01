/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:27:22 by yobenali          #+#    #+#             */
/*   Updated: 2022/05/29 18:46:57 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	biggest_value(t_data *data)
{
	int	i;
	int	index;

	index = *(data->b_count) + *(data->down);
	i = 0;
	while (i < *(data->b_count))
	{
		if (data->sorted[index - 1] == data->b[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_offset(t_data *data)
{
	if (*(data->count) <= 10)
		*data->offset = *(data->count) / 5;
	else if (*(data->count) <= 150)
		*data->offset = *(data->count) / 8;
	else
		*data->offset = *(data->count) / 13;
	return (*data->offset);
}

int	check_lower(t_data *data)
{
	int	i;

	i = *data->mid;
	while (i <= *(data->end))
	{
		if (data->b[0] == data->sorted[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_sorted(t_data *data)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	while (i < *(data->count) - 1)
	{
		if (data->a[i] < data->a[i + 1])
			j++;
		else
			return (0);
		i++;
	}
	if (j == *(data->count) - 1)
		return (1);
	return (0);
}

int	bigger(t_data *data)
{
	if (data->a[0] > data->a[1] && data->a[0] > data->a[2])
		return (1);
	else if (data->a[1] > data->a[2] && data->a[1] > data->a[0])
		return (2);
	return (0);
}
