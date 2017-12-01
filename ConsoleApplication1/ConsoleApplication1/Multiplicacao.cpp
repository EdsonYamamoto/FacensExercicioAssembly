#include "stdafx.h"

void multiplicacao()
{
	int m = 10, n = 10, res;

	__asm
	{
		mov eax, m
		mov ebx, n
		push eax
		push ebx
		call MULTIR
		mov res, eax
		pop ebx
		pop eax
		jmp FIM

		MULTIR :
		push ebp
			mov ebp, esp
			sub esp, 8
			push ebx
			push esi
			push edi

			IFCONDITION :
		mov eax, [ebp + 8]
			cmp eax, 0
			je IF
			JMP ELSE
			IF :
		mov eax, 0
			mov[ebp - 4], eax
			jmp RETORNO
			ELSE :

		mov eax, [ebp + 12]
			mov ebx, [ebp + 8]
			sub ebx, 1
			push eax
			push ebx
			call MULTIR
			mov[ebp - 8], eax
			add eax, [ebp + 12]
			mov[ebp - 4], eax
			pop eax
			pop ebx

			RETORNO :

		mov eax, [ebp - 4]

			pop edi
			pop esi
			pop ebx
			add esp, 8
			pop ebp
			ret
			FIM :



	}

	printf("%i\n", res);
}