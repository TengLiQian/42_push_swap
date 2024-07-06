/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:08 by lteng             #+#    #+#             */
/*   Updated: 2024/03/20 21:40:24 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_nbr(t_stack *stack)
{
	int	i;

	i = (stack)->nbr;
	while (stack)
	{
		if ((stack)->nbr > i)
			i = (stack)->nbr;
		stack = (stack)->next;
	}
	return (i);
}

int	min_nbr(t_stack *stack)
{
	int	i;

	i = (stack)->nbr;
	while (stack)
	{
		if ((stack)->nbr < i)
			i = (stack)->nbr;
		stack = (stack)->next;
	}
	return (i);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
