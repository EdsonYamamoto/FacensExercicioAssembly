
#include "stdafx.h"

class Recursivo
{
public:
	int fatorialRecursivo(int);
	int fatorialRecursivo1(int);
	void Exercicio1Recursivo();
	void Exercicio2Recursivo();
private:

};


int Recursivo::fatorialRecursivo1(int num)
{
	int n = num;
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
			mul ebx
			jmp ver

			fimop :
		pop edi
			pop esi
			pop ebx
			pop ebp
			ret
			fim :

	}

	printf("Resultado %d\n", res);
	getchar();

	return res;
}
void Recursivo::Exercicio2Recursivo()
{
	printf("Exercicio 2-------------------------------------------");
	int A, B, C, res;
	A = 1;
	B = 4;
	C = 3;


	__asm {
		mov eax, A
		mov ebx, B
		mov ecx, C
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
			fim :
	}


	printf("Resultado: %i\n", res);
	getchar();
	return;
}
void Recursivo::Exercicio1Recursivo()
{
	int *a = new int();
	int *b = new int();
	*a = 2;
	*b = 4;

	__asm {
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
			mov ebx, eax
			mov[ebp + 12], ecx
			mov[ebp + 8], ebx

			pop edi
			pop esi
			pop ebx
			pop ebp
			ret
			fim :
	}

	printf("A %d B %d \n", *a, *b);
	getchar();
	return;
}

int Recursivo::fatorialRecursivo(int num)
{
	int n = num;
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

	printf("Resultado %d\n", res);
	getchar();

	return res;
}
int main()
{
	Recursivo recursivo;
	//recursivo.teste();
	//recursivo.deltaBascara(1, 2, 3);
	recursivo.Exercicio2Recursivo();
	recursivo.fatorialRecursivo(3);
	recursivo.fatorialRecursivo1(6);
	return 0;
}

