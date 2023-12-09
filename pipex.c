/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:45 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/28 20:57:06 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **env)
{
	t_pipex		*pipex;
	pid_t		pid1;
	pid_t		pid2;

	pipex = ft_initialize(argc, argv, env);
	if (! pipex)
		perror("Init fail");
	if (pipe(pipex->pipes) == -1)
		perror("Pipe error");
	pid1 = fork();
	if (pid1 == 0)
		ft_child_one(pipex);
	pid2 = fork();
	if (pid2 == 0)
		ft_child_two(pipex);
	close (pipex->pipes[0]);
	close (pipex->pipes[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	ft_free_pipex(pipex);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		perror("Wrong number of arguments");
	else
		pipex(argc, argv, env);
	return (0);
}
