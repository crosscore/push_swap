/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:34:27 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/19 00:23:11 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* rev_rotate_both:
スタックAとBのいずれかが所定の位置に来るまで、スタックAとBの両方を逆回転させます。
両方のポジションがそれぞれのスタックの下半分にあるため、指定されたコストは負です。
スタックが回転するにつれてコストが増加し、片方が0に達するまで、
スタックは可能な限り回転し、最上部の位置は正しくなります。*/
static void	rev_rotate_both(t_stack **a, t_stack **b,
											int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

/* rotate_both:
スタックAとBのいずれかが配置されるまで両方を回転させます。
両方のポジションがそれぞれのスタックの上半分にあるため、指定されたコストは正です。
スタックがローテーションされるとコストが減少し、片方が0に達するまで、
スタックは可能な限り回転し、最上部の位置は正しくなります。*/
static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/* rotate_a:
所定の位置になるまでスタックAを回転させます。
コストが負の場合、スタックは逆回転し、正の場合は回転します。*/
static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/* rotate_b:
所定の位置になるまでスタックBを回転させます。
コストが負の場合、スタックは逆回転し、正の場合は回転します。*/
static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/* move:
Bスタックの要素をスタックAの正しいpositionに移動するための方法を選択します。
スタックAとBを位置に移動するコストが一致する場合 (両方のコストが負または正)、
両方が同時に回転または逆回転します。
同時回転できる間は同時回転し、終わり次第それぞれのシングル回転に移行します。
両方の回転が完了したら、最終的に一番上のB要素を一番上のスタックAにプッシュ（pa）されます。*/
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b);
}
