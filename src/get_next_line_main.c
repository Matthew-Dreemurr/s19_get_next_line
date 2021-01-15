/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             ++  +:+       ++        */
/*                                                ++++++   ++           */
/*   Created: 2021/01/02 15:41:33 by mhadad            +    +             */
/*   Updated: 2021/01/15 15:57:08 by mhadad              .fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#ifndef TXT
# define TXT "ERROR"
#endif
#ifndef LOOP
# define LOOP 1
#endif

int	gnl_test(int fd)
{
	char		*line;
	int			ret;

	ret = 0;
	//* Call GNL *//

	printf("\n[---[GNL: start]---]\n");
	ret = get_next_line(fd, &line);
	printf("GNL return |%d|\n", ret);
	if (ret == -1)
	{
		printf(RED "/!\\ [{Error}_check_error]: Return fonction = -1 /!\\\n" RESET);
	}
	if (ret == 0)
	{
		printf(GRN "[{OK}_get_next_line]\n\n\n" RESET);
	}
	printf("line read = |%s|\n", line);
	printf("[---[GNL: stop]---]\n");
	free(line);
	return (ret);
}

int	main()
{
	int	loop;
	int	fd;
	int	ret;
	int	i;

	loop = LOOP;
	ret = 0;
	i = 0;
		//* Check open file *//
	if((fd = open(TXT, O_RDONLY)) == -1)
	{
		printf(RED "/!\\ [{Error}_main]: Open " TXT " fd = |%d|/!\\\n" RESET, fd);
		return (0);
	}
	printf(GRN "Open %s successful, File descriptor |%d|\n" RESET, TXT, fd);
	printf(YEL "Reading file |%s| whit the buffer size limit of |%d|oct\n" RESET, TXT, BUFFER_SIZE);
	if (!(strcmp(TXT, "ERROR")))
	{
		printf(RED "/!\\ [{Error}_main]: Please add DEF = -D TXT=\"FILE_NAME\" to the Makefile /!\\\n" RESET);
		return (0);
	}
	while(i < loop)
	{
		printf(YEL "\n[=====[Loop nbr %d]=====]\n" RESET, i);
		ret = gnl_test(fd);
		if (ret == -1)
		{
			printf(RED "[======[ERROR]======]" RESET);
			break;
		}
		else if (!ret)
		{
			printf(GRN "[======[EOF]======]" RESET);
			break;
		}
		i++;
	}
	return (0);
}