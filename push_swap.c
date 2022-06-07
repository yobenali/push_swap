/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:44:52 by yobenali          #+#    #+#             */
/*   Updated: 2022/06/01 21:40:55 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_sort(t_data *data)
{
	ft_sort_int_tab(data, *(data->count));
	*(data->mid) = *(data->count) / 2;
	*(data->offset) = ft_offset(data);
	*(data->start) = *(data->mid) - *(data->offset);
	if (*(data->start) < 0)
		*(data->start) = 0;
	*(data->end) = *(data->mid) + *(data->offset);
	if (*(data->end) >= *(data->count))
		*(data->end) = *(data->count) - 1;
	check_dup(data);
}

void	data_init(t_data *data, int argc, char **argv, int i)
{
	data->count = ft_calloc(sizeof(int), 1);
	data->b_count = ft_calloc(sizeof(int), 1);
	data->first_in = ft_calloc(sizeof(int), 1);
	data->mid = ft_calloc(sizeof(int), 1);
	data->offset = ft_calloc(sizeof(int), 1);
	data->end = ft_calloc(sizeof(int), 1);
	data->start = ft_calloc(sizeof(int), 1);
	data->down = ft_calloc(sizeof(int), 1);
	data->tab = ft_strdup("");
	while (i < argc)
	{
		if (*argv[i] == '\0')
			exit(write(2, "Error empty string\n", 20));
		data->tab = ft_strjoin(data->tab, argv[i]);
		data->tab = ft_strjoin(data->tab, " ");
		i++;
	}
	data->ptr = ft_split(data->tab, ' ');
	while (data->ptr[*(data->count)])
		(*data->count)++;
	data->a = malloc(*(data->count) * sizeof(int));
	data->b = malloc(*(data->count) * sizeof(int));
	data->sorted = malloc(*(data->count) * sizeof(int));
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	data_init(&data, argc, argv, 1);
	while (i < *(data.count))
	{
		data.a[i] = ft_atoi(data.ptr[i]);
		data.sorted[i] = ft_atoi(data.ptr[i]);
		i++;
	}
	ft_ultimate(&data);
	if (*(data.count) == 0)
		check_big2(&data);
	if (*(data.count) == 5 && !ft_sorted(&data))
		ft_five(&data);
	if ((*data.count) == 4 && !ft_sorted(&data))
		ft_four(&data);
	if (*(data.count) == 3 && !ft_sorted(&data))
		low_sort(&data);
	if (*(data.count) == 2)
		low_sort(&data);
	system("leaks push_swap");
	return (0);
}
