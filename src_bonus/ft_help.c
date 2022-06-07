/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:34:24 by yobenali          #+#    #+#             */
/*   Updated: 2022/06/01 21:34:25 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_big2(t_data *data)
{
	int	i;

	*(data->down) = 0;
	while (*(data->b_count) + *(data->down) != 0)
	{
		i = biggest_value(data);
		if (i != -1)
			lifo(data, i);
		else if (*data->down > 0)
		{
			sel_rev_rotate(data, 'a');
			(*data->down)--;
		}
	}
}

void	check_big(t_data *data)
{
	if (*(data->count) > 5)
	{
		*(data->first_in) = *(data->count);
		while (*(data->count) != 0)
			push_first(data);
	}
}
