/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:19:31 by yobenali          #+#    #+#             */
/*   Updated: 2022/06/01 21:42:12 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(int *from, int *to, int *from_count, int *to_count)
{
	int	i;

	if (*from_count == 0)
		return ;
	i = *to_count + 1;
	while (--i > 0)
		to[i] = to[i - 1];
	to[0] = from[0];
	i = 0;
	while (i + 1 < *from_count)
	{
		from[i] = from[i + 1];
		i++;
	}
	(*from_count)--;
	(*to_count)++;
}

void	sel_push(t_data *data, char c)
{
	if (c == 'a')
	{
		ft_push(data->b, data->a, data->b_count, data->count);
		write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		ft_push(data->a, data->b, data->count, data->b_count);
		write(1, "pb\n", 3);
	}
}

void	sel_rotate(t_data *data, char c)
{
	if (c == 'a')
	{
		ft_rotate(data->a, data->count);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		ft_rotate(data->b, data->b_count);
		write(1, "rb\n", 3);
	}
}

void	sel_rev_rotate(t_data *data, char c)
{
	if (c == 'a')
	{
		ft_rev_rotate(data->a, data->count);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		ft_rev_rotate(data->b, data->b_count);
		write(1, "rrb\n", 4);
	}
}

void	sel_swap(t_data *data, char c)
{
	if (c == 'a')
	{
		ft_swap(data->a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		ft_swap(data->b);
		write(1, "sb\n", 3);
	}
}
