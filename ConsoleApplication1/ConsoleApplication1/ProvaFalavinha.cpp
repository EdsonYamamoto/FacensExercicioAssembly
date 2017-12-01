#include "stdafx.h"

/********************************** PROVA FALAVINHA *******************************/
int somar_valor_entre_dois_numeros()
{
	int x = 1, y = 16, i = 0, m = 0;

	__asm
	{
		mov ecx, i
		mov eax, x
		mov ebx, y
		mov m, eax

		inicio :
		cmp eax, y
			je fim
			cmp ecx, 9
			je fim
			add eax, 1
			add m, eax


			add ecx, 1
			jmp inicio

			fim :
	}

	printf("%i\n\n", m);


	system("pause");
	return 0;
}
/*
3) Grande quantidade de registradores é uma característica de uma arquitetura RISC ou CISC ? Explique se isso traz vantagem ou não.
É uma característica da arquitetura RISC.Estudos indicam que as chamadas de funções consomem um tempo significativo do processador e na RISC essas chamadas são feitas dentro do processador utilizado registradores fazendo assim uma passagem de parâmetros mais eficiente.
*/
/*
5)
Cluster –
Maior divisibilidade de processamento
Maior eficácia
Se uma cpu falhar, o nó é desabilitado
Superior em relação a escalabilidade
Superior em relação a disponibilidade, todos os componentes do sistema são redundantes
SMP –
Maior volume de processamento
Maior eficiência
Se uma CPU falar, o sistema sai do ar
Requer menos espaço físico e menos energia
Mais próximo do modelo de único processador para o qual a maior parte de aplicações foi escrita
*/