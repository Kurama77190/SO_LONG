/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:22:57 by sben-tay          #+#    #+#             */
/*   Updated: 2024/05/06 18:26:24 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_test(t_game_data *data);


int	main(void)
{
	t_game_data	game_data;

	char		**test;
	int			i;

	game_data.memory_data = NULL;
	i = 0;
	test = ft_split("1 2 3 4 5 6 7 8 9 10", ' ', &game_data.memory_data);
	if (!test)
		return (0);
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
	char *test1 = ft_calloc(10, sizeof(char), game_data.memory_data);
	if (!test1)
		return (0);
	test1 =  "987654321";
	printf("%s\n", test1);
	char *test2 = ft_calloc(10, sizeof(char), game_data.memory_data);
	if (!test2)
		return (0);
	test2 = "123456789";
	printf("%s\n", test2);
	ft_test(&game_data);
	ft_free_all(&game_data.memory_data);
	printf("Hello, world!\n");
	return (0);
}

void	ft_test(t_game_data *data)
{
	t_garbage	*current;

	current = data->memory_data;

	char *test1 = ft_calloc(10, sizeof(char), current);
	if (!test1)
		return ;
	test1 = "je suis\n";
	while (*test1)
	{
		printf("%c", *test1);
		test1++;
	}
	return ;
}
