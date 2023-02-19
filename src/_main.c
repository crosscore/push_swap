/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:06:46 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/19 23:21:13 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* is_sorted:
スタックがソートされているかどうかを確認します。
スタックがソートされていない場合は0を返し、ソートされている場合は1を返します。
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
ソートする値の数に応じてソート方法を選択します。
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		three_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	free_new_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**new_argv;
	int		new_argc;

	if (argc < 2)
		return (1);
	new_argv = split_args(argv, &new_argc);
	if (!is_input_formatted_correctly(new_argv))
	{
		free_new_argv(new_argv);
		display_error_and_exit(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = create_stack_from_argv(new_argc, new_argv);
	stack_size = calculate_stack_size(stack_a);
	set_index_values(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_new_argv(new_argv);
	return (0);
}

/*
__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q push_swap");
}
*/