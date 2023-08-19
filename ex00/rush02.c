/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:56:35 by vwildner          #+#    #+#             */
/*   Updated: 2023/08/19 15:32:57 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

void	ft_putchar(char c);

/*
	Essa função é prefixada com `static` porque ela só é usada nesse arquivo.
	Essa função é responsável por tratar erros de argumentos.
	Se algum dos argumentos for menor que 1 ou maior que INT_MAX, a função
	retorna 1, caso contrário retorna 0.
	A função é implementada desse jeito porque não queremos mostrar
	nada na tela se acontecer um erro de entrada, mas também não queremos
	que o programa pare de funcionar.

	Vamos explicar cada uma das exceções:
		- Se x ou y for menor que 1, o retângulo não existe.
		- Se x ou y for maior que INT_MAX, o retângulo é muito grande.
		- Se x ou y for menor que INT_MIN, o retângulo é muito pequeno.
*/
static int	raises_error(int x, int y)
{
	if (x < 1 || y < 1 || x > INT_MAX
		|| y > INT_MAX || x < INT_MIN || y < INT_MIN)
		return (1);
	return (0);
}

/*
	Essa função é prefixada com `static` porque ela só é usada nesse arquivo.
	Essa é a função responsável por imprimir uma linha do retângulo.
	Se o retângulo tiver apenas uma coluna, a função imprime apenas o
	caractere de início.
	Se o retângulo tiver duas colunas, o caractere de início e o caractere
	de fim são impressos.
	Se o retângulo tiver mais de duas colunas, o caractere de início é
	impresso, o caractere central é impresso a quantidade de vezes
	correspondente ao número de colunas menos 2, e o caractere de fim é
	impresso.

	Ao final de cada linha, a função acrescenta uma quebra de linha.
*/
static void	print_line(char start, char center, char end, int columns)
{
	if (columns < 2)
	{
		ft_putchar(start);
		ft_putchar('\n');
		return ;
	}
	ft_putchar(start);
	while (columns-- > 2)
		ft_putchar(center);
	ft_putchar(end);
	ft_putchar('\n');
}

/*
	Essa é a função principal, ela é responsável por imprimir o retângulo
	O parâmetro x é a quantidade de colunas e o parâmetro y é a quantidade de
	linhas.

	Exemplo:
		rush(5, 3);
	Imprime:
		ABCDE
		B   B
		ABCDE

	Vamos entender cada passo do programa faz:
		- Inicialmente o programa joga a responsabilidade de erros de entrada
		para a função `raises_error`, se tudo tiver ok ele continua. Do
		contrário, ele finaliza imediatamente.
		- A seguir a primeira linha do programa é impressa.
		- Se o retângulo tiver apenas uma linha, o programa termina.
		- Se o retângulo tiver duas linhas, a segunda linha é impressa e o
		programa termina.
		- Se o retângulo tiver mais de duas linhas, o programa entra em um
		loop que imprime a linha central do retângulo até que a quantidade de
		linhas restantes seja igual a 2. Ele faz isso aproveitando a variável y
		que foi passada como parâmetro.
		Vamos entender melhor como dá pra aproveitar `y`:
			- Se o retângulo tiver 3 linhas, o loop é executado apenas uma vez.
			- Se o retângulo tiver 4 linhas, o loop é executado duas vezes.
			- Se o retângulo tiver 5 linhas, o loop é executado três vezes.
			- Se o retângulo tiver 6 linhas, o loop é executado quatro vezes.
			- E assim por diante...
		- Ao final do programa, a última linha do retângulo é impressa.

*/
void	rush(int x, int y)
{
	if (raises_error(x, y))
		return ;
	print_line('A', 'B', 'A', x);
	if (y == 1)
		return ;
	print_line('B', ' ', 'B', x);
	if (y == 2)
		return ;
	while (--y > 2)
		print_line('B', ' ', 'B', x);
	print_line('C', 'B', 'C', x);
}
