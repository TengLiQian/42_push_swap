/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:09:54 by lteng             #+#    #+#             */
/*   Updated: 2024/03/08 16:22:31 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	temp_a = *a;
	*a = (*a)->next;
	temp_a->next = (*a)->next;
	(*a)->next = temp_a;
	temp_b = *b;
	*b = (*b)->next;
	temp_b->next = (*b)->next;
	(*b)->next = temp_b;
	write(1, "ss\n", 3);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	temp_a = ft_last_node(*a);
	temp_a->next = *a;
	*a = (*a)->next;
	temp_a->next->next = NULL;
	temp_b = ft_last_node(*b);
	temp_b->next = *b;
	*b = (*b)->next;
	temp_b->next->next = NULL;
	write(1, "rr\n", 3);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*last_node_a;
	t_stack	*second_last_node_a;
	t_stack	*last_node_b;
	t_stack	*second_last_node_b;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last_node_a = ft_last_node(*a);
	second_last_node_a = ft_second_last_node(*a);
	last_node_a->next = *a;
	*a = last_node_a;
	second_last_node_a->next = NULL;
	last_node_b = ft_last_node(*b);
	second_last_node_b = ft_second_last_node(*b);
	last_node_b->next = *b;
	*b = last_node_b;
	second_last_node_b->next = NULL;
	write(1, "rrr\n", 4);
}
