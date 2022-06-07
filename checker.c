/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:44:52 by yobenali          #+#    #+#             */
/*   Updated: 2022/06/01 21:39:05 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_is_handled2(t_data *data, char *op)
{
	if (ft_strcmp(op, "ss\n") == 0)
	{
		sel_swap(data, 'a');
		sel_swap(data, 'b');
	}
	else if (ft_strcmp(op, "rr\n") == 0)
	{
		sel_rotate(data, 'a');
		sel_rotate(data, 'b');
	}
	else if (ft_strcmp(op, "rrr\n") == 0)
	{
		sel_rev_rotate(data, 'a');
		sel_rev_rotate(data, 'b');
	}
}

int	ft_is_handled(t_data *data, char *op)
{
	ft_is_handled2(data, op);
	if (ft_strcmp(op, "pa\n") == 0)
		sel_push(data, 'a');
	else if (ft_strcmp(op, "pb\n") == 0)
		sel_push(data, 'b');
	else if (ft_strcmp(op, "sa\n") == 0)
		sel_swap(data, 'a');
	else if (ft_strcmp(op, "sb\n") == 0)
		sel_swap(data, 'b');
	else if (ft_strcmp(op, "ra\n") == 0)
		sel_rotate(data, 'a');
	else if (ft_strcmp(op, "rb\n") == 0)
		sel_rotate(data, 'b');
	else if (ft_strcmp(op, "rra\n") == 0)
		sel_rev_rotate(data, 'a');
	else if (ft_strcmp(op, "rrb\n") == 0)
		sel_rev_rotate(data, 'b');
	else
		return (0);
	return (1);
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
			exit(write(2, "Error\n", 6));
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

int	ft_operation(t_data *data, int fd)
{
	char	*op;

	op = get_next_line(fd);
	while (op)
	{
		if (!op)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (!ft_is_handled(data, op))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		free(op);
		op = get_next_line(fd);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc > 1)
	{
		data_init(&data, argc, argv, 1);
		while (i < *(data.count))
		{
			data.a[i] = ft_atoi(data.ptr[i]);
			data.sorted[i] = ft_atoi(data.ptr[i]);
			i++;
		}
		check_dup(&data);
		if (!ft_operation(&data, 0))
			return (0);
		if (ft_sorted(&data))
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
	return (0);
}
