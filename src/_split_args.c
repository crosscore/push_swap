/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _split_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:11:29 by ysakahar          #+#    #+#             */
/*   Updated: 2023/02/19 23:20:25 by ysakahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	split_words(char **argv, char **new_argv, int i, int j)
{
	char	**words;
	int		word_count;
	int		k;

	words = ft_split(argv[j], ' ');
	word_count = count_words(argv[j]);
	k = 0;
	while (k < word_count)
	{
		if (!is_input_formatted_correctly(&words[k]))
		{
			free_string_array(new_argv, i);
			free_string_array(words, word_count);
			display_error_and_exit(NULL, NULL);
		}
		new_argv[i] = ft_strdup(words[k]);
		i++;
		k++;
	}
	free_string_array(words, word_count);
	return (i);
}


char	**split_args(char **argv, int *new_argc)
{
	int		i;
	int		j;
	int		word_count;
	char	**new_argv;

	word_count = 0;
	i = 0;
	while (argv[++i])
		word_count += count_words(argv[i]);
	new_argv = malloc(sizeof(char *) * (word_count + 2));
	if (new_argv == NULL)
		return (NULL);
	new_argv[0] = ft_strdup(argv[0]);
	i = 1;
	j = 0;
	while (argv[++j])
		i = split_words(argv, new_argv, i, j);
	new_argv[i] = NULL;
	*new_argc = i;
	return (new_argv);
}
