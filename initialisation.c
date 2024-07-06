/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:00 by lteng             #+#    #+#             */
/*   Updated: 2024/03/20 21:18:40 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Set the current position of the nodes within the stack
void	set_position(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->current_pos = pos;
		if (pos <= stack_size(stack) / 2)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		pos++;
	}
}

// Set the target node in A that nodes in B stack should be linked to
void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_a;
	int		closest_big_a;

	while (b)
	{
		target_a = NULL;
		closest_big_a = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->nbr > b->nbr) && (current_a->nbr < closest_big_a))
			{
				closest_big_a = current_a->nbr;
				target_a = current_a;
			}
			current_a = current_a->next;
		}
		if (target_a == NULL && b->nbr > max_nbr(a))
			b->target_node = find_smallest(a);
		else
			b->target_node = target_a;
		b = b->next;
	}
}

// Cost above median is just the index/pos
// Cost below median is the stack size - index/pos
// Total price = cost in stack b + cost in stack a
void	set_price(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (b->above_median)
			b->cost = b->current_pos;
		else
			b->cost = size_b - b->current_pos;
		if (b->target_node->above_median)
			b->cost += b->target_node->current_pos;
		else
			b->cost += size_a - (b->target_node->current_pos);
		b = b->next;
	}
}

// Set the cheapest node in B as true
void	set_cheapest(t_stack *b)
{
	int		min_cost;
	t_stack	*current_b;

	min_cost = INT_MAX;
	current_b = b;
	while (current_b)
	{
		if (current_b->cost < min_cost)
			min_cost = current_b->cost;
		current_b = current_b->next;
	}
	while (b)
	{
		if (b->cost == min_cost)
			b->cheapest = true;
		else
			b->cheapest = false;
		b = b->next;
	}
}

void	ft_initialisation(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
