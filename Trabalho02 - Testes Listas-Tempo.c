// ---- Alunos: Adiel Ferreira Santana e Artur Roza Campos 
// ---- Professor: Ms. Ivairton Monteiro Santos
// ---------------------------  Testes de Listas ---------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000
#define TAM2 10000

//CRIACAO DAS STRUCTS(LISTAS)
//Lista Encadeada
typedef struct listaEncadeada tipoListaEncadeada;
struct listaEncadeada{
	int valor;
	tipoListaEncadeada *prox;
};
//Lista Duplamente Encadeada
typedef struct listaDupla tipoListaDupla;
struct listaDupla{
	int valor;
	tipoListaDupla *prox;
	tipoListaDupla *ant;
};
//Lista estatica MIL
typedef struct listaEstaticaMil tipoListaEstaticaMil;
struct listaEstaticaMil{
	int valor[TAM];
	int tamanho;
};
//Lista estatica DEZMIL
typedef struct listaEstaticaDezMil tipoListaEstaticaDezMil;
struct listaEstaticaDezMil{
	int valor[TAM2];
	int tamanho;
};
typedef struct Info tipoInfo;
struct Info{
	double mediaTempo;
	int qtd;
};
//PROTOTIPOS DAS FUNCOES
void geraVetorAleatorio(int vet[],int tam);
//FUNCOES LISTA ENCADEADA
void insereInicio(tipoListaEncadeada **lst,int vlr);
void mostraLista(tipoListaEncadeada **lst);
void insereFim(tipoListaEncadeada **lst,int vlr);
void inserePos(tipoListaEncadeada **lst,int pos, int vlr);
//FUNCOES LISTA DUPLAMENTE ENCADEADA
void insereFimListaDupla(tipoListaDupla **lst, int vlr);
void insereInicioListaDupla(tipoListaDupla **lst, int vlr);
void inserePosDupla(tipoListaDupla **lst, int pos, int vlr);
//FUNCOES LISTA ESTATICA MIL
void inserePosicaoEstaticaMil(tipoListaEstaticaMil *l, int valor, int posicao);
void insereFimEstaticaMil(tipoListaEstaticaMil *l,int valor);
void insereInicioEstaticaMil(tipoListaEstaticaMil *l,int valor);
//FUNCOES LISTA ESTATICA DEZ  MIL
void inserePosicaoEstaticaDezMil(tipoListaEstaticaDezMil *l, int valor, int posicao);
void insereFimEstaticaDezMil(tipoListaEstaticaDezMil *l,int valor);
void insereInicioEstaticaDezMil(tipoListaEstaticaDezMil *l,int valor);

