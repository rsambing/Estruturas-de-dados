#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct l {
    int valor;
    struct l* prox; // ponteiro que aponta para o pr�ximo n� da lista
    struct l* ant; // ponteiro que aponta n� antecessor na lista
}lista;

// fun��o para criar e inicializar a lista, retorna NULL para mostrar que a lista est� vazia
lista* criar (){
	return NULL;
}

// fun��o para inserir um n� no final da lista
lista * inserirFim(lista *l, int i){
	lista* novo = (lista*)malloc(sizeof(lista)); // aloca espa�o para o novo n�
	if(novo){
		// inicializa o novo n�
		novo->ant = NULL;
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux =l;
			while(aux->prox){
				aux = aux->prox;
			}
			novo->ant = aux; // o ponteiro para o antecessor do novo n� recebe o endere�o do �ltimo n� da lista
			aux->prox = novo;// o �ltimo n� da lista recebe o novo n� criado
		}
		else{
			// se a lista estiver vazia, o ponteiro que aponta para o in�cio da lista recebe o novo n� criado
			l = novo;
		}
	}
	else{
		printf("Erro de aloca��o");
	}
	
	return(l);
	
}

// fun��o para inserir um n� no inicio da lista
lista * inserirInicio(lista *l, int i){
	lista* novo = (lista*)malloc(sizeof(lista));
	if(novo){
		novo->ant = NULL;
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux =l;// Guarda o endere�o do in�cio da lista
			l = novo; // Muda o endere�o do inicio da lista
			novo->prox = aux; // Liga o novo n� a lista atrav�s do endere�o armazendado
			aux->ant = novo;
		}
		else{
			l = novo;
		}
	}
	else{
		printf("Erro de aloca��o");
	}
	
	return(l);
	
}

// fun��o para procurar um n� na lista
lista* procurarNo(lista* l, int k){
	// Copia o endere�o do primeiro n� da lista para que n�o se perca enquanto se percorre a lista
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

// fun��o para inserir um n� entre dois n�s da lista
lista * inserirMeio(lista *l, int i, int k){
	lista* novo = (lista*)malloc(sizeof(lista));
	
	if(novo){
		novo->ant = NULL;
		novo->valor = i;
		novo->prox= NULL;
		
		if(l){
			lista* aux = procurarNo(l,k);  // procura o n� que ir� preceder o novo n�
			novo->ant = aux; //liga o novo n� ao n� precendente
			novo->prox = aux->prox; //liga o novo n� ao n� que est� ap�s o n� precedente
			aux->prox->ant = novo; // liga o n� que est� ap�s o n� precedente ao novo n�
			aux->prox = novo;// liga o n� precedente ao novo n�
		}
		else{
			l = novo;
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
		while( aux!= NULL && aux->prox->valor!=k){
			aux = aux->prox;
		}
		if(aux->prox->valor == k){
			//n� encontrado
			aux2 = aux->prox; // guarda o endere�o do n� que se deseja apagar
			aux->prox = aux->prox->prox; // Substitui o n� a ser removido pelo n� que est� ap�s ele
			aux->prox->ant = aux; // liga o n� que est� ap�s o n� a ser removido ao n� que antecede o n� a ser removido 
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
	
	return NULL; // Inicializa a lista com NULL para indicar que est� vazia
}

// fun��o para imprimir todos os elementos da lista
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

// fun��o para imprimir lista ao contr�rio
void imprimirListaReversa(lista* l){
	if(l == NULL){
		printf("Lista vazia");
	}
	else{
		lista* aux = l;
		
		//Procura o �ltimo n� da lista
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
   		printf(" [1] Inserir n� no in�cio da lista\n\n");
   		printf(" [2] Inserir n� no fim da lista\n\n");
   		printf(" [3] Inserir n� ap�s um n� existente na lista\n\n");
   		printf(" [4] Procurar n� na lista\n\n");
   		printf(" [5] Imprimir a lista\n\n");
   		printf(" [6] Remover n� da lista\n\n");
   		printf(" [7] Apagar lista\n\n");
   		printf(" [8] Imprimir a lista de forma reversa\n\n");
   		printf(" [0] Sair\n\n");
   		scanf("%d", &n);
   		
   		switch(n){
   			
   			case 1:
   				printf("Valor do n�: ");
   				scanf("%d", &valor);
   				l = inserirInicio(l,valor);
   				printf("N� inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 2:
   				printf("Valor do n�: ");
   				scanf("%d", &valor);
   				l = inserirFim(l,valor);
   				printf("N� inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 3:
   				printf("Valor do n�: ");
   				scanf("%d", &valor);
   				printf("Valor do n� que deseja que preceda o novo n�: ");
   				scanf("%d", &precede);
   				l = inserirMeio(l,valor,precede);
   				printf("N� inserido com sucesso");
   				printf("\n\n");
   				break;
   				
   			case 4:
   				printf("Valor do n� que deseja procurar: ");
   				scanf("%d", &valor);
   				no = procurarNo(l,valor);
   				if(no){
   					printf("N� encontrado: %d ", no->valor);
				   }
				printf("\n\n");
				break;
				
   			case 5:
   				imprimirLista(l);
   				printf("\n\n");
   				break;
   				
   			case 6:
   				printf("Valor do n� que deseja remover: ");
   				scanf("%d", &valor);
   				l = removerNo(l,valor);
   				printf("N� removido com sucesso");
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

