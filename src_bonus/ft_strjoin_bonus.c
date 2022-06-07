/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:03:17 by yobenali          #+#    #+#             */
/*   Updated: 2022/05/20 18:16:26 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_hp_free(char *str)
{
	free(str);
	str = NULL;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*tab;

	i = -1;
	j = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	tab = (char *)ft_calloc(size + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (++i < j)
		tab[i] = s1[i];
	if (s1)
		ft_hp_free(s1);
	j = 0;
	while (i < size)
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	return (tab);
}
