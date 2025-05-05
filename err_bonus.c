/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:09:18 by saalamoo          #+#    #+#             */
/*   Updated: 2024/01/30 15:10:55 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exec_error(char *path, char **split_cmd, char **envp)
{
	int	i;

	if (path == NULL)
	{
		perror("path");
		free(path);
		free_char_array(split_cmd);
		return ;
	}
	if (execve(path, split_cmd, envp) == -1)
	{
		i = 0;
		while (split_cmd[i])
			free(split_cmd[i++]);
		free(split_cmd);
		free(path);
	}
}
