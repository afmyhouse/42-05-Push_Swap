/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:45:26 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/19 12:33:46 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief 			Displays errors when args or process not successful
/// @param		-	void
/// @return	-		ERROR
int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (ERROR);
}

/// @brief 		Get a line (\n terminated) from keyboard
/// @param	-	void
/// @return	-	ERROR
char	*ps_gnl(void)
{
	char	*line;
	char	*action;
	char	*tmp;

	line = ft_calloc(2, sizeof(char));
	action = ft_calloc(1, sizeof(char));
	while (*line != '\n')
	{
		if (read(0, line, 1) > 0)
		{
			tmp = action;
			action = ft_strjoin(action, line);
			if (tmp)
				free(tmp);
		}
		else
			break ;
	}
	if (line)
		free(line);
	return (action);
}
