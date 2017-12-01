#include "stdafx.h"

void troca_valores(int a, int b)
{
	/*int *a = new int(), *b = new int();
	*a = 5;
	*b = 10;*/

	__asm
	{
		mov eax, a
		mov ecx, b
		push eax
		push ecx
		call troca
		pop b
		pop a
		jmp fim

		troca :
		push ebp
			mov ebp, esp
			push ebx
			push esi
			push edi

			mov eax, [ebp + 12]
			mov ecx, [ebp + 8]
			mov[ebp + 12], ecx
			mov[ebp + 8], eax

			pop edi
			pop esi
			pop ebx
			pop ebp
			ret
			fim :

	}

	printf("%i %i\n", a, b);

}