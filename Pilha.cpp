#include<iostream>
#include<stdlib.h>
using namespace std;

// Estrutura da pilha
struct pilha{
	int valor;
	struct pilha *prox;
}*prim,*ult,*aux;

// Assinaturas das funções
void push(int v);// Inclue um valor no topo da pilha
void pop();// Exclue um valor no topo da pilha
int top();// Lista o valor do topo
void listagem();// Lista todos os elementos da pilha
bool veri(int v);// Verifica se um dado valor está na pilha

// Programa principal
main(){
	int op,v;
	do{
		cout << "1 - Empilhar\n";
		cout << "2 - Desempilhar\n";
		cout << "3 - Topo\n";
		cout << "4 - Lista total\n";
		cout << "5 - Verificar se um valor esta na pilha\n";
		cout << "0 - Sair\n";
		cin >> op;
		switch(op){
			case 1:
				cout << "Digite um valor: ";
				cin >> v;
				push(v);
				break;
			case 2:
				pop();
				break;
			case 3:
				v = top();
				if(v != -1){
					cout << "Topo: " << v << "\n";
				} else{
					cout << "Pilha vazia\n";
				}
				break;
			case 4:
				listagem();
				break;
			case 5:
				cout << "Digite um valor para verificar: ";
				cin >> v;
				bool ve = veri(v);
				if(ve){
					cout << "O valor consta na lista!\n";
				} else{
					cout << "O valor nao consta na lista\n";
				}
				break;
			default:
				cout << "Opcao invalida\n";
		}
	}while(op != 0);
}

//Inclusão no topo
void push(int v){
	aux = (struct pilha *)malloc(sizeof(struct pilha));
	if(ult == NULL){
		ult = aux;
	} else{
		aux->prox = prim;
	}
	prim = aux;
	prim->valor = v;
	ult->prox = NULL;
	cout << "Elemento empilhado!\n";
}

// Exclusão do topo
void pop(){
	if(prim != NULL){
		aux = prim;
		if(prim == ult){
			prim = ult = NULL;
		} else{
			prim = prim->prox;
		}
		cout << "Topo desempilhado: " << aux->valor << "\n";
		free(aux);
	} else{
		cout << "Pilha Vazia\n";
	}
}

// Listagem do valor do topo
int top(){
	if(prim != NULL){
		return (prim->valor);
	} else{
		return (-1);
	}
}

// Listagem de toda a pilha
void listagem(){
	if(prim != NULL){
		aux = prim;
		cout << "Valores na pilha\n";
		while(aux != NULL){
			cout << aux->valor << "\n";
			aux = aux->prox;
		}
	} else{
		cout << "Pilha vazia\n";
	}
}

// Verificar um dado elemento na pilha
bool veri(int v){
	if(prim != NULL){
		aux = prim;
		bool verificado = false;
		while(aux != NULL){
			if(aux->valor == v){
				verificado = true;
				break;
			}
			aux = aux->prox;
		}
		return verificado;
	} else {
		cout << "Lista vazia!";
	}
}
