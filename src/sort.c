/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:10 by mcombeau          #+#    #+#             */
/*   Updated: 2023/02/19 00:24:42 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* shift_stack:
スタックの大部分がソートされた後、最小値が最上位になるまでスタックAをrotateします。
mini_index_posを持つ値がスタックの下半分にある場合は、スタックAの一番上になるまでrra。
そうでない場合は、スタックAの一番上になるまでraします。*/
static void	shift_stack(t_stack **stack_a)
{
	int	mini_index_pos;
	int	stack_size;

	stack_size = calculate_stack_size(*stack_a);
	mini_index_pos = get_position_of_minimum_index(stack_a);
	if (mini_index_pos > stack_size / 2)
	{
		while (mini_index_pos < stack_size)
		{
			rra(stack_a);
			mini_index_pos++;
		}
	}
	else
	{
		while (mini_index_pos > 0)
		{
			ra(stack_a);
			mini_index_pos--;
		}
	}
}

/* move_all_to_b_except_3:
最後の3つの要素を除いて、スタックAのすべての要素をスタックBにプッシュします。
小さい値を最初にpbし、次に大きい値をpbすることでソート効率を高めます。*/
static void	move_all_to_b_except_3(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = calculate_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

/* sort:　3より大きいスタックのソートアルゴリズム。
3つの数字を除くすべてをスタックBにプッシュします。
スタックAに残っている3つの数字を並べ替えます。
最も費用対効果の高い移動を計算し、最終的にpaします。
全ての要素のpaが終わったらスタックAが整うまで要素をシフトします。*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	move_all_to_b_except_3(stack_a, stack_b);
	three_sort(stack_a);
	while (*stack_b)
	{
		set_target_position(stack_a, stack_b);
		calculate_move_costs(stack_a, stack_b);
		move_lowest_cost_b_to_a(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
