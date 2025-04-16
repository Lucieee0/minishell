/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:51:33 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/14 13:56:30 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void	ft_pwd(void)
{
	char	buffer[1024];

	if (getcwd(buffer, 1024) == NULL) //function copies the absolut path name
	{
		perror("getcwd");
		exit(errno);
	}
	printf("%s\n", getcwd(buffer, 1024));
	// exit(EXIT_SUCCESS);
}
