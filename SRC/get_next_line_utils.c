/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 20:15:56 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *s1;

	s1 = s;
	if (n)
		while (n--)
			s1[n] = 0;
}