#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "listaDupla.h"

#define NOME_TAM 30
#define END_TAM 50

#ifndef _LISTADUPLA_C_
#define _LISTADUPLA_C_

struct no
{
	int id;
	int idade;
	int cpf;
	int conta;
	int saldo;
	struct no *proximoNo;
	struct no *NoAnterior;
};

No *criarNo(int id){
	
	No *no = (No*)malloc(sizeof(No));
	if(no){
		no->id = id;
		no->idade = 0;
		no->cpf = 0;
		no->conta = 0;
		no->saldo = 0;
		no->proximoNo = NULL;
		no->NoAnterior = NULL;
	}
	return no;
}

int listaVazia(No *cabecaLista){//verifica se a lista é vazia
	return (cabecaLista == NULL);
}

int tamanhoLista(No *cabecaLista){//calcula o tamanho da lista
	
	int tamanho = 0;
	while(cabecaLista){//enquanto existirn elemento na lista
		tamanho ++;//incrementa o tamanho
		cabecaLista = cabecaLista->proximoNo;
	}
	return tamanho;
}

void limparLista(No **cabecaLista){//libera memória alocada
	No *prox = NULL;
	No *aux = *cabecaLista;
	while(aux){
		prox = aux->proximoNo;
		free(aux);
		aux = prox;
	}
	*cabecaLista = NULL;
}

int inserir(No **cabecaLista, int id){//insere elemnto no início da lista
	
	No *aux = criarNo(id);
	if(aux){
		aux->proximoNo = *cabecaLista;
		aux->NoAnterior = NULL;
		if(*cabecaLista)
			(*cabecaLista)->NoAnterior = aux;
		*cabecaLista = aux;	
		return 1;//retorna 1 se sucesso na operação
	}
	return 0;
}

int inserir_final(No **cabecaLista, int id){//insere no final da lista
	
	No *aux = criarNo(id);
	if(aux){
		aux->proximoNo = NULL;
		if(!*cabecaLista){//lista vazia
			inserir(cabecaLista, id);//insere no início da lista
		}else{
			No *flag = *cabecaLista;
			while(flag->proximoNo)//percorre a lista para inserir no final
				flag = flag->proximoNo;
			flag->proximoNo = aux;
			aux->NoAnterior = flag;		
		}
		return 1;
	}
	return 0;
}

int inserir_ordem(No **cabecaLista, int id){//insere elemento ordenado na lista

	No *aux = criarNo(id);
		
	if(aux){
		No *ante, *atual = *cabecaLista;
		while(atual && (atual->id < id)){//percorre a lista para encontrar o elemento
			ante = atual;
			atual = atual->proximoNo;
		}
		if(atual == *cabecaLista){//significa que o elemento será inserido no início da lista
			return inserir(cabecaLista, id);
		}else{//elemento será inserido no local ordenado no meio ou no final da lista
			aux->proximoNo = ante->proximoNo;
			aux->NoAnterior = ante;
			ante->proximoNo = aux;
			if(atual)	
				atual->NoAnterior = aux;
		}
		return 1;
		}
		
	return 0;
}

int removeElemento(No **cabecaLista, int id){//remove elemento da lista

	No *aux = *cabecaLista;	

	if(cabecaLista == NULL)
		return 0;
		
	while(aux && aux->id != id)//procura o elemento na lista
		aux = aux->proximoNo;
	if(aux == NULL)//final da lista não encontra elemento
		return 0;
	if(aux->NoAnterior == NULL)//remove o premiro nó da lista
		*cabecaLista = aux->proximoNo;
	else//remove elemento no final ou no meio da lista
		aux->NoAnterior->proximoNo = aux->proximoNo;
	if(aux->proximoNo)
		aux->proximoNo->NoAnterior = aux->NoAnterior;
		
	free(aux);
	
	return 1;
}

int buscaElemento(No *cabecaLista, int id)//busca elemento na lista
{
	if(listaVazia(cabecaLista)){//se lista vazia
		return 0;
	}
	while(cabecaLista){//percorre a lista
		if(cabecaLista->id == id){//achou o elemento
			return 1;
		}
		cabecaLista = cabecaLista->proximoNo;
	}
	return 0;
}

void imprimeLista(No *cabecaLista, char *mensagem){//imprime a lista
	
	printf("%s", mensagem);
	while(cabecaLista){//percorre a lista
		printf("%d -> ", cabecaLista->id);//imprime a lista
		cabecaLista = cabecaLista->proximoNo;
	}
	printf(" NULL\n");
}

int validarResp(char *mensagem, int padrao) {//função para confirmar comando pelo usuário
   int op;
   char cPadrao = (padrao ? 's' : 'n');

   do {
      printf("\n%s [S ou N] %c", mensagem, cPadrao);
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'S' && op != 'n' && op != 'N' && op != 13);

    if(op == 13)
        return padrao;

   return ((op == 's' || op == 'S') ? 1 : 0);
}


#endif



















































