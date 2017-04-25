#include<iostream>
#include<stdlib.h>
using namespace std;

// Estrutura da pilha
struct pilha{
	int valor;
	struct pilha *prox;
}*prim,*ult,*aux;

// Assinaturas das funções
void push(int v);
void pop();
int top();

// Programa principal
main(){
	int op,v;
	do{
		cout << "1 - Empilhar\n";
		cout << "2 - Desempilhar\n";
		cout << "3 - Topo\n";
		cout << "4 - Sair\n";
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
		}
	}while(op != 4);
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
