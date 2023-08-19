/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:02:00 by vwildner          #+#    #+#             */
/*   Updated: 2023/08/19 15:30:39 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Essa função é responsável por imprimir um caractere na tela.
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
