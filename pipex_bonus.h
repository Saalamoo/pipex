/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:04:37 by saalamoo          #+#    #+#             */
/*   Updated: 2024/01/29 15:44:45 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "./libft/libft.h"

# ifndef MAX_PATH_LENGTH
#  define MAX_PATH_LENGTH 1024
# endif

void	len_path(char **paths, char *command_path, char *command, int i);
void	exec_error(char *path, char **split_cmd, char **envp);
char	*result_path(char **paths, char *command, char *command_path);
char	*find_command_path(char *command, char **envp);
void	fork_err_bonus(pid_t pid, int fd1, int fd2, int w);
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	error(int w);
char	*get_next_line(void);
void	close_fds(int fd1, int fd2);
int		open_file(char *argv, int i, int fd);
void	child_process(char *argv, char **envp, int w);
void	deli_line(char *line, char *delimiter, int fd);
void	here_doc(int argc, char *delimiter);

#endif