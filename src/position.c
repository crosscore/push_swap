/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:26:20 by mcombeau          #+#    #+#             */
/*   Updated: 2023/02/19 00:23:35 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	assign_positions:
スタックの各要素に、上から下に昇順でpositionを割り当てます。
Example stack:
	value:		 3	 0	 9	 1
	index:		[3]	[1]	[4]	[2]
	position:	<0>	<1>	<2>	<3>
positionは特定の数値を特定の位置に移動するコスト計算に使用されます。
上記の例がスタックBである場合、最初の要素をスタックAにプッシュするのにコストはかかりません(0)。
しかし、3番目の位置にある最高値9をプッシュしたい場合、
スタックAにプッシュする前に、その9をBの最上部に移動するには2回rbするため、コスト2が必要です。*/
static void	assign_positions(t_stack **stack)
{
	t_stack	*tmp;
	size_t	i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_position_of_minimum_index:
スタック内の最小のindexを持つ要素の現在のpositionをreturnします。*/
int	get_position_of_minimum_index(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		min_index_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	assign_positions(stack);
	min_index_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			min_index_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_index_pos);
}

/* get_target_position:
スタックBのインデックス(b_index)に対して、スタックA内の最適なtarget positionを選択します。
最初に、より大きなインデックスを持つ要素がスタックAにあるかどうかチェックすることで、
B要素のインデックスをスタックAの要素間のどこに配置できるかをチェックします。
そうでない場合は、Aで最小のインデックスを持つ要素を見つけて、それをターゲット位置として割り当てます。
--- Example:
target_posは INT_MAX から開始されます
	B index: 3
	A contains indexes: 9 4 2 1 0
	9 > 3 && 9 < INT_MAX 	: target_pos updated to 9
	4 > 3 && 4 < 9 			: target pos updated to 4
	2 < 3 && 2 < 4			: no update!
最終的に target_pos は最も近いindex 4のpositionに決定され、returnされます。
--- Example:
	target_pos starts at INT_MAX
	B index: 20
	A contains indexes: 16 4 3
	16 < 20					: no update! target_pos = INT_MAX
	4  < 20					: no update! target_pos = INT_MAX
	3  < 20					: no update! target_pos = INT_MAX
b_indexがAのどの数値よりも大きい場合は、target_pos が INT MAXのままとなるため、
stackAの最小のindexを持つ要素のpositionをターゲット位置とする戦略に切り替えます。
	16 < 20					: target_pos updated to 20
	4  < 20					: target_pos updated to 4
	3  < 20					: target_pos updated to 3
この計算により最小のindex 3のpositionがリターンされます。*/
static int	get_target_position(t_stack **a, int b_index,
									int target_index, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* set_target_position:
スタックAのtarget_posをスタックAの各t_stackに割り当てます。
target_posは、Bの要素が正しくソートされるために到達する必要がある場所です。
このtarget_posは、各要素をスタックAのtarget_posに移動するコストを計算するために使用されます。*/
void	set_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	assign_positions(a);
	assign_positions(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target_position(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
