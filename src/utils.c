/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:11:41 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/20 13:11:44 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* free_stack:
スタックに含まれる全てのノードを解放することで、メモリリークを防ぐことができます。
tmp変数を使用して、次のノードへのポインタを一時的に保持することで、
スタックの先頭ノードを解放しても、その後ろのノードへのアクセスが失われることを防止しています。
最後に、tmpをNULLにすることで、ポインタの無効なアクセスを防止しています。*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *stack;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}

void	display_error_and_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL && *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/* ft_atoi:
英数字文字列を整数に変換します。*/
long	ft_atoi(const char *str)
{
	long int	nb;
	int			sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

/* absn:
引数の数値の絶対値をリターンします。*/
int	absn(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}
