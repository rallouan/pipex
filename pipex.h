/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:48 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/28 17:08:28 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/lib.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	int		pipes[2];
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	**env;
}	t_pipex;

//Main function
void		pipex(int argc, char **argv, char **env);

//Util functions
t_pipex		*ft_initialize(int argc, char **argv, char **env);
char		*ft_find_cmd(char **path, char *command);
void		ft_free_pipex(t_pipex *pipex);

//Parsing function
char		*path_parsing(char **env);

//Children functions
void		ft_child_one(t_pipex *pipex);
void		ft_child_two(t_pipex *pipex);

#endif