int main(){
		clock_t end,start;
		int OPC1=0,OPC2=0;
		tipoInfo mTempo;
		mTempo.qtd = 0;
		do{
			printf("\n----TRABALHO DE TESTES DE LISTAS----\n");
			printf("Qual estrutura deseja avaliar ?\n");
			printf("0-SAIR \n");
			printf("1-Lista Encadeada \n");
			printf("2-Lista Estatica \n");
			printf("3-Lista Duplamente Encadeada \n");
			scanf("%d",&OPC1);
			
			if(OPC1==1){
				do{
					
					printf("\nQual tamanho deseja avaliar ?\n");
					printf("0-SAIR \n");
					printf("1-MIL \n");
					printf("2-DEZ MIL \n");
					scanf("%d",&OPC2);
					
					if(OPC2==1){
						//OPCAO DE TAMANHO MIL
						//vetores de numeros aleatorios e posicoes aleatorias
						printf("\nGerando lista ligada com 1000 posicoes...");
						int numerosAleatorios[TAM];
						int posAleatorias[333];
						//inicializacao da lista encadeada
						tipoListaEncadeada *lst = NULL;
						malloc(sizeof(lst));
						//GERADOR DE POSICOES ALEATORIAS ENTRE 0-MIL
						geraVetorAleatorio(posAleatorias,333);
						printf("Lista criada com sucesso!");
						printf("\nGerando dez mil numeros aleatorios...");
						//GERADOR DE NUMEROS ALEATORIOS ENTRE 0-DEZ MIL
						geraVetorAleatorio(numerosAleatorios,1000);
						printf("\nNumeros gerados com sucesso!");
						printf("\nIniciando insercao de valores aleatorios na lista...");
						start = clock();
						//INSERCAO NO INICIO DA STRUCT LISTA
						for(int i=0;i<333;i++){
							insereInicio(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no inicio...");
						//INSERCAO NO FINAL DA STRUCT LISTA
						for(int i=334;i<666;i++){
							insereFim(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no fim...");
						//INSERCAO NAS POSICOES ALETORIAS DA STRUCT LISTA
						for(int i=667;i<TAM	;i++){
							inserePos(&lst,posAleatorias[i],numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos em posicoes aleatorias...");
						end = clock();
						
						double tempo = 0;
						tempo = (end-start) * 1000.0 / CLOCKS_PER_SEC;
						mTempo.mediaTempo += tempo;
						mTempo.qtd++;
						//mostraLista(&lst);
						printf("\nInsercao concluida!");
						printf("\nO tempo de execucao e de %.2f ms",tempo);	
						printf("\nVoce executou a insercao %d vezes",mTempo.qtd);
						double t = mTempo.mediaTempo/ mTempo.qtd;
						printf("\nA media de tempo total e %.2f",t);
					}else if(OPC2==2){
						if((mTempo.qtd > 0) && (mTempo.mediaTempo > 0.0)){
							mTempo.qtd=0;
							}
						//OPCAO DE TAMANHO DEZ MIL
						//vetores de numeros aleatorios e posicoes aleatorias
						printf("\nGerando lista ligada com 10000 posicoes...");
						int numerosAleatorios[TAM2];
						int posAleatorias[3333];
						//inicializacao da lista encadeada
						tipoListaEncadeada *lst = NULL;
						malloc(sizeof(lst));
						//GERADOR DE POSICOES ALEATORIAS ENTRE 0-MIL
						geraVetorAleatorio(posAleatorias,3333);
						printf("Lista criada com sucesso!");
						printf("\nGerando dez mil numeros aleatorios...");
						//GERADOR DE NUMEROS ALEATORIOS ENTRE 0-DEZ MIL
						geraVetorAleatorio(numerosAleatorios,10000);
						
						printf("\nNumeros gerados com sucesso!");
						printf("\nIniciando insercao de valores aleatorios na lista...");
						start = clock();
						printf("\n TEMPO INICIAL - %d",start);
						//INSERCAO NO INICIO DA STRUCT LISTA
						for(int i=0;i<3333;i++){
							insereInicio(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no inicio...");
						//INSERCAO NO FINAL DA STRUCT LISTA
						for(int i=3334;i<6666;i++){
							insereFim(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no fim...");
						//INSERCAO NAS POSICOES ALETORIAS DA STRUCT LISTA
						for(int i=6667;i<TAM2;i++){
							inserePos(&lst,posAleatorias[i],numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos em posicoes aleatorias...");
						end = clock();
						printf("\n TEMPO INICIAL - %d",end);
						double tempo = 0;
						
						tempo = (end-start) * 1000.0 / CLOCKS_PER_SEC;
						mTempo.mediaTempo += tempo;
						mTempo.qtd++;
						
						//mostraLista(&lst);
						printf("\nInsercao concluida!");
						printf("\nO tempo de execucao e de %.2f ms",tempo);
						printf("\nVoce executou a insercao %d vezes",mTempo.qtd);
						double t = mTempo.mediaTempo/ mTempo.qtd;
						printf("\nA media de tempo total e %.2f",t);
						}
					}while(OPC2!=0);//end2
			
			}if(OPC1==2){
				do{
					printf("\nQual tamanho deseja avaliar ?\n");
					printf("0-VOLTAR \n");
					printf("1-MIL \n");
					printf("2-DEZ MIL \n");
					scanf("%d",&OPC2);
				
					if(OPC2==1){
						tipoListaEstaticaMil listaMil;
						listaMil.tamanho = 0;
						int valoresAleatorios[TAM];
						int posicoesAleatorias[333];
						printf("\nLista criada com sucesso!");
						printf("\nGerando valores aleatorios...");
						geraVetorAleatorio(posicoesAleatorias,333);
						geraVetorAleatorio(valoresAleatorios,TAM);
						
						printf("\nValores e posicoes aleatorias geradas com sucesso!");
						start = clock();
						for(int i=0;i<333;i++){
							insereInicioEstaticaMil(&listaMil,valoresAleatorios[i]);	
						}
						for(int i=334;i<666;i++){
							insereFimEstaticaMil(&listaMil,valoresAleatorios[i]);
						}
						for(int i=666;i<TAM;i++){
							inserePosicaoEstaticaMil(&listaMil,valoresAleatorios[i],posicoesAleatorias[i]);
						}
						end = clock();
						double tempo = 0;
						tempo = (end-start) * 1000.0 / CLOCKS_PER_SEC;
						mTempo.mediaTempo += tempo;
						mTempo.qtd++;
						printf("\nInsercao concluida!");
						printf("\nO tempo de execucao e de %.2f ms",tempo);
						printf("\nVoce executou a insercao %d vezes",mTempo.qtd);
						double t = mTempo.mediaTempo/ mTempo.qtd;
						printf("\nA media de tempo total e %.2f",t);

					}
					if(OPC2==2){
						tipoListaEstaticaDezMil listaDezMil;
						listaDezMil.tamanho = 0;
						int valoresAleatorios[TAM];
						int posicoesAleatorias[333];
						printf("\nLista criada com sucesso!");
						printf("\nGerando valores aleatorios...");
						geraVetorAleatorio(posicoesAleatorias,3333);
						geraVetorAleatorio(valoresAleatorios,TAM2);
						printf("\nValores e posicoes aleatorias geradas com sucesso!");
						start = clock();
						for(int i=0;i<3333;i++){
							insereInicioEstaticaDezMil(&listaDezMil,valoresAleatorios[i]);	
						}
						for(int i=3334;i<6666;i++){
							insereFimEstaticaDezMil(&listaDezMil,valoresAleatorios[i]);
						}
						for(int i=6666;i<TAM2;i++){
							inserePosicaoEstaticaDezMil(&listaDezMil,valoresAleatorios[i],posicoesAleatorias[i]);
						}
						end = clock();
						double tempo = 0;
						tempo = (end-start) * 1000.0 / CLOCKS_PER_SEC;
						printf("\nInsercao concluida!");
						printf("\nO tempo de execucao e de %.2f ms",tempo);
					}	
				}while(OPC2!=0);
		}//FIM CONDICOES
		if(OPC1 == 3){
			do{
					printf("\nQual tamanho deseja avaliar ?\n");
					printf("0-VOLTAR \n");
					printf("1-MIL \n");
					printf("2-DEZ MIL \n");
					scanf("%d",&OPC2);
					if(OPC2 ==1){
						printf("\nGerando lista ligada com 1000 posicoes...");
						int numerosAleatorios[TAM];
						int posAleatorias[333];
						//inicializacao da lista encadeada
						tipoListaDupla* lst = NULL;
						malloc(sizeof(lst));
						//GERADOR DE POSICOES ALEATORIAS ENTRE 0-MIL
						geraVetorAleatorio(posAleatorias,333);
						printf("Lista criada com sucesso!");
						printf("\nGerando dez mil numeros aleatorios...");
						//GERADOR DE NUMEROS ALEATORIOS ENTRE 0-DEZ MIL
						geraVetorAleatorio(numerosAleatorios,1000);
						printf("\nNumeros gerados com sucesso!");
						printf("\nIniciando insercao de valores aleatorios na lista...");
						start = clock();
						//INSERCAO NO INICIO DA STRUCT LISTA
						for(int i=0;i<333;i++){
							insereInicioListaDupla(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no inicio...");
						//INSERCAO NO FINAL DA STRUCT LISTA
						for(int i=334;i<666;i++){
							insereFimListaDupla(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no fim...");
						//INSERCAO NAS POSICOES ALETORIAS DA STRUCT LISTA
						for(int i=667;i<TAM	;i++){
							inserePosDupla(&lst,posAleatorias[i],numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos em posicoes aleatorias...");
						//mostraLista(&lst);
						end = clock();
						
						double tempo = 0;
						tempo = (end-start) * 1000.0 / CLOCKS_PER_SEC;
						mTempo.mediaTempo += tempo;
						mTempo.qtd++;
						printf("\nInsercao concluida!");
						printf("\nO tempo de execucao e de %.2f ms",tempo);
						printf("\nVoce executou a insercao %d vezes",mTempo.qtd);
						double t = mTempo.mediaTempo/ mTempo.qtd;
						printf("\nA media de tempo total e %.2f",t);					}
					if(OPC2==2){
						printf("\nGerando lista ligada com 1000 posicoes...");
						int numerosAleatorios[TAM2];
						int posAleatorias[3333];
						//inicializacao da lista encadeada
						tipoListaDupla *lst = NULL;
						malloc(sizeof(lst));
						//GERADOR DE POSICOES ALEATORIAS ENTRE 0-MIL
						geraVetorAleatorio(posAleatorias,3333);
						printf("Lista criada com sucesso!");
						printf("\nGerando dez mil numeros aleatorios...");
						//GERADOR DE NUMEROS ALEATORIOS ENTRE 0-DEZ MIL
						geraVetorAleatorio(numerosAleatorios,10000);
						printf("\nNumeros gerados com sucesso!");
						printf("\nIniciando insercao de valores aleatorios na lista...");
						start = clock();
						//INSERCAO NO INICIO DA STRUCT LISTA
						for(int i=0;i<3333;i++){
							insereInicioListaDupla(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no inicio...");
						//INSERCAO NO FINAL DA STRUCT LISTA
						for(int i=3334;i<6666;i++){
							insereFimListaDupla(&lst,numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos no fim...");
						//INSERCAO NAS POSICOES ALETORIAS DA STRUCT LISTA
						for(int i=6667;i<TAM2;i++){
							inserePosDupla(&lst,posAleatorias[i],numerosAleatorios[i]);
						}
						printf("\nNumeros inseridos em posicoes aleatorias...");
						end = clock();
						
						double tempo = 0;
						tempo = (end-start) * 1000.0 / CLOCKS_PER_SEC;
						mTempo.mediaTempo += tempo;
						mTempo.qtd++;
						printf("\nInsercao concluida!");
						printf("\nO tempo de execucao e de %.2f ms",tempo);
						printf("\nVoce executou a insercao %d vezes",mTempo.qtd);
						double t = mTempo.mediaTempo/ mTempo.qtd;
						printf("\nA media de tempo total e %.2f",t);
					}
			}while(OPC2!=0);
		}
	}while(OPC1!=0);//end1
}
//FUNCOES
void geraVetorAleatorio(int vet[], int tam){
	if(tam == 333){
		srand(time(NULL));
		for(int i=0; i<tam;i++){
			vet[i] = rand() % 1000;
		}
	}else{
		srand(time(NULL));
		for(int i=0; i<tam;i++){
			vet[i] = rand() % 10000;
		}	
	}
}
//FUNCOES LISTA ENCADEADA
void insereInicio(tipoListaEncadeada **lst,int vlr){
	tipoListaEncadeada *novaLista;
	novaLista = (tipoListaEncadeada *) malloc(sizeof(tipoListaEncadeada));

	novaLista->valor = vlr;
	novaLista->prox = *lst;
	*lst = novaLista;
}
void mostraLista(tipoListaEncadeada **lst){
	if((*lst) == NULL){
		printf("\nLISTA VAZIA!");
	}else{
		tipoListaEncadeada *novaLista;
		novaLista = *lst;
		while(novaLista != NULL){
			printf("\n%d",novaLista->valor);
			novaLista = novaLista->prox;
			if(novaLista == NULL){
				printf("\nACABOU A LISTA!");
			}
		}
	}
}
void insereFim(tipoListaEncadeada **lst,int vlr){
	tipoListaEncadeada *novaLista, *aux;
	novaLista = (tipoListaEncadeada *) malloc(sizeof(tipoListaEncadeada));
	aux = (tipoListaEncadeada *) malloc(sizeof(tipoListaEncadeada));
	
	novaLista->valor = vlr;
	novaLista->prox = NULL;
	
	if((*lst) == NULL){
		*lst = novaLista;
	}else{
		aux = *lst;

		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novaLista;
	}
}
void inserePos(tipoListaEncadeada **lst,int pos, int vlr){
	int cont;
	tipoListaEncadeada *novaLista,*aux,*aux_ant;
	novaLista = (tipoListaEncadeada *) malloc(sizeof(tipoListaEncadeada));
	aux = (tipoListaEncadeada *) malloc(sizeof(tipoListaEncadeada));
	aux_ant = (tipoListaEncadeada *) malloc(sizeof(tipoListaEncadeada));
	
	novaLista->valor = vlr;
	cont = 0;
	aux = (*lst);
	while((cont<pos) && (aux != NULL)){
		cont = cont+1;
		aux_ant = aux;
		aux = aux->prox;
	}
	if((cont == pos) && pos > 0){
		novaLista->prox = aux;
		aux_ant->prox = novaLista;
	}else{
		novaLista->prox = *lst;
		*lst = novaLista;
	}
}
//FUNCOES DA LISTA ESTATICA MIL
void insereInicioEstaticaMil(tipoListaEstaticaMil *l,int valor){
	if(l->tamanho == 0){
		l->valor[0] = valor;
		l->tamanho++;
	}else{
		if(l->tamanho > TAM){
			printf("\nLista cheia!");
		}else{
			for(int i = l->tamanho; i>0 ;i--){
				l->valor[i] = l->valor[i-1];
			}
			l->valor[0] = valor;
			l->tamanho++;
		}
	}
}
void insereFimEstaticaMil(tipoListaEstaticaMil *l,int valor){
	if(l->tamanho < TAM){
		l->valor[l->tamanho] = valor;
		l->tamanho++;
	}else{
		printf("\nLista cheia!");
	}	
}
void inserePosicaoEstaticaMil(tipoListaEstaticaMil *l, int valor, int posicao){
	if(l->tamanho > TAM){
		printf("\nLista Cheia!");
	}else{
		if(posicao > l->tamanho){
			l->valor[posicao] = valor;
			l->tamanho++;			
		}else{
			//descola todos pra esquerda
			for(int i = l->tamanho; i>posicao ;i--){
				l->valor[i] = l->valor[i-1];	
			}
			l->valor[posicao] = valor;
			l->tamanho++;
		}
	}
}
//FUNCOES DA LISTA ESTATICA DEZ MIL
void insereInicioEstaticaDezMil(tipoListaEstaticaDezMil *l,int valor){
	if(l->tamanho == 0){
		l->valor[0] = valor;
		l->tamanho++;
	}else{
		if(l->tamanho > TAM2){
			printf("\nLista cheia!");
		}else{
			for(int i = l->tamanho; i>0 ;i--){
				l->valor[i] = l->valor[i-1];
			}
			l->valor[0] = valor;
			l->tamanho++;
		}
	}
}
void insereFimEstaticaDezMil(tipoListaEstaticaDezMil *l,int valor){
	if(l->tamanho < TAM2){
		l->valor[l->tamanho] = valor;
		l->tamanho++;
	}else{
		printf("\nLista cheia!");
	}	
}
void inserePosicaoEstaticaDezMil(tipoListaEstaticaDezMil *l, int valor, int posicao){
	if(l->tamanho > TAM2){
		printf("\nLista Cheia!");
	}else{
		if(posicao > l->tamanho){
			l->valor[posicao] = valor;
			l->tamanho++;			
		}else{
			//descola todos pra esquerda
			for(int i = l->tamanho; i>posicao ;i--){
				l->valor[i] = l->valor[i-1];	
			}
			l->valor[posicao] = valor;
			l->tamanho++;
		}
	}
}
//FUNCOES LISTA DUPLAMENTE ENCADEADA
void insereFimListaDupla(tipoListaDupla **lst, int vlr){	
	tipoListaDupla *novoNo, *aux;
	novoNo = (tipoListaDupla*)malloc(sizeof(tipoListaDupla));
	novoNo->valor = vlr;
	novoNo->prox = NULL;
	novoNo->ant = NULL;
	if(*lst == NULL){
		*lst = novoNo;
	}else{
		aux = *lst;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novoNo;
		novoNo->ant = aux;
	}
}
void inserePosDupla(tipoListaDupla **lst, int pos, int vlr){
	int cont;
	tipoListaDupla *novoNo,*aux,*aux_ant;
	novoNo = (tipoListaDupla *) malloc(sizeof(tipoListaDupla));
	aux = (tipoListaDupla *) malloc(sizeof(tipoListaDupla));
	aux_ant = (tipoListaDupla *) malloc(sizeof(tipoListaDupla));
	
	novoNo->valor = vlr;
	cont = 0;
	aux = (*lst);

	while((cont<pos) && (aux != NULL)){
		cont = cont+1;
		aux_ant = aux;
		aux = aux->prox;
	}
	if((cont == pos) && pos > 0){
		novoNo->prox = aux;
		novoNo->ant = aux_ant;
		aux_ant->prox = novoNo;
	}else{
		novoNo->prox = *lst;
		novoNo->ant = aux_ant;
		*lst = novoNo;
	}
}
void insereInicioListaDupla(tipoListaDupla **lst, int vlr){
	tipoListaDupla *novoNo;
	novoNo = (tipoListaDupla*)malloc(sizeof(tipoListaDupla));
		if(novoNo != NULL){
		novoNo->valor = vlr;
		novoNo->prox = *lst;
		novoNo->ant = novoNo;
		*lst = novoNo;
	}
}
