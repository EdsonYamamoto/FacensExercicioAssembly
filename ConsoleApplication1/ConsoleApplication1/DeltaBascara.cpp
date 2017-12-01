#include "stdafx.h"

int deltaBascara(int a, int b, int c)
{
	int delta, res;
	__asm {
		mov eax, a
		mov ebx, b
		mov ecx, c
		push eax
		push ebx
		push ecx
		call delta
		mov res, eax
		jmp fim

		delta :
		push ebp
			sub  esp, 8
			mov ebp, esp
			push ebx
			push esi
			push edi

			mov[ebp + 8], 4
			mov eax, [ebp + 24]
			mul[ebp + 16]
			mul[ebp + 8]
			mov[ebp + 4], eax
			mov eax, [ebp + 20] //get B
			mul eax
			sub eax, [ebp + 4]

			pop edi
			pop esi
			pop ebx
			add esp, 8
			pop ebp
			ret

			fim:
	}


	return delta;

}