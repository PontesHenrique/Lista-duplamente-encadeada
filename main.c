/*
	UFPB - Universidade Federal da Para�ba
	
	Exerc�cio de fixa��o da disciplina de Estrutura de dados
	Lista Din�mica Duplamente Encadeada
	Professor: Leandro
	Aluno: Luis Henrique Pontes
	M�tricula: 20180163467
*/

#include "listaDupla.c"

int main(void)
{
	
	int id = 0, flag_id;
	int continuar;
	
	setlocale(LC_ALL, "Portuguese");

	No *cabecaLista = NULL;
	
	char opcao_char = ' ';
	int opcao = opcao_char;
	
    while(opcao){
        printf(" *** Lista Encadeada ***\n\n");
        printf("1) Inserir registro inicio na Lista\n");//49
        printf("2) Inserir registro final na Lista\n");//50
        printf("3) Inserir registro ordenado na Lista\n");//51
        printf("4) Remover registro da Lista\n");//52
        printf("5) Buscar registro na Lista\n");//53
        printf("6) Tamanho da Lista\n");//54
        printf("7) Imprimir Lista\n");//55
        printf("8) Limpar Lista\n");//56
        printf("0) Encerrar\n");//48

        do{
        	fflush(stdin);
            printf("Op��o:");
            scanf("%c", &opcao_char);
            fflush(stdin);
            opcao = opcao_char;
            if(opcao == 48){
            	if(!cabecaLista){
            		return EXIT_SUCCESS;
				}
            	free(cabecaLista);
				printf("Mem�ria liberada com sucesso");
            	return EXIT_SUCCESS;
			}
        }while((opcao < 49 || opcao > 58));
  
        fflush(stdin);
        system("CLS");

        switch(opcao){
            case 49:
            	id++;
            	inserir(&cabecaLista, id); 
                imprimeLista(cabecaLista, "Lista de ID: ");
            break;
            
            case 50:
            	id++;
            	inserir_final(&cabecaLista, id); 
                imprimeLista(cabecaLista, "Lista de ID: ");
            break;
            	
            case 51:
            	id++;
            	inserir_ordem(&cabecaLista, id); 
                imprimeLista(cabecaLista, "Lista de ID: ");
            break;
            
            case 52:
            	continuar = validarResp("Confirma Remover elemento?", 1);//Retorna 1 se a resposta for verdadeira
    			system("CLS");
    			imprimeLista(cabecaLista, "Lista de ID: ");
    			if(continuar){
    				printf("Digite ID: ");
	            	scanf("%d", &flag_id);
	                if(!removeElemento(&cabecaLista, flag_id)){
	                	printf("ID %d n�o pertence a lista\n");
					}else{
						printf("Elemento excluido com sucesso!!!\n");
	                	imprimeLista(cabecaLista, "Lista de ID: ");
	                	if(listaVazia(cabecaLista)){
	    					id = 0;
						}
					}
				}
            break;
            
            case 53:
            	imprimeLista(cabecaLista, "Lista de ID: ");
                printf("\nDigite o elemento para busca: ");
                scanf("%d", &flag_id);
                if(listaVazia(cabecaLista)){
                	printf("Lista vazia!!!\n");
				}else{
					if(buscaElemento(cabecaLista, flag_id)){
                		printf("%d pertence a lista\n", flag_id);
					}else{
						printf("%d n�o pertence a lista\n");
					}
				}
            break;
            	
            case 54:
            	imprimeLista(cabecaLista, "Lista de ID: ");
            	printf("\nA lista possui %d elemento(s)\n\n", tamanhoLista(cabecaLista));
            break;
            
            case 55:
            	imprimeLista(cabecaLista, "Lista de ID: ");
            break;
            
            case 56:
            	imprimeLista(cabecaLista, "Lista de ID: ");
            	limparLista(&cabecaLista);
            	imprimeLista(cabecaLista, "Lista de ID: ");
            break;
   
        }
    }//fim do while

	return 0;
}











































