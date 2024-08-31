#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura que representa os elementos da pilha
typedef struct l {
    int valor; 
    struct l* prox; // ponteiro que aponta para o pr�ximo n� da pilha
}lista;

// Estrutura que a pilha
typedef struct p { 
    lista* topo ; // ponteiro que aponta para o topo n� da pilha
}pilha;

// fun��o para criar e inicializar a pilha 
pilha* criar(){
	pilha* p = (pilha*) malloc(sizeof(pilha)); // aloca espa�o para a pilha
	
	if(p){
		p->topo = NULL; // retorna NULL para o topo para mostrar que a pilha est� vazia
	}
	else{
		printf("Erro de aloca��o");
	}
	return p;
}

// As pilhas t�m 2 fun��es principais: o push e o pop
// O push serve para para empilhar e o pop para desempilhar

//fun��o para empilhar - "push"
pilha* push(pilha* p, int n){
	
	if(p){
		lista* novo = (lista*) malloc(sizeof(lista)); // aloca espa�o para o novo n�
		
		if(novo){
			// inicializa��o do novo n�
			novo->valor = n; 
			novo->prox = p->topo; // conecta o novo n� ao in�cio da pilha 
			p->topo = novo; // para que o novo n� seja o primeiro da pilha
		}
		else{
			printf("Erro de aloca��o");
		}
	}
	else{
		printf("A pilha n�o foi criada");
	}
}

// func�o para desempilhar - "pop"
int pop(pilha** p){
	
	int k = 0;
	
	//o pop retorna o elemento removido
	// sempre remove o elemento no topo da pilha 
    // por n�o retornar a pilha altetrada h� a necessidade de passar a pilha por refer�ncia 
	
	if(*p){
		if((*p)->topo){
			lista* aux = (*p)->topo; // recebe o endere�o do n� a ser removido
			(*p)->topo = aux->prox; // Muda o topo da pilha
			k = aux->valor; // Guarda o valor do n� que ser� removido
			free(aux); // libera o espa�o alocado na mem�ria para esse n�
		}
		else{
			printf("Pilha vazia");
		}	
	}
	else{
		printf("A pilha n�o foi criada");
	}
	return k; // retorna o valor do n� que foi removido
}

// fun��o para imprimir a pilha
void imprimirPilha (pilha* p) {
	if(p == NULL){
		printf("A pilha n�o foi criada");
	}
	else{
		if(p->topo){
			lista* aux = p->topo;
    		while (aux != NULL) {
        	printf("%d -> ", aux -> valor);
        	aux = aux -> prox;
    		}	
		}
		else{
			printf("Pilha vazia");
		}	
	}
}

//fun��o para apagar a pilha
pilha* apagarPilha(pilha* p){
	int k;
	
	// remove cada n� da pilha
	while(p->topo){
		k = pop(&p);
	}
	// Inicializa a pilha com NULL para indicar que est� vazia
	return NULL;
}

// menu
void menu(pilha* p){
	
	int n, valor;
   	do{
   		printf("-------------Pilha-------------\n\n");
   		printf(" [1] Inserir n� na pilha\n\n");
   		printf(" [2] Imprimir a pilha\n\n");
   		printf(" [3] Remover n� da pilha\n\n");
   		printf(" [4] Apagar pilha\n\n");
   		printf(" [0] Sair\n\n");
   		scanf("%d", &n);
   		
   		switch(n){
   			
   			case 1:
   				printf("Valor do n�: ");
   				scanf("%d", &valor);
   				p = push(p,valor);
   				printf("N� inserido com sucesso");
   				printf("\n\n");
   				break;
   	
   			case 2:
   				imprimirPilha(p);
   				printf("\n\n");
   				break;
   				
   			case 3:
   				valor = pop(&p);
   				printf(" %d ", valor);
   				printf("removido da pilha com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 4:
   				p = apagarPilha(p);
   				if (p){
   					printf("Erro ao apagar a pilha");
				}
				else{
					printf("Pilha apagada com sucesso");
				}
				printf("\n\n");
   				break;
   				
   			case 0:
   				exit(0);
   				break;
   				
			default:
				printf("Op��o inv�lida");
				printf("\n\n");
				break;		
		}	
	}while( n!=0);
   		
}

int main() {
	
   	setlocale(LC_ALL, "Portuguese");
   	
   	pilha* p;
   	p = criar();
   	menu(p);
   	
    return 0;
}
