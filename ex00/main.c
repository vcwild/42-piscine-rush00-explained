#include <stdio.h>

/*
	É necessário declarar a função `rush` antes de usá-la porque ela só é
	implementada mais depois no arquivo `rush02.c`, porém o compilador ainda
	não sabe disso e vai dar erro se não declararmos a função antes.
	Precisamos sempre avisar o compilador sobre as funções que vamos usar.
	Essa declaração aqui nós costumeiramente chamamos de "protótipo" da função,
	porque ela é uma prévia da função que vamos usar, mas não é a função em si.
*/
void	rush(int x, int y);

/*
	Esse é o programa principal, ele é responsável apenas por chamar a função
	`rush` com os argumentos passados pelo usuário.
*/
int	main()
{
	rush(5, 3);
	return (0);
}
