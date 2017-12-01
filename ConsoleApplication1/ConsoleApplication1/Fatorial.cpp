#include "stdafx.h"

void Fatorial() {
	int n = 3;
	int res = 0;
	__asm {
		mov eax, n
		push eax
		call fatorial
		mov res, eax
		jmp fim

		fatorial :
		push ebp
			mov ebp, esp
			push ebx
			push esi
			push edi

			mov ebx, [ebp + 8]
			mov eax, ebx

			ver :
		sub ebx, 1
			cmp ebx, 0
			je fimop
			push ebx
			call fatorial
			pop ebx
			add ebx, 1
			mul ebx

			fimop :
		pop edi
			pop esi
			pop ebx
			pop ebp
			ret
			fim :

	}
	printf("Resultado: %d\n", res);

}