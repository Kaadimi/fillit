/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:59:26 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/01 18:47:25 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 1


int main()
{
	int buf[BUFF_SIZE + 1];
	int ret = 0;
	int backspace;

	while ((ret = read(0, buf, BUFF_SIZE)))
	{

		write(1, buf, 1);
	}
	return(0);
}
