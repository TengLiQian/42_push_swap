/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:31:51 by lteng             #+#    #+#             */
/*   Updated: 2024/02/28 00:38:58 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compare to see if a equals b
int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] == b[i])
			i++;
		else
			break ;
	}
	return (a[i] - b[i]);
}

// Compare to see if duplicates found in str[]
int	ft_duplicate(char *str[])
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
