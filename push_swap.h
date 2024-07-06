/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:41:26 by lteng             #+#    #+#             */
/*   Updated: 2024/03/23 12:13:22 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				current_pos;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

int		max_nbr(t_stack *stack);
int		min_nbr(t_stack *stack);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);

t_stack	*find_smallest(t_stack *stack);
t_stack	*find_cheapest(t_stack *b);

void	ft_sort_five(t_stack **a);
void	ft_sort_three(t_stack **a);
void	ft_push(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a);

void	free_all(char **tab);
void	free_lst(t_stack **lst);

void	set_position(t_stack *stack);
void	set_target_node(t_stack *a, t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	ft_initialisation(t_stack *a, t_stack *b);

void	ft_error(t_stack **lst);
int		ft_num(char *str);
int		ft_atoi_new(char *nptr);
t_stack	*ft_process_split(char *argv[]);
t_stack	*ft_process(int argc, char *argv[]);

int		ft_strcmp(char *a, char *b);
int		ft_duplicate(char *str[]);

t_stack	*ft_new_node(int content);
t_stack	*ft_last_node(t_stack *lst);
t_stack	*ft_second_last_node(t_stack *lst);
void	ft_add_node(t_stack **lst, t_stack *new_node);

void	swap_a(t_stack **a);
void	rotate_a(t_stack **a);
void	reverse_rotate_a(t_stack **a);
void	push_a(t_stack **a, t_stack **b);

void	swap_ab(t_stack **a, t_stack **b);
void	rotate_ab(t_stack **a, t_stack **b);
void	reverse_rotate_ab(t_stack **a, t_stack **b);

void	swap_b(t_stack **b);
void	rotate_b(t_stack **b);
void	reverse_rotate_b(t_stack **b);
void	push_b(t_stack **a, t_stack **b);

#endif
