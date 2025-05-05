/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:44:23 by saalamoo          #+#    #+#             */
/*   Updated: 2024/01/26 14:59:14 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	len_path(char **paths, char *command_path, char *command, int i)
{
	char	*p;
	char	*q;

	p = command_path;
	q = paths[i];
	while (*q)
		*p++ = *q++;
	*p++ = '/';
	q = command;
	while (*q)
		*p++ = *q++;
	*p = '\0';
}

char	*result_path(char **paths, char *command, char *command_path)
{
	char	*result;
	int		i;

	result = NULL;
	i = -1;
	while (paths[++i])
	{
		len_path(paths, command_path, command, i);
		if (access(command_path, X_OK) == 0)
		{
			result = ft_strdup(command_path);
			break ;
		}
	}
	return (result);
}

char	*find_command_path(char *command, char **envp)
{
	char	**paths;
	char	command_path[MAX_PATH_LENGTH];
	int		i;
	char	*result_f;

	if (command == NULL)
		return (NULL);
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i], ':');
	if (!envp)
		return (NULL);
	result_f = result_path(paths, command, command_path);
	i = 0;
	while (paths[i])
		free (paths[i++]);
	free (paths);
	return (result_f);
}

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
