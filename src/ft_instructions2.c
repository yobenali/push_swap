/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:26:11 by yobenali          #+#    #+#             */
/*   Updated: 2022/06/01 21:42:40 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ft_rotate(int *stack, int *count)
{
	int	tmp;
	int	j;

	j = 0;
	tmp = stack[0];
	while (j < *count - 1)
	{
		stack[j] = stack[j + 1];
		j++;
	}
	stack[j] = tmp;
}

void	ft_rev_rotate(int *stack, int *count)
{
	int	tmp;
	int	j;

	j = *count;
	tmp = stack[*(count) - 1];
	while (--j > 0)
		stack[j] = stack[j - 1];
	stack[0] = tmp;
}

void	check_dup(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < *(data->count))
	{
		j = i + 1;
		while (j < *(data->count))
		{
			if (data->a[j] == data->a[i])
				exit(write(2, "Error duplicated number :D\n", 27));
			j++;
		}
		i++;
	}
}

void	ft_select(t_data *data, int loc)
{
	if (loc == 0)
		return ;
	else if (loc == 1)
		sel_swap(data, 'a');
	else if (loc == 2)
	{
		sel_rotate(data, 'a');
		sel_rotate(data, 'a');
	}
	else if (loc == 3 && *(data->count) == 5)
	{
		sel_rev_rotate(data, 'a');
		sel_rev_rotate(data, 'a');
	}
	else
		sel_rev_rotate(data, 'a');
}
