/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:40:26 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/05 01:27:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>


int get_random_int(int	x);

int main(void)
{
	printf("random int: %d\n", get_random_int(10));
	return (0);
}
int get_random_int(int	x)
{
    int random_int;

    int fd = open("/dev/random", O_RDONLY);
    if (fd < 0)
	{
        perror("Failed to open /dev/random");
        exit(EXIT_FAILURE);
    }
	random_int = 0;
	while(1)
	{
		if (read(fd, &random_int, sizeof(int)) < 0)
		{
			perror("Failed to read from /dev/random");
			exit(EXIT_FAILURE);
		}
		if (random_int <= x && random_int >= 0)
			break;
	}
	if (random_int < 0)
		random_int *= -1;
    close(fd);
    return (random_int);
}
