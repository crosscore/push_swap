/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:31:04 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/19 20:48:29 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* create_stack_from_argv:
コマンドラインから入力された値でstack_aを埋めます。
値が整数の範囲外の場合は、エラーを出力してプログラムを終了します。*/
t_stack	*create_stack_from_argv(int argc, char **argv)
{
	t_stack			*stack_a;
	long long int	n;
	int				i;

	stack_a = NULL;
	n = 0;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_new_argv(argv);
			display_error_and_exit(NULL, NULL);
		}
		if (i == 1)
			stack_a = create_new_stack((int)n);
		else
			stack_add_tail(&stack_a, create_new_stack((int)n));
		i++;
	}
	return (stack_a);
}

/* set_index_values:
スタックAのvaluesにindexを割り当てます。
実際の値の代わりにindexをチェックして順序を比較できます。
	ex. values:		-3	 0	 9	 2
	indexes:		[1]	[2]	[4]	[3]
indexは、最大 (stack_size) から最小 (1) まで割り当てられます。*/
void	set_index_values(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*maximum;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		maximum = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				maximum = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (maximum != NULL)
			maximum->index = stack_size;
	}
}
