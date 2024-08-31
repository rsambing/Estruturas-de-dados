#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// as listas circulares podem ser simples ou duplamente ligadas
// o que caracteriza as listas circulares � o facto de que o �ltimo n� sempre aponta para o in�cio da lista
 
typedef struct l {
    int valor;
    struct l* prox; // ponteiro que aponta para o pr�ximo n� da lista
}lista;

// fun��o para criar e inicializar a lista, retorna NULL para mostrar que a lista est� vazia
lista* criar (){
	return NULL;
}

// fun��o para inserir um n� no final da lista
lista * inserirFim(lista *l, int i){
	lista* novo = (lista*)malloc(sizeof(lista)); // aloca espa�o para o novo n�
	if(novo){
		//inicializa��o do novo n�
		novo->valor = i; 
		novo->prox = NULL;
		
		if(l){
			lista* aux =l;
			// Percorre a lista recebendo o endere�o do pr�ximo n�
			//Quando o pr�ximo n� for igual ao endere�o do in�cio da lista ele para porque isso indica que est� no �ltimo n� da lista
			while(aux->prox != l){
				aux = aux->prox;
			}
			aux->prox = novo;// o �ltimo n� da lista recebe o novo n� criado
			novo->prox = l;// o sucessor do novo n� aponta para o in�cio da lista 
		}
		else{
			l = novo;
			novo->prox = l;
		}
	}
	else{
		printf("Erro de aloca��o");
	}
	
	return(l);
	
}

// fun��o para procurar um n� na lista
lista* procurarNo(lista* l, int k){
	lista* aux = l; // Copia o endere�o do primeiro n� da lista para que n�o se perca enquanto se percorre a lista
	if(l){
		// enquanto n�o estiver no �ltimo n�, percorre a lista
		while(aux->prox != l){
			if(aux->valor == k){
				// n� encontrado 
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

// fun��o para inserir um n� entre dois n�s da lista
lista * inserirMeio(lista *l, int i, int k){
	lista* novo = (lista*)malloc(sizeof(lista));
	
	if(novo){
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux = procurarNo(l,k);// procura o n� que ir� preceder o novo n�
			lista* aux2 = aux->prox;// guarda o endere�o do n� que est� a seguir o n� precedente
			aux->prox = novo;
			novo->prox = aux2;
		}
		else{
			l = novo;
			novo->prox = l;
		}
	}
	else{
		printf("Erro de aloca��o");
	}
	
	return(l);	
}

// fun��o para remover um n� da lista
lista* removerNo(lista* l, int k){
	lista* aux = l;
	lista* aux2 = NULL;
	
	if(l){
		// Procura o n� que precede o n� que se deseja apagar e percorre a lista
		while( aux->prox != l && aux->prox->valor != k){
			aux = aux->prox;
		}
		if(aux->prox->valor == k){
			//n� encontrado
			aux2=aux->prox; // guarda o endere�o do n� que se deseja apagar
			aux->prox = aux->prox->prox; // armazena o n� que est� ap�s o n� que deseja apagar  
			free(aux2); // apaga o n�
		}
		else{
			printf("N� inexistente");
		}	
	}
	else{
		printf("Lista vazia");
	}
	return l;
}

// fun��o para apagar a lista
lista* apagarLista(lista* l){
	lista* aux = l;
	lista* prox;
	
	// remove cada n� da lista
	while(aux){
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
	
	// Inicializa a lista com NULL para indicar que est� vazia
	return NULL;
}

// fun��o para imprimir todos os elementos da lista
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
   		printf(" [1] Inserir n� no fim da lista\n\n");
   		printf(" [2] Inserir n� ap�s um n� existente na lista\n\n");
   		printf(" [3] Procurar n� na lista\n\n");
   		printf(" [4] Imprimir a lista\n\n");
   		printf(" [5] Remover n� da lista\n\n");
   		printf(" [6] Apagar lista\n\n");
   		printf(" [0] Sair\n\n");
   		scanf("%d", &n);
   		
   		switch(n){
   				
   			case 1:
   				printf("Valor do n�: ");
   				scanf("%d", &valor);
   				l = inserirFim(l,valor);
   				printf("N� inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 2:
   				printf("Valor do n�: ");
   				scanf("%d", &valor);
   				printf("Valor do n� que deseja que preceda o novo n�: ");
   				scanf("%d", &precede);
   				l = inserirMeio(l,valor,precede);
   				printf("N� inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 3:
   				printf("Valor do n� que deseja procurar: ");
   				scanf("%d", &valor);
   				no = procurarNo(l,valor);
   				if(no){
   					printf("N� encontrado: %d ", no->valor);
				   }
				printf("\n\n");
				break;
				
   			case 4:
   				imprimirLista(l);
   				printf("\n\n");
   				break;
   				
   			case 5:
   				printf("Valor do n� que deseja remover: ");
   				scanf("%d", &valor);
   				l = removerNo(l,valor);
   				printf("N� removido com sucesso");
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
				printf("Op��o inv�lida");
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

