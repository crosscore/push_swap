/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:40:30 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/18 18:55:01 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Split Arguments */
char	*ft_strdup(const char *s1);
int		count_words(char *str);
void	free_string_array(char **array, int size);
char	**ft_split(char const *s, char c);
char	**split_args(char **argv, int *new_argc);

/* Argument_validator */
int		is_input_formatted_correctly(char **argv);
int		is_digit(char c);

/* Initialization */
t_stack	*create_stack_from_argv(int ac, char **av);
void	set_index_values(t_stack *stack_a, int ac);
int		isspace(int c);

/* Sorting Algorithms */
void	three_sort(t_stack **stack);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);

/* Position */
int		get_position_of_minimum_index(t_stack **stack);
void	set_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */
void	calculate_move_costs(t_stack **stack_a, t_stack **stack_b);
void	move_lowest_cost_b_to_a(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);

/* Stack Functions */
t_stack	*get_stack_tail(t_stack *stack);
t_stack	*get_stack_before_tail(t_stack *stack);
t_stack	*create_new_stack(int value);
void	stack_add_tail(t_stack **stack, t_stack *new);
int		calculate_stack_size(t_stack	*stack);

/* Utils */
void	free_stack(t_stack **stack);
long	ft_atoi(const char *str);
void	ft_putstr(char *str);
int		absn(int nb);

/* Error */
void	display_error_and_exit(t_stack **stack_a, t_stack **stack_b);

/* Input Check */
int		is_input_formatted_correctly(char **argv);
int		is_digit(char c);
int		is_sign(char c);
int		str_num_cmp(const char *s1, const char *s2);

#endif
