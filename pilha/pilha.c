#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura que representa os elementos da pilha
typedef struct l {
    int valor; 
    struct l* prox; // ponteiro que aponta para o próximo nó da pilha
}lista;

// Estrutura que a pilha
typedef struct p { 
    lista* topo ; // ponteiro que aponta para o topo nó da pilha
}pilha;

// função para criar e inicializar a pilha 
pilha* criar(){
	pilha* p = (pilha*) malloc(sizeof(pilha)); // aloca espaço para a pilha
	
	if(p){
		p->topo = NULL; // retorna NULL para o topo para mostrar que a pilha está vazia
	}
	else{
		printf("Erro de alocação");
	}
	return p;
}

// As pilhas têm 2 funções principais: o push e o pop
// O push serve para para empilhar e o pop para desempilhar

//função para empilhar - "push"
pilha* push(pilha* p, int n){
	
	if(p){
		lista* novo = (lista*) malloc(sizeof(lista)); // aloca espaço para o novo nó
		
		if(novo){
			// inicialização do novo nó
			novo->valor = n; 
			novo->prox = p->topo; // conecta o novo nó ao início da pilha 
			p->topo = novo; // para que o novo nó seja o primeiro da pilha
		}
		else{
			printf("Erro de alocação");
		}
	}
	else{
		printf("A pilha não foi criada");
	}
}

// funcão para desempilhar - "pop"
int pop(pilha** p){
	
	int k = 0;
	
	//o pop retorna o elemento removido
	// sempre remove o elemento no topo da pilha 
    // por não retornar a pilha altetrada há a necessidade de passar a pilha por referência 
	
	if(*p){
		if((*p)->topo){
			lista* aux = (*p)->topo; // recebe o endereço do nó a ser removido
			(*p)->topo = aux->prox; // Muda o topo da pilha
			k = aux->valor; // Guarda o valor do nó que será removido
			free(aux); // libera o espaço alocado na memória para esse nó
		}
		else{
			printf("Pilha vazia");
		}	
	}
	else{
		printf("A pilha não foi criada");
	}
	return k; // retorna o valor do nó que foi removido
}

// função para imprimir a pilha
void imprimirPilha (pilha* p) {
	if(p == NULL){
		printf("A pilha não foi criada");
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

//função para apagar a pilha
pilha* apagarPilha(pilha* p){
	int k;
	
	// remove cada nó da pilha
	while(p->topo){
		k = pop(&p);
	}
	// Inicializa a pilha com NULL para indicar que está vazia
	return NULL;
}

// menu
void menu(pilha* p){
	
	int n, valor;
   	do{
   		printf("-------------Pilha-------------\n\n");
   		printf(" [1] Inserir nó na pilha\n\n");
   		printf(" [2] Imprimir a pilha\n\n");
   		printf(" [3] Remover nó da pilha\n\n");
   		printf(" [4] Apagar pilha\n\n");
   		printf(" [0] Sair\n\n");
   		scanf("%d", &n);
   		
   		switch(n){
   			
   			case 1:
   				printf("Valor do nó: ");
   				scanf("%d", &valor);
   				p = push(p,valor);
   				printf("Nó inserido com sucesso");
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
				printf("Opção inválida");
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
