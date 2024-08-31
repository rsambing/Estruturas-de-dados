#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct l {
    int valor;
    struct l* prox; // ponteiro que aponta para o próximo nó da lista
    struct l* ant; // ponteiro que aponta nó antecessor na lista
}lista;

// função para criar e inicializar a lista, retorna NULL para mostrar que a lista está vazia
lista* criar (){
	return NULL;
}

// função para inserir um nó no final da lista
lista * inserirFim(lista *l, int i){
	lista* novo = (lista*)malloc(sizeof(lista)); // aloca espaço para o novo nó
	if(novo){
		// inicializa o novo nó
		novo->ant = NULL;
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux =l;
			while(aux->prox){
				aux = aux->prox;
			}
			novo->ant = aux; // o ponteiro para o antecessor do novo nó recebe o endereço do último nó da lista
			aux->prox = novo;// o último nó da lista recebe o novo nó criado
		}
		else{
			// se a lista estiver vazia, o ponteiro que aponta para o início da lista recebe o novo nó criado
			l = novo;
		}
	}
	else{
		printf("Erro de alocação");
	}
	
	return(l);
	
}

// função para inserir um nó no inicio da lista
lista * inserirInicio(lista *l, int i){
	lista* novo = (lista*)malloc(sizeof(lista));
	if(novo){
		novo->ant = NULL;
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux =l;// Guarda o endereço do início da lista
			l = novo; // Muda o endereço do inicio da lista
			novo->prox = aux; // Liga o novo nó a lista através do endereço armazendado
			aux->ant = novo;
		}
		else{
			l = novo;
		}
	}
	else{
		printf("Erro de alocação");
	}
	
	return(l);
	
}

// função para procurar um nó na lista
lista* procurarNo(lista* l, int k){
	// Copia o endereço do primeiro nó da lista para que não se perca enquanto se percorre a lista
	lista* aux = l;
	if(l){
		while(aux){
			if(aux->valor == k){
				return aux;
			}
			else{
				aux = aux->prox;
			}
		}
		if(aux == NULL){
			printf("Elemento inexistente na lista");
			return aux;
		}
	}
	else{
		printf("Lista inexistente");
		return l;
	}
}

// função para inserir um nó entre dois nós da lista
lista * inserirMeio(lista *l, int i, int k){
	lista* novo = (lista*)malloc(sizeof(lista));
	
	if(novo){
		novo->ant = NULL;
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux = procurarNo(l,k);  // procura o nó que irá preceder o novo nó
			novo->ant = aux; //liga o novo nó ao nó precendente
			novo->prox = aux->prox; //liga o novo nó ao nó que está após o nó precedente
			aux->prox->ant = novo; // liga o nó que está após o nó precedente ao novo nó
			aux->prox = novo;// liga o nó precedente ao novo nó
		}
		else{
			l = novo;
		}
	}
	else{
		printf("Erro de alocação");
	}
	
	return(l);	
}

// função para remover um nó da lista
lista* removerNo(lista* l, int k){
	lista* aux = l;
	lista* aux2 = NULL;
	
	if(l){
		// Procura o nó que precede o nó que se deseja apagar e percorre a lista
		while( aux!= NULL && aux->prox->valor!=k){
			aux = aux->prox;
		}
		if(aux->prox->valor == k){
			//nó encontrado
			aux2 = aux->prox; // guarda o endereço do nó que se deseja apagar
			aux->prox = aux->prox->prox; // Substitui o nó a ser removido pelo nó que está após ele
			aux->prox->ant = aux; // liga o nó que está após o nó a ser removido ao nó que antecede o nó a ser removido 
			free(aux2); // apaga o nó
		}
		else{
			printf("Nó inexistente");
		}
		
	}
	else{
		printf("Lista vazia");
	}
	return l;
}

// função para apagar a lista
lista* apagarLista(lista* l){
	lista* aux = l;
	lista* prox;
	
	// remove cada nó da lista
	while(aux){
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
	
	return NULL; // Inicializa a lista com NULL para indicar que está vazia
}

// função para imprimir todos os elementos da lista
void imprimirLista (lista* l) {
	if(l == NULL){
		printf("Lista vazia");
	}
	else{
		lista* aux = l;
    	while (aux != NULL) {
        	printf("%d -> ", aux -> valor);
        	aux = aux -> prox;
    	}
	}
}

// função para imprimir lista ao contrário
void imprimirListaReversa(lista* l){
	if(l == NULL){
		printf("Lista vazia");
	}
	else{
		lista* aux = l;
		
		//Procura o último nó da lista
    	while (aux->prox != NULL) {
        	aux = aux -> prox;
    	}
    	
    	while (aux != NULL) {
        	printf("%d -> ", aux -> valor);
        	aux = aux -> ant;
    	}
	}
}

// menu
void menu(lista* l){
	
	int n, valor, precede;
   	lista* no;
   	do{
   		printf("----------Lista Duplamente Ligadas ----------\n\n");
   		printf(" [1] Inserir nó no início da lista\n\n");
   		printf(" [2] Inserir nó no fim da lista\n\n");
   		printf(" [3] Inserir nó após um nó existente na lista\n\n");
   		printf(" [4] Procurar nó na lista\n\n");
   		printf(" [5] Imprimir a lista\n\n");
   		printf(" [6] Remover nó da lista\n\n");
   		printf(" [7] Apagar lista\n\n");
   		printf(" [8] Imprimir a lista de forma reversa\n\n");
   		printf(" [0] Sair\n\n");
   		scanf("%d", &n);
   		
   		switch(n){
   			
   			case 1:
   				printf("Valor do nó: ");
   				scanf("%d", &valor);
   				l = inserirInicio(l,valor);
   				printf("Nó inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 2:
   				printf("Valor do nó: ");
   				scanf("%d", &valor);
   				l = inserirFim(l,valor);
   				printf("Nó inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 3:
   				printf("Valor do nó: ");
   				scanf("%d", &valor);
   				printf("Valor do nó que deseja que preceda o novo nó: ");
   				scanf("%d", &precede);
   				l = inserirMeio(l,valor,precede);
   				printf("Nó inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 4:
   				printf("Valor do nó que deseja procurar: ");
   				scanf("%d", &valor);
   				no = procurarNo(l,valor);
   				if(no){
   					printf("Nó encontrado: %d ", no->valor);
				   }
				printf("\n\n");
				break;
				
   			case 5:
   				imprimirLista(l);
   				printf("\n\n");
   				break;
   				
   			case 6:
   				printf("Valor do nó que deseja remover: ");
   				scanf("%d", &valor);
   				l = removerNo(l,valor);
   				printf("Nó removido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 7:
   				l = apagarLista(l);
   				if (l){
   					printf("Erro ao apagar a lista");
				}
				else{
					printf("Lista apagada com sucesso");
				}
				printf("\n\n");
   				break;
   				
   			case 8:
   				imprimirListaReversa(l);
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
   	lista* l;
   	l = criar();
   	menu(l);
   	
    return 0;
}

