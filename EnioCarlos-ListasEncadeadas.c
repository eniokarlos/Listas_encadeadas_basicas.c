//Listas encadeadas - Enio Carlos - BCC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	char nome[50];
	struct lista * prox;
}Lista;

//Insere elementos na cabeça da lista
Lista * inserir_cab(Lista * L, char name[]){
	Lista * novo = (Lista *) malloc(sizeof(Lista));
	strcpy(novo->nome, name);
	novo->prox = L;
	return novo;
}

//Insere elementos no fim da lista
Lista * inserir_fim(Lista * L, char name[]){
	Lista * novo = (Lista *) malloc(sizeof(Lista));
	strcpy(novo->nome, name);
	novo->prox = NULL;
	if (L == NULL)
		return novo;

	Lista * aux = L;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;
	return L;
}

//Remove o elemnto especificado da lista
Lista * remover (Lista * L, char name[]){
	Lista * aux = L;
	Lista * ant = NULL;
	while(aux != NULL && strcmp(name, aux->nome) != 0){
		ant = aux;
		aux = aux->prox;
	}
	if(aux == NULL){
	printf("Elemento nao encontrado\n");
	return L;
	}
	if (ant == NULL)
		L = aux->prox;
	else 
		ant->prox = aux->prox;
	free(aux);
	return L;
}

//Concatena duas listas em uma
Lista * concat(Lista * L, Lista * R){
	Lista * aux = L;
	Lista * ant = NULL;
	while(aux != NULL){
		ant = aux;
		aux = aux->prox;
	}
	aux = R;
	ant->prox = aux;
	return L;	
}

//Verifica duas listas e retorna uma nova lista com os valores que se repetem
Lista * repts(Lista * L, Lista * R){
	Lista * aux = L;
	Lista * aux2 = R;
	Lista * A = NULL;
	while(aux != NULL){
		while(aux2 != NULL){
			if(strcmp(aux->nome, aux2->nome) == 0){
				A = inserir_cab(A, aux->nome);
			}
			aux2 = aux2->prox;
		}
		aux2 = R;
		aux = aux->prox;
	}
	return A;
}



//Retorna o numero de itens na lista
int qtd(Lista * L){
	Lista * aux = L;
	int i = 0;
	while (aux != NULL)
	{
		i++;
		aux = aux->prox;
	}
	return i;
}

//Retorna a posicao de um item na lista
int posicao(Lista * L, char nome[]){
	Lista * aux = L;
	int len = qtd(L);
	while(aux != NULL && strcmp(aux->nome, nome) != 0){
		aux = aux->prox;
		len--;
	}
	return len;
}

//Remove uma quantidade q de itens da lista
Lista * rem_qtd (Lista* L, int q){
	Lista * aux = L;
	while(q > 0){
		L = aux->prox;
		free(aux);
		aux = L;
		q--;
	}
	return L;
}

//Insere um novo valor na lista caso ele nao exista
Lista * inserir_nome(Lista* L, char nome[]){
	Lista * aux = L;
	while (aux != NULL && strcmp(aux->nome, nome) != 0){
		aux = aux->prox;
	}
	if (aux == NULL)
		L = inserir_cab(L,nome);
	else
		printf("nome ja existe!\n");
	return L;
}

//Insere os valores na lista em ordem alfabética
Lista * inserir_ordem(Lista * L, char nome[]){
	Lista * novo = (Lista *) malloc(sizeof(Lista));
	strcpy(novo->nome, nome);
	Lista * aux = L;
	Lista * ant = NULL;
	int i = 0;
	while(aux != NULL && aux->nome[i] <= nome[i]){
		if(aux->nome[i] == nome[i]){
			i++;
		}else{
			ant = aux;
			aux = aux->prox;
		}
	}		
	if(ant == NULL){
		novo->prox = aux;
		L = novo;
	}
	else{
		ant->prox = novo;
		novo->prox = aux;
		}
	return L;
}

//Ordena a lista em ordem alfabética
Lista * ordenar(Lista * L, Lista * R){
	Lista * aux = L;
	while(aux != NULL){
		R = inserir_ordem(R, aux->nome);
		aux = aux->prox;
	}
	return R;
}

//Remove todos os valores que começarem com a letra desejada
Lista * remover_por_letra(Lista* L, char letra){
	Lista * aux = L;
	while(aux != NULL){
		if(letra == aux->nome[0]){
			L = remover(L, aux->nome);
		}
		aux = aux->prox;
	}
	return L;
}

//Retorna a maior string da lista
void maior(Lista * L){
	Lista * aux = L; 
	char maior[50];
	strcpy(maior, aux->nome);
	while(aux != NULL){
		if(strlen(aux->nome) > strlen(maior)){
			strcpy(maior, aux->nome);
		}
		aux = aux->prox;
	}
	printf("%s\n", maior);
}

//Verifica se duas listas são iguais
void iguais(Lista * L, Lista * R){
	Lista * aux;
	Lista * aux2;
	for(aux = L; aux != NULL; aux = aux->prox){
		for(aux2 = R; aux2 != NULL && strcmp(aux->nome, aux2->nome) != 0; aux2 = aux2->prox){
		}
		if(aux2 == NULL){
			printf("listas diferentes\n");
			break;
		}
	}
	if(aux == NULL){
		printf("listas iguais\n");
	}
}

//Imprime a lista na tela
void imprimir(Lista * L){
	if (L == NULL)
	printf("lista vazia\n");
	else {
		Lista * aux = L;
		while(aux != NULL){
			printf("%s -> ", aux->nome);
			aux = aux->prox;
		}
	}printf("\n");
}


