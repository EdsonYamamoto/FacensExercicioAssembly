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
3) Grande quantidade de registradores � uma caracter�stica de uma arquitetura RISC ou CISC ? Explique se isso traz vantagem ou n�o.
� uma caracter�stica da arquitetura RISC.Estudos indicam que as chamadas de fun��es consomem um tempo significativo do processador e na RISC essas chamadas s�o feitas dentro do processador utilizado registradores fazendo assim uma passagem de par�metros mais eficiente.
*/
/*
5)
Cluster �
Maior divisibilidade de processamento
Maior efic�cia
Se uma cpu falhar, o n� � desabilitado
Superior em rela��o a escalabilidade
Superior em rela��o a disponibilidade, todos os componentes do sistema s�o redundantes
SMP �
Maior volume de processamento
Maior efici�ncia
Se uma CPU falar, o sistema sai do ar
Requer menos espa�o f�sico e menos energia
Mais pr�ximo do modelo de �nico processador para o qual a maior parte de aplica��es foi escrita
*/