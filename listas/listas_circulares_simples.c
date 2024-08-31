#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// as listas circulares podem ser simples ou duplamente ligadas
// o que caracteriza as listas circulares é o facto de que o último nó sempre aponta para o início da lista
 
typedef struct l {
    int valor;
    struct l* prox; // ponteiro que aponta para o próximo nó da lista
}lista;

// função para criar e inicializar a lista, retorna NULL para mostrar que a lista está vazia
lista* criar (){
	return NULL;
}

// função para inserir um nó no final da lista
lista * inserirFim(lista *l, int i){
	lista* novo = (lista*)malloc(sizeof(lista)); // aloca espaço para o novo nó
	if(novo){
		//inicialização do novo nó
		novo->valor = i; 
		novo->prox = NULL;
		
		if(l){
			lista* aux =l;
			// Percorre a lista recebendo o endereço do próximo nó
			//Quando o próximo nó for igual ao endereço do início da lista ele para porque isso indica que está no último nó da lista
			while(aux->prox != l){
				aux = aux->prox;
			}
			aux->prox = novo;// o último nó da lista recebe o novo nó criado
			novo->prox = l;// o sucessor do novo nó aponta para o início da lista 
		}
		else{
			l = novo;
			novo->prox = l;
		}
	}
	else{
		printf("Erro de alocação");
	}
	
	return(l);
	
}

// função para procurar um nó na lista
lista* procurarNo(lista* l, int k){
	lista* aux = l; // Copia o endereço do primeiro nó da lista para que não se perca enquanto se percorre a lista
	if(l){
		// enquanto não estiver no último nó, percorre a lista
		while(aux->prox != l){
			if(aux->valor == k){
				// nó encontrado 
				return aux;
			}
			else{
				aux = aux->prox;
			}
		}
		if(aux->prox == l ){
			printf("Elemento inexistente na lista");
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
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux = procurarNo(l,k);// procura o nó que irá preceder o novo nó
			lista* aux2 = aux->prox;// guarda o endereço do nó que está a seguir o nó precedente
			aux->prox = novo;
			novo->prox = aux2;
		}
		else{
			l = novo;
			novo->prox = l;
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
		while( aux->prox != l && aux->prox->valor != k){
			aux = aux->prox;
		}
		if(aux->prox->valor == k){
			//nó encontrado
			aux2=aux->prox; // guarda o endereço do nó que se deseja apagar
			aux->prox = aux->prox->prox; // armazena o nó que está após o nó que deseja apagar  
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
	
	// Inicializa a lista com NULL para indicar que está vazia
	return NULL;
}

// função para imprimir todos os elementos da lista
void imprimirLista (lista* l) {
	if(l == NULL){
		printf("Lista vazia");
	}
	else{
		lista* aux = l;
    	while (aux->prox != l) {
        	printf("%d -> ", aux -> valor);
        	aux = aux -> prox;
    	}
    	printf("%d -> ", aux -> valor);
	}
}

// menu
void menu(lista* l){
	
	int n, valor, precede;
   	lista* no;
   	do{
   		printf("----------Lista Circulares Simples----------\n\n");
   		printf(" [1] Inserir nó no fim da lista\n\n");
   		printf(" [2] Inserir nó após um nó existente na lista\n\n");
   		printf(" [3] Procurar nó na lista\n\n");
   		printf(" [4] Imprimir a lista\n\n");
   		printf(" [5] Remover nó da lista\n\n");
   		printf(" [6] Apagar lista\n\n");
   		printf(" [0] Sair\n\n");
   		scanf("%d", &n);
   		
   		switch(n){
   				
   			case 1:
   				printf("Valor do nó: ");
   				scanf("%d", &valor);
   				l = inserirFim(l,valor);
   				printf("Nó inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 2:
   				printf("Valor do nó: ");
   				scanf("%d", &valor);
   				printf("Valor do nó que deseja que preceda o novo nó: ");
   				scanf("%d", &precede);
   				l = inserirMeio(l,valor,precede);
   				printf("Nó inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 3:
   				printf("Valor do nó que deseja procurar: ");
   				scanf("%d", &valor);
   				no = procurarNo(l,valor);
   				if(no){
   					printf("Nó encontrado: %d ", no->valor);
				   }
				printf("\n\n");
				break;
				
   			case 4:
   				imprimirLista(l);
   				printf("\n\n");
   				break;
   				
   			case 5:
   				printf("Valor do nó que deseja remover: ");
   				scanf("%d", &valor);
   				l = removerNo(l,valor);
   				printf("Nó removido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 6:
   				l = apagarLista(l);
   				if (l){
   					printf("Erro ao apagar a lista");
				}
				else{
					printf("Lista apagada com sucesso");
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
   	lista* l;
   	l = criar();
   	menu(l);
   	
    return 0;
}

