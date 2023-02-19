/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:41:01 by mcombeau          #+#    #+#             */
/*   Updated: 2023/02/19 00:27:41 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* find_highest_index:
スタック内の最高のインデックスを返します。*/
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* three_sort:
3つの数字のスタックを2回以下の移動で並べ替えます。並べ替えはvalueではなくindexで行われます。
Example:
	values:		 0	 9	 2
	indexes:	[1]	[3]	[2]
最大2回の移動で解決:
rra:
	values:		 2	 0	 9
	indexes:	[2]	[1]	[3]
sa:
	values:		 0	 2	 9
	indexes:	[1]	[2]	[3] */
void	three_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
