/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:51:01 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/14 17:10:00 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

//echo alone returns a new line
//echo | cat -e

//echo -n | cat -e
//no new line

//edge cases 
//echo -nnnnn -nnnnn hello baby
//echo -na
//echo -nnnnnn -na -nn

//pseudo code
//if echo -n or echo -nnnnnn no '\n'
//if only echo '\n'
//if echo -naa '\n'
//if echo hello  hello'\n'

// void	ft_echo(char *input)
// {
// 	printf("%s\n", input);
// }

void	ft_echo(char *input)
{
	char **input_array;
	int				i;

	i = 1;
	input_array = ft_split(input, ' ');
	if (input_array[i] == NULL)
	{
		printf("\n");
		return ;
	}
		
	while (input_array[i] != NULL)
	{
		printf("%s", input_array[i]);
		if (input_array[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
	free(input_array);
}
