#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "conio.c"
#include <string.h>
#include <time.h>
#include <windows.h>

void PilaMoneda();
void juego();
int turno();
void usuario();
void computadora();
void graficPila(int &aux);
//Global
int pila=0, moneda, minimo, maximo,  extraccion=0;
bool comienza;

main(){
	int verificar;
	bool op=true;
	while(op==true){
		PilaMoneda();
		juego();
		printf("\nQuieres volver a jugar? (Para SI ingrese '1', para NO ingrese '2'): " );
		scanf("%d", &verificar);
				if(verificar==2){
					op=false;
				}
				else{
					system("cls");
				}
	}
}

void PilaMoneda(){
	srand(time(NULL));
	pila=rand()%(51-1);
	if(pila<10){
		pila+=10;
	}
}

void juego(){
	int verificar, auxPila=pila;
	printf("\n %d",pila);
	printf("\n Ingresar el valor minimo de monedas a sacar por turno: " );
	scanf("%d", &minimo);
	printf("\n Ingresar el valor maximo de monedas a sacar por turno: " );
	scanf("%d", &maximo);
	verificar=turno();
		if(verificar==1){
			printf("\nInicia la partida el usuario.\n");
		}
		else{
			printf("\nInicia la partida la computadora.\n");
		}
	while(pila!=0 and pila>minimo){
		
		if(verificar==2){
			computadora();
		
			printf("\n La computadora saco %d monedas\n", extraccion);
			printf("\nQuedan %d monedas\n",pila);
			system("pause");
			system("cls");
	}
			verificar--;
		}
		if(verificar==1){
			usuario();
			
			printf("\nQuedan %d monedas\n",pila);
			verificar++;
		}
	
	if(verificar==1 and pila==0){
		printf("\n LA COMPUTADORA GANO!!! Puntaje obtenido: 0\n");
	}
	if(verificar==2 and pila==0){
		printf("\n GANASTE!!! Puntaje obtenido: 5\n");
	}
	if(pila!=0){
		printf("\n NO HAY GANADOR\n\n");
	}
		
		
}
void graficPila(int &aux){
	//x>=85 y>=16
	int porcenPila, valorRelativo;
	porcenPila=extraccion*100/aux;
	valorRelativo=porcenPila*14/100;
	
	for(int i=16; i<35; i++){
		gotoxy(90, i); printf("%c", 178);
		gotoxy(110, i); printf("%c", 178);
	}
	for(int i=90; i<111; i++){
		gotoxy(i, 16); printf("%c", 178);
		gotoxy(i, 34); printf("%c", 178);
	}
}

int turno(){
	return 1 + rand()%(2+1 - 1);	
}

void usuario(){
	printf("\nElija la cantidad de monedas a sacar: ");
	scanf("%d", &moneda);
		if(moneda<=maximo and moneda>=minimo){
			pila-=moneda;
		}else{
			printf("\n Por favor ingresar un valor que se encuentre entre %d y %d\n ", minimo, maximo);
			printf("\nElija la cantidad de monedas a sacar: ");
			scanf("%d", &moneda);
			pila-=moneda;
		}
}

void computadora(){
	extraccion= minimo + rand()%(maximo + 1 - minimo);
	pila-=extraccion;
}

