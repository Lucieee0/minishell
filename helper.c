/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:14 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 17:22:16 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void	free_array(char **input_array)
{
	int	i;

	i = 0;
	if (!input_array)
		return ;
	while (input_array[i])
	{
		free(input_array[i]);
		i++;
	}
	free(input_array);
}

void	free_env(t_env **env)
{
	t_env	*current;
	t_env	*before_current;

	current = *env;
	before_current = *env;
	while (current)
	{
		before_current = current;
		current = current->next;
		free(before_current->str);
		free(before_current);
	}
	*env = NULL;
}
