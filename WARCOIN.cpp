#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <conio.c>
#include <string.h>
#include <time.h>
#include <windows.h>

void PilaMoneda();
void Titulo();
void PedirDatos();
void GenerarTurno();
void Juego();
void Informacion();
void usuario();
void computadora();
void GraficMonedas();
//Global
int pila=0, moneda, minimo, maximo,  extraccion=0, turno=0;
bool comienza;

main(){
	int verificar;
	bool op=true;
	while(op==true){
		PilaMoneda();
		Titulo();
		PedirDatos();
		GenerarTurno();
		Juego();
		textcolor(YELLOW);
		gotoxy(5, 15); printf("\n%c Quieres volver a jugar? (Para SI ingrese '1', para NO ingrese '2'): ", 175);
		scanf("%d", &verificar);
		printf("\n");
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
	pila=1+rand()%(50+1-1);
}

void Titulo(){
	textcolor(5);
		for(int i=56; i<65; i++){
  			gotoxy(i, 3); printf("%c", 205);
    		gotoxy(i, 5); printf("%c", 205);
 		 }
  			for(int i=3; i<5; i++){
    			gotoxy(56, i); printf("%c", 186);
    			gotoxy(64, i); printf("%c", 186);
			}
	gotoxy(56, 3); printf("%c", 201);
	gotoxy(56, 5); printf("%c", 200);
	gotoxy(64, 3); printf("%c", 187);
	gotoxy(64, 5); printf("%c", 188);
	
	gotoxy(10, 4); printf("===========================================>");
	gotoxy(57, 4); printf("WARCOIN");
	gotoxy(67,4); printf("<============================================");
}

void PedirDatos(){
	textcolor(WHITE); 
	gotoxy(34, 8); printf("%cIngresar el valor minimo de monedas a sacar por turno: ", 175);
	scanf("%d", &minimo);
	gotoxy(34, 10); printf("%cIngresar el valor maximo de monedas a sacar por turno: ", 175);
	scanf("%d", &maximo);
	gotoxy(5,13); printf("----------------------------------------------------------------------------------------------------------------\n");
}

void Juego(){
	int contador=0, terminar=1;
		while(terminar!=0){
			if(turno==2){
				textcolor(GREEN); printf("\n\t\tLa pila tiene %d modenas\n",pila);
				computadora();
				if(pila<=minimo){
						terminar=0;
					}
				turno--;
					
			}
				if(turno==1){
					textcolor(GREEN); printf("\n\t\tLa pila tiene %d modenas\n",pila);
					usuario();
					textcolor(GREEN);
						if(pila<=minimo){
							terminar=0;
						}
					turno++;
				}
				contador++;
					if(contador==2){
						Sleep(500);
						system("cls");
						contador=0;
						Titulo();
						Informacion();
					}
		}
		system("cls");
	if(turno==1 and pila==0){
		textcolor(GREEN);
			for(int i=46; i<85; i++){
				gotoxy(i, 5); printf("%c", 205);
				gotoxy(i, 11); printf("%c", 205);
			}
				for(int i=5; i<12; i++){
					gotoxy(46, i); printf("%c", 186);
					gotoxy(84, i); printf("%c", 186);
				}
		gotoxy(46, 5); printf("%c", 201);
		gotoxy(46, 11); printf("%c", 200);
		gotoxy(84, 5); printf("%c", 187);
		gotoxy(84, 11); printf("%c", 188);
		gotoxy(50, 8); printf("GANASTE!!! Puntaje obtenido: 5");
	}else{
		textcolor(LIGHTRED);
			for(int i=37; i<85; i++){
				gotoxy(i, 5); printf("%c", 205);
				gotoxy(i, 11); printf("%c", 205);
			}
				for(int i=5; i<12; i++){
					gotoxy(37, i); printf("%c", 186);
					gotoxy(84, i); printf("%c", 186);
				}	
		gotoxy(37, 5); printf("%c", 201);
		gotoxy(37, 11); printf("%c", 200);
		gotoxy(84, 5); printf("%c", 187);
		gotoxy(84, 11); printf("%c", 188);
		gotoxy(40, 8); printf("LA COMPUTADORA GANO!!! Puntaje obtenido: 0");
	}
}

void GenerarTurno(){
	turno= 1 + rand()%(2+1 - 1);
		if(turno==1){
			textcolor(LIGHTRED); printf("\n\t\tInicia la partida el usuario.\n");
		}else{
			textcolor(LIGHTRED); printf("\n\tInicia la partida la computadora.\n");
		}
}

void Informacion(){
	textcolor(WHITE); 
	gotoxy(34, 8); printf("%cLa cantidad minima permitida para sacar monedas es: %d", 175, minimo);
	gotoxy(34, 10); printf("%cLa cantidad maxima permitida para sacar monedas es: %d", 175, maximo);
	gotoxy(5,13); printf("----------------------------------------------------------------------------------------------------------------\n");
}

void usuario(){
	textcolor(YELLOW); printf("\n\t%cTurno del usuario%c\n", 175, 174);
	textcolor(WHITE); printf("\n\tElija la cantidad de monedas a sacar: ");
	scanf("%d", &moneda);
		if(moneda<=maximo and moneda>=minimo){
			pila-=moneda;
		}else{
			printf("\n\nPor favor ingresar un valor que se encuentre entre %d y %d\n ", minimo, maximo);
			printf("\n\nElija la cantidad de monedas a sacar: ");
			scanf("%d", &moneda);
			pila-=moneda;
		}
}

void computadora(){
	textcolor(3); printf("\n\t%cTurno de la computadora%c\n", 175, 174);
	Sleep(500);
	extraccion= minimo + rand()%(maximo + 1 - minimo);
	textcolor(WHITE); printf("\n\tLa computadora saco %d monedas\n", extraccion);
	pila-=extraccion;
}
