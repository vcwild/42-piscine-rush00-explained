/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:36:49 by vwildner          #+#    #+#             */
/*   Updated: 2023/08/19 15:34:30 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

void	rush(int x, int y);

/*
	Esse é o programa principal, ele é responsável apenas por chamar a função
	`rush` com os argumentos passados pelo usuário.
*/
int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = argv[1][0] - '0';
	y = argv[2][0] - '0';
	rush(x, y);
	return (0);
}
