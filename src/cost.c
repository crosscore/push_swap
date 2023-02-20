/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:10:36 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/20 13:10:37 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* move_lowest_cost_b_to_a:
best_move_costを更新することで、
スタックAに移動するためのコストが最も低いスタックB内の要素を見つけ、
それをスタックA内の正しいpositionにmove関数で移動します。*/
void	move_lowest_cost_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		best_move_cost;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	best_move_cost = INT_MAX;
	while (tmp)
	{
		if (absn(tmp->cost_a) + absn(tmp->cost_b) < absn(best_move_cost))
		{
			best_move_cost = absn(tmp->cost_b) + absn(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}

/* calculate_move_costs:
スタックBの各要素をスタックAの正しい位置に移動するコストを計算します。
2つのコストが計算されます。
cost_bは、要素をスタックBの一番上に移動するコストを表します。
cost_aは、スタックAの正しい位置に到達するためのコストを表します。
要素がスタックの下半分にある場合コストは負になり、上半分にある場合コストは正になります。*/
void	calculate_move_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = calculate_stack_size(tmp_a);
	size_b = calculate_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
