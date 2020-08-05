/*Consiste en una pila de monedas, de la cual el jugador y la computadora van sacando monedas hasta que ya no
quedan más en la pila. El que vacía la pila de monedas es quien gana el juego.
Antes de comenzar el juego, el jugador ingresa la cantidad mínima y la cantidad máxima de monedas que se puede
sacar en cada turno. Luego de realizado esto, la computadora elegirá un valor al azar entre 10 y 50, que representará
la cantidad inicial de monedas que tendrá la pila.
Una vez que se ingresa toda la información inicial, el programa deberá decidir en forma aleatoria quién inicia la
jugada: si el usuario o la computadora.
Si le toca al jugador, éste elige la cantidad de monedas a retirar de la pila: un valor entre cantidad mínima y cantidad
máxima. Si se da alguna de las dos situaciones de fin de juego, el jugador gana el juego.
Si aún quedan monedas luego de que el jugador saca la cantidad elegida de la pila, es el turno de la computadora, la
cual elige la cantidad a sacar. Si se da alguna de las dos situaciones de fin de juego, la computadora gana el juego.
La secuencia de turnos se repite hasta que se dé alguna de las dos situaciones de fin de juego.
Puntaje: Si gana el jugador obtiene 5 puntos, en caso contrario obtiene 0 puntos.*/

/*#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void juego();

int pila, turno, moneda;
int minimo,maximo;

main(){
	juego();
}
void juego(){
	srand(time(NULL));
	pila= 10 + rand()%(50+1 - 10);
	//printf("\n %d",pila);//
	printf("\n Ingresar el valor minimo de monedas a sacar por turno: " );
	scanf("%d", &minimo);
	printf("\n Ingresar el valor maximo de monedas a sacar por turno: " );
	scanf("%d", &maximo);
		turno= 1 + rand()%(2+1 - 1);
			if(turno==1){
				printf("\n Elija la cantidad de monedas a sacar: ");
				scanf("%d", &moneda);
					if(moneda<=maximo and moneda>=minimo){
						pila=pila-moneda;
					}else{
						printf("\n Por favor ingresar un valor que se encuentre entre %d y %d: ", minimo, maximo);
						scanf("%d", &moneda);
						pila=pila-moneda;
					}
			}
			printf("\n %d",pila);
}*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void PilaMoneda();
void juego();
int turno();
void usuario(int &Pila);
void computadora(int &Pila, int Minimo, int Maximo);

//Global
int pila=0, moneda, minimo, maximo,  extraccion=0;
bool comienza;

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
	int verificar;
	printf("\n %d",pila);
	printf("\n Ingresar el valor minimo de monedas a sacar por turno: " );
	scanf("%d", &minimo);
	printf("\n Ingresar el valor maximo de monedas a sacar por turno: " );
	scanf("%d", &maximo);
	verificar=turno();
		if(verificar==1){
			printf("\nInicia la partida el usuario.\n");
			usuario(pila);
			printf("\nQuedan %d monedas\n",pila);
		}
		else{
			printf("\nInicia la partida la computadora.\n");
			computadora(pila, minimo, maximo);
			printf("\n La computadora saco %d monedas\n", extraccion);
			printf("\nQuedan %d monedas\n",pila);
		}
	while(verificar==1 and pila>minimo){
			computadora(pila, minimo, maximo);
			printf("\n La computadora saco %d monedas\n", extraccion);
			printf("\nQuedan %d monedas\n",pila);
			usuario(pila);
			printf("\nQuedan %d monedas\n",pila);
	}
	while(verificar==2 and pila>minimo){
			usuario(pila);
			printf("\nQuedan %d monedas\n",pila);
			computadora(pila, minimo, maximo);
			printf("\n La computadora saco %d monedas\n", extraccion);
			printf("\nQuedan %d monedas\n",pila);
		}
		printf("\n LA COMPUTADORA GANO!!! Puntaje obtenido: 0\n");
		printf("\n GANASTE!!! Puntaje obtenido: 5\n");
}

int turno(){
	int Turno;
	return Turno= 1 + rand()%(2+1 - 1);	
}



void usuario(int &Pila){
	printf("\nElija la cantidad de monedas a sacar: ");
	scanf("%d", &moneda);
		if(moneda<=maximo and moneda>=minimo){
			pila=pila-moneda;
		}else{
			printf("\n Por favor ingresar un valor que se encuentre entre %d y %d\n ", minimo, maximo);
			printf("\nElija la cantidad de monedas a sacar: ");
			scanf("%d", &moneda);
			pila=pila-moneda;
		}
}

void computadora(int &Pila, int Minimo, int Maximo){
	
	extraccion= Minimo + rand()%(Maximo + 1 - Minimo);
	Pila= Pila-extraccion;
}

