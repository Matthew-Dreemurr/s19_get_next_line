/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/16 16:46:27 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#ifdef DEBUG
# include <stdio.h>
#endif

/*
**   get_next_line();
**
**   Return :
**      1 =    LRD
**      0 =    EOF
**      -1 =   Error
*/

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	static char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	(void)tmp;
	(void)gnl;
	if (!line)
		return (ERROR);
#ifdef DEBUG
printf(B_YEL "\nThe last buff" RESET " = |%s|\n", buff);
#endif
	if (!(eol_len(buff, 0)))
	{
		
		gnl.ret_read = read(fd, &buff, BUFFER_SIZE);
		buff[gnl.ret_read] = '\0';




#ifdef DEBUG
printf(B_YEL "\nRead buff" RESET " = |%s|\n", buff);
#endif
	}
	else
	{
		/* code */
	}
	
	*line = buff;
	
	return (1);
}
