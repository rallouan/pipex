/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:13:41 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/27 14:49:26 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//finds the line where PATH= can be found
//returns the position after that;
char	*path_parsing(char **env)
{
	int		i;
	int		j;
	char	*path;

	path = "PATH";
	i = 0;
	while (env[i])
	{
		j = 0;
		while (path[j] && path[j] == env[i][j])
		{
			if (! path[j + 1])
				return (&env[i][j + 1]);
			j++;
		}
		i++;
	}
	return (NULL);
}
