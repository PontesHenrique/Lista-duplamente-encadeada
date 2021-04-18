#ifndef _LISTADUPLA_H_
#define _LISTADUPLA_H_

typedef struct no No;

No *criarNo(int id);
int listaVazia(No *cabecaLista);
int tamanhoLista(No *inicioLista);
int inserir(No **cabecaLista, int id);
int inserir_final(No **cabecaLista, int id);
int inserir_ordem(No **cabecaLista, int id);
int removeElemento(No **cabecaLista, int id);
int buscaElemento(No *cabecaLista, int id);
void imprimeLista(No *cabecaLista, char *mensagem);
void limparLista(No **cabecaLista);
int validarResp(char *mensagem, int padrao);

#endif

