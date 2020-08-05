#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void PilaMoneda();
void juego();
bool turno();
void usuario(int &Pila);
void computadora(int &Pila, int Minimo, int Maximo);

//Global
int pila=0, moneda, minimo, maximo;

main(){
	int verificar;
	bool op=true;
	PilaMoneda();
	while(op==true){
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
	pila= 10 + rand()%(50+1 - 10);
}


void juego(){
	//printf("\n %d",pila);
	printf("\n Ingresar el valor minimo de monedas a sacar por turno: " );
	scanf("%d", &minimo);
	printf("\n Ingresar el valor maximo de monedas a sacar por turno: " );
	scanf("%d", &maximo);
		if(turno()==true){
			usuario(pila);
		}
		else{
			computadora(pila, minimo, maximo);
		}
			printf("\nQuedan %d monedas\n",pila);
}

bool turno(){
	int Turno;
	Turno= 1 + rand()%(2+1 - 1);
		if(Turno==1){
			return true;	
		}
		else{
			return false;
		}
}



void usuario(int &Pila){
	printf("\nInicia la partida el usuario.\n");
	printf("\nElija la cantidad de monedas a sacar: ");
	scanf("%d", &moneda);
		if(moneda<=maximo and moneda>=minimo){
			pila=pila-moneda;
		}else{
			printf("\n Por favor ingresar un valor que se encuentre entre %d y %d: ", minimo, maximo);
			scanf("%d", &moneda);
			pila=pila-moneda;
		}
}

void computadora(int &Pila, int Minimo, int Maximo){
	int extraccion=0;
	extraccion= Minimo + rand()%(Maximo + 1 - Minimo);
	Pila= Pila-extraccion;
}
