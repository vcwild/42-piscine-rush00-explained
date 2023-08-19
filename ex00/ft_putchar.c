#include <unistd.h>

/*
	Essa função é responsável por imprimir um caractere na tela.
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
