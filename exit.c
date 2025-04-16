/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:21:39 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/16 16:53:03 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

//clean / free everything
//return error code 0
//exit successfully
//decrease a shell level
//void	ft_exit()

void	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}





// 	t_builtin	*head;
// 	t_env		*env;
// 	char		**env_list;
// 	int			i;

// 	i = 0;
// 	env_list = recreate_env(&env);
// 	// while (env_list[i +1] != NULL)
// 	// {
// 	// 	if (strcmp(env_list[i + 1], "SHLV=") == 0)
// 	// 		printf("%d\n", (int)env_list[i + 1][6]);
// 	// 		// if (((int)env_list[i + 1][6]) > 1)
// 	// 		// 	(int)env_list[i + 1][6] -= 1;
// 	// 	printf("%s\n", env_list[i]);
// 	// 	i++;
// 	// }
// 	free_builtin_list(&head);
// }
