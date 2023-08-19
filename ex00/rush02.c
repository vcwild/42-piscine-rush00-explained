#include <limits.h>

void	ft_putchar(char c);

/*
	Essa função é responsável por tratar erros de argumentos.
	Não queremos mostrar nada na tela se acontecer um erro de entrada,
	mas também não queremos que o programa pare de funcionar.

	A função retorna (1) quando encontra um erro porque é mais fácil
	verificar se a função retornou (1) do que verificar se a função
	retornou (0) e depois verificar se o programa está funcionando
	corretamente.

	Observe o exemplo:
		if (raises_error(x, y))
			return ;
	Se a função retornar (1), o programa vai parar de executar porque ele
	encontrou um erro (raises an error).
	Se a função retornar (0), o programa vai continuar executando.

	Vamos explicar cada uma das exceções:
		- Se x ou y for menor que 1, o retângulo não existe.
		- Se x ou y for maior que INT_MAX, o retângulo é muito grande.
		- Se x ou y for menor que INT_MIN, o retângulo não existe.
	Essa função é prefixada com `static` porque ela só é usada nesse arquivo.
*/
static int	raises_error(long long int x, long long int y)
{
	return (x < 1 || y < 1 || x > INT_MAX || y > INT_MAX);
}

/*
	Essa é a função responsável por imprimir uma linha do retângulo.
	Se o retângulo tiver apenas uma coluna, a função imprime apenas o
	caractere de início.
	Se o retângulo tiver duas colunas, o caractere de início e o caractere
	de fim são impressos.
	Se o retângulo tiver mais de duas colunas, o caractere de início é
	impresso, o caractere central é impresso a quantidade de vezes
	correspondente ao número de colunas menos 2, e o caractere de fim é
	impresso.

	A linha 	while (columns-- > 2)
	é equivalente a:
		while (columns > 2)
		{
			columns--;
			ft_putchar(center);
		}
	Isso significa que a variável `columns` é decrementada até que ela seja
	igual a 2 e então finaliza o loop.
	A variável columns é decrementada porque ela é a quantidade de colunas

	Enquanto a gente tiver mais de duas colunas, a gente imprime o caractere
	central e decrementa a quantidade de colunas. Isso faz sentido porque
	quando a gente tiver apenas duas colunas, a gente não precisa imprimir
	o caractere central, a gente só precisa imprimir o caractere de início e
	o caractere de fim.

	Exemplo:
	columns = 2
	Imprimimos o caractere de início e o caractere de fim.
	columns = 3
	Imprimimos o caractere de início, o caractere central uma vez e o
	caractere de fim.
	columns = 4
	Imprimimos o caractere de início, o caractere central duas vezes e o
	caractere de fim.

	Ao final de cada linha, a função acrescenta uma quebra de linha.
	Essa função é prefixada com `static` porque ela só é usada nesse arquivo.

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
		ABBBA
		B   B
		CBBBC

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
