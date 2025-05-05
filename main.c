/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:25:21 by saalamoo          #+#    #+#             */
/*   Updated: 2024/01/30 15:04:28 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_err(pid_t pid)
{
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	error_cmd(char *cmd, char *path)
{
	if (cmd[0] == '\0' || path == NULL)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

void	in_put(int fds[2], char *infile, char *cmd, char **envp)
{
	int		fd;
	pid_t	pid;
	char	*path;
	char	**split_cmd;

	pid = fork();
	fork_err(pid);
	if (pid == 0)
	{
		close(fds[0]);
		fd = open(infile, O_RDONLY);
		if (fd == -1)
		{
			perror("infile");
			exit(0);
		}
		dup2(fd, STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		close(fd);
		split_cmd = ft_split(cmd, ' ');
		path = find_command_path(split_cmd[0], envp);
		exec_error(path, split_cmd, envp);
	}
}

void	out_put(int fds[2], char *outfile, char *cmd, char **envp)
{
	int		fd;
	pid_t	pid;
	char	*path;
	char	**split_cmd;

	pid = fork();
	fork_err(pid);
	if (pid == 0)
	{
		close(fds[1]);
		fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
		{
			perror("outfile");
			exit(0);
		}
		dup2(fds[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		split_cmd = ft_split(cmd, ' ');
		path = find_command_path(split_cmd[0], envp);
		error_cmd(cmd, path);
		exec_error(path, split_cmd, envp);
		close(fds[0]);
		close(fd);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fds[2];

	if (ac != 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (0);
	}
	if (pipe(fds) == -1)
		perror("pipe");
	in_put(fds, av[1], av[2], envp);
	waitpid(-1, 0, 0);
	out_put(fds, av[4], av[3], envp);
	close(fds[0]);
	close(fds[1]);
	waitpid(-1, 0, 0);
	return (0);
}
