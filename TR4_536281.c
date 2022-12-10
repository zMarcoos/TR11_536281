#include "ordvetor.h"

//Função para criar o vetor ordenado com tamanho n e função de comparação
VETORORD* VETORD_create(int n, COMP* compara) {
	VETORORD* vector = malloc(sizeof(VETORORD));
	vector->elems = malloc(n * sizeof(void*));
	vector->N = n;
	vector->P = 0;
	vector->comparador = compara;
	return vector;
}

//Função para adicionar um elemento ao vetor ordenado (se houver espaço) e ordenar o vetor de acordo com a função de comparação
void VETORD_add(VETORORD* vector, void* newElement) {
	if (vector->P < vector->N) {
		int position = vector->P, index;

		for (index = 0; index < vector->P; index++) {
			if (vector->comparador(vector->elems[index], newElement) == -1) {
				position = index;
				break;
			}
		}

		for (index = vector->P; index > position; index--) {
			vector->elems[index] = vector->elems[index - 1];
		}

		vector->elems[position] = newElement;
		vector->P++;
	}	
}

//Função para remover o menor elemento do vetor ordenado e reordenar o vetor de acordo com a função de comparação
void* VETORD_remove(VETORORD* vector) {
  void* minimum = vector->elems[0];

	for (int index = 0; index < vector->P - 1; index++) {
		vector->elems[index] = vector->elems[index + 1];
	}

	vector->P--;

	return minimum;
}