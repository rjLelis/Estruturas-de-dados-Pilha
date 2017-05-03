#include<iostream>
#include<stdlib.h>
using namespace std;
//Registros
struct itemPilha{
	int valor;
	struct itemPilha *prox;
}*prim,*ult,*primaux,*ultaux;
//Assinaturas
void push(int v);
void pop();
int top();
//Assinaturas auxiliares
void pushAux(int v);
void popAux();
int topAux();
//Funções do exercício
int verifica(int v);
int ContaValor(int v);
void esvaziar();
int ContaElemento();
void ContaPar();

main(){
	int op,v;
	do{
		system("CLS");
		cout << "1 - Push\n";
		cout << "2 - Pop\n";
		cout << "3 - Top\n";
		cout << "4 - Verificar se um numero esta na pilha\n";
		cout << "5 - Contar quantas vezes um elemento se repeta na pilha\n";
		cout << "6 - Esvaziar\n";
		cout << "7 - Contar quantos elementos tem na pilha\n";
		cout << "8 - Mostrar os elementos pares da pilha\n";
		cout << "0 - Sair\n\n";
		cout << ">>> ";
		cin >> op;
		if(op == 1){
			system("CLS");
			cout << "Digite um valor para empilhar: ";
			cin >> v;
			push(v);
		}else if(op == 2){
			system("CLS");
			if(top() != -1){
				cout << "O valor " << top() << " foi desimpilhado\n";
				pop();
			} else{
				cout << "Pilha vazia\n";
			}
			system("pause");
		} else if(op == 3){
			system("CLS");
			if(top() != -1){
				cout << "O valor " << top() << " esta no topo\n";
			} else{
				cout << "Pilha vazia\n";
			}
			system("pause");
		} else if(op == 4){
			system("CLS");
			if(top() != -1){
				cout << "Digite um numero para verificar: ";
				cin >> v;
				if(verifica(v) == 1){
					cout << "O valor digitado ESTA na pilha\n";
				} else{
					cout << "O valor digitado NAO ESTA na pilha\n";
				}
			} else{
				cout << "Pilha vazia\n";
			}
			system("pause");
		} else if(op == 5){
			system("CLS");
			if(top() != -1){
				cout << "Digite um elemento para verificar: ";
				cin >> v;
				cout << "O valor digitado se repete " << ContaValor(v) << " vezes\n";
			} else{
				cout << "Pilha vazia\n";
			}
			system("pause");
		} else if(op == 6){
			system("CLS");
			if(top() != -1){
				esvaziar();
				cout << "Pilha esvaziada\n";
			} else{
				cout << "A pilha ja esta vazia\n";
			}
			system("pause");
		} else if(op == 7){
			system("CLS");
			if(top() != -1){
				cout << "A pilha tem " << ContaElemento() << " elementos\n";
			} else{
				cout << "A pilha vazia\n";
			}
			system("pause");
		} else if(op == 8){
			system("CLS");
			if(top() != -1){
				cout << "Elementos pares na pilha: \n";
				ContaPar();
			} else{
				cout << "A pilha vazia\n";
			}
			system("pause");
		}
	}while(op != 0);
}

void push(int v){
	struct itemPilha *aux;
	aux = (struct itemPilha *) malloc(sizeof(struct itemPilha));
	if(!ult){
		ult = aux;
	} else{
		aux->prox = prim;
	}
	prim = aux;
	prim->valor = v;
	ult->prox = NULL;
}

void pop(){
	struct itemPilha *aux;
	if(!prim){
		cout << "Pilha vazia\n";
	} else{
		aux = prim;
		if(prim == ult){
			prim = ult = NULL;
		} else{
			prim = prim->prox;
		}
		free(aux);
	}
}

int top(){
	if(!prim){
		return(-1);
	} else{
		return(prim->valor);
	}
}

void pushAux(int v){
	struct itemPilha *aux;
	aux = (struct itemPilha *) malloc(sizeof(struct itemPilha));
	if(!ultaux){
		ultaux = aux;
	} else{
		aux->prox = primaux;
	}
	primaux = aux;
	primaux->valor = v;
	ultaux->prox = NULL;
}

void popAux(){
	struct itemPilha *aux;
	if(!primaux){
		cout << "Pilha vazia";
	} else{
		aux = primaux;
		if(primaux == ultaux){
			primaux = ultaux = NULL;
		} else{
			primaux = primaux->prox;
		}
		free(aux);
	}
}

int topAux(){
	if(!primaux){
		return (-1);
	} else{
		return (primaux->valor);
	}
}

int verifica(int v){
	int aux = -1,achei = 0;
	primaux = ultaux = NULL;
	aux = top();
	while(top() != -1){
		if(aux == v)
			achei = 1;
		pushAux(top());
		pop();
		aux = top();
	}
	while(topAux() != -1){
		push(topAux());
		popAux();
	}
	
	if(achei == 1)
		return (1);
	 else
		return (0);
}

int ContaValor(int v){
	int aux = -1,cont = 0;
	primaux = ultaux = NULL;
	aux = top();
	while(top() != -1){
		if(aux == v){
			cont++;
		}
		pushAux(top());
		pop();
		aux = top();
	}
	while(topAux() != -1){
		push(topAux());
		popAux();
	}
	return cont;
}

void esvaziar(){
	while(top() != -1){
		pop();
	}
}

int ContaElemento(){
	int aux,cont = 0;
	primaux = ultaux = NULL;
	aux = top();
	while(top() != -1){
		cont++;
		pushAux(top());
		pop();
		aux = top();
	}
	while(topAux() != -1){
		push(topAux());
		popAux();
	}
	return cont;
}

void ContaPar(){
	int aux;
	primaux = ultaux = NULL;
	aux = top();
	while(top() != -1){
		if(aux % 2 == 0){
			cout << aux << endl;
		}
		pushAux(top());
		pop();
		aux = top();
	}
	while(topAux() != -1){
		push(topAux());
		popAux();
	}
	
}
