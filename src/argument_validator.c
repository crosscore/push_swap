/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:48:31 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/19 14:33:28 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* is_arg_number:
引数が数値かどうかをチェックします。 +1 1 -1 はすべて有効な数値です。
戻り値: 引数が数値の場合は 1、そうでない場合は 0。*/
static int	is_arg_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

/* has_duplicates:
引数リストに重複する数字があるかどうかを確認します。
戻り値: 重複がある場合は1、ない場合は0。*/
/*
static int	has_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && str_num_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
*/

static int	has_duplicates(char **argv)
{
	int	i;
	int	j;

	if (!argv)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (str_num_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* is_arg_zero:
0 +0 -0 と 0 0000 +000 -00000000 の重複を避けるために、引数が 0 であることを確認します。
戻り値: 引数がゼロの場合は 1、ゼロ以外のものが含まれている場合は0。*/
static int	is_arg_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* is_input_formatted_correctly:
指定された引数がすべて数値であり、重複がないかどうかを確認します。
戻り値: 引数が有効な場合は1、そうでない場合は0。*/
int	is_input_formatted_correctly(char **argv)
{
	int	i;
	int	nb_zeros;

	if (!argv)
		return (0);
	nb_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!is_arg_number(argv[i]))
			return (0);
		nb_zeros += is_arg_zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (has_duplicates(argv))
		return (0);
	return (1);
}
