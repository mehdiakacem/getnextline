/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:50:04 by makacem           #+#    #+#             */
/*   Updated: 2022/01/20 17:48:13 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count(char	*str)
{
	int		i;
	
	i = 0;
	while(*str && *str != '\n')
	{
		str++;
		i++;
	}
	return (i + 1);
}


char	*get_next_line(int	fd)
{
	char		*LINE;
	char		*BUFFER;
	char		*BIG_BUFFER;
	// int			BUFFER_SIZE;
	int			read_retrun_value;
	static char	*temp_BUFFER;

	// BUFFER_SIZE = 1;
	BIG_BUFFER = ft_calloc(1, sizeof(char));
	while(!(ft_strchr(BUFFER, '\n')) && read_retrun_value != 0)
	{
		BUFFER = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		// if (!BUFFER)
		// 	return 0;
		read_retrun_value = read(fd, BUFFER, BUFFER_SIZE);
		BIG_BUFFER = ft_strjoin(BIG_BUFFER, BUFFER);
		free(BUFFER);
	}
	if(temp_BUFFER != NULL)
	{
		BIG_BUFFER = ft_strjoin(temp_BUFFER, BIG_BUFFER);
		free(temp_BUFFER);
	}
	LINE = ft_calloc(ft_strlen(BIG_BUFFER) + 1, sizeof(char));
	ft_strlcpy(LINE, BIG_BUFFER, ft_strlen(BIG_BUFFER) + 1);
	temp_BUFFER = ft_calloc(1, sizeof(char));
	ft_strlcpy(temp_BUFFER, BIG_BUFFER + ft_strlen(BIG_BUFFER), 1);
	free(BIG_BUFFER);
	return (LINE);
}
