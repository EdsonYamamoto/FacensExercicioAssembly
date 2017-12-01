#include "stdafx.h"

/*Retorna posição Fibonnaci no indice enviado*/
void fibonnaci()
{
	int n = 8, res;

	__asm
	{
		mov eax, n
		push eax
		call FIB
		mov res, eax
		pop eax
		jmp FIM

		FIB :
		push ebp
			mov ebp, esp
			sub esp, 12
			push ebx
			push esi
			push edi

			IFCONDITION :

		mov ecx, [ebp + 8]
			cmp ecx, 0
			je IF
			cmp ecx, 1
			je IF
			jmp ELSE
			IF :
		mov eax, [ebp + 8]
			mov[ebp - 4], eax
			jmp RETORNO

			ELSE :
		mov eax, [ebp + 8]
			sub eax, 2
			push eax
			call FIB
			mov[ebp - 12], eax
			pop eax
			mov eax, [ebp + 8]
			sub eax, 1
			push eax
			call FIB
			mov[ebp - 8], eax
			pop eax
			mov eax, [ebp - 12]
			add eax, [ebp - 8]
			mov[ebp - 4], eax

			RETORNO :

		mov eax, [ebp - 4]

			pop edi
			pop esi
			pop ebx

			add esp, 12
			pop ebp
			ret

			FIM :

	}

	printf("%i\n", res);
}