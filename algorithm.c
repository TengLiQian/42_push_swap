/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:17:41 by lteng             #+#    #+#             */
/*   Updated: 2024/03/21 21:33:35 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stack **a)
{
	t_stack	**b;
	int		i;

	i = 0;
	b = malloc(sizeof(t_stack *));
	if (b == NULL)
		return ;
	*b = NULL;
	ft_initialisation(*a, *b);
	while (i < 2)
	{
		while (*a != find_smallest(*a))
		{
			if (find_smallest(*a)->above_median)
				rotate_a(a);
			else
				reverse_rotate_a(a);
		}
		push_b(a, b);
		i++;
	}
	ft_sort_three(a);
	push_a(a, b);
	push_a(a, b);
	free(b);
}

void	ft_sort_three(t_stack **a)
{
	if ((*a)->nbr == min_nbr(*a))
	{
		if (is_sorted(*a) == 1)
		{
			reverse_rotate_a(a);
			swap_a(a);
		}
	}
	else if (((*a)->nbr) == max_nbr(*a))
	{
		rotate_a(a);
		if (is_sorted(*a) == 1)
			swap_a(a);
	}
	else if (((*a)->next)->nbr == max_nbr(*a))
		reverse_rotate_a(a);
	else
		swap_a(a);
}

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		while (*b != cheapest && *a != cheapest->target_node)
			rotate_ab(a, b);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		while (*b != cheapest && *a != cheapest->target_node)
			reverse_rotate_ab(a, b);
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rotate_b(b);
		else
			reverse_rotate_b(b);
	}
	while (*a != cheapest->target_node)
	{
		if ((cheapest->target_node)->above_median)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	push_a(a, b);
}

void	ft_sort(t_stack **a)
{
	t_stack	**b;

	b = malloc(sizeof(t_stack *));
	if (b == NULL)
		return ;
	*b = NULL;
	if (stack_size(*a) == 2)
		swap_a(a);
	while (stack_size(*a) > 3)
		push_b(a, b);
	ft_sort_three(a);
	while (*b)
	{
		ft_initialisation(*a, *b);
		ft_push(a, b);
	}
	if (find_smallest(*a)->above_median)
		while (*a != find_smallest(*a))
			rotate_a(a);
	else
		while (*a != find_smallest(*a))
			reverse_rotate_a(a);
	free(b);
}
