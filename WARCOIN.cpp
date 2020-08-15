#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "main.cpp"

void PilaMoneda();
void TituloWC();
void PedirDatos();
void GenerarTurno();
void Juego();
void Informacion();

//Global
int pila=0, moneda, minimo, maximo,  extraccion=0, turno=0, turnoIni;
bool comienza;

warcoin(){
	system("mode 120, 35");
	int verificar;
	bool op=true;
	while(op==true){
		PilaMoneda();
		TituloWC();
		PedirDatos();
		GenerarTurno();
		Juego();
		textcolor(YELLOW);
		gotoxy(5, 15); printf("\n%c Quieres volver a jugar? (Para SI ingrese '1', para NO ingrese '2'): ", 175);
		scanf("%d", &verificar);
		printf("\n");
				if(verificar==2){
					op=false;
					system("cls");
					main();
				}
				else{
					system("cls");
				}
	}
	system("cls");
}

void PilaMoneda(){
	srand(time(NULL));
	pila=10+rand()%(50+1-1);
	
}

void TituloWC(){
	textcolor(LIGHTMAGENTA);
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
	gotoxy(32, 8); printf("%cIngresar el valor minimo de monedas a sacar por turno: ", 175);
	scanf("%d", &minimo);
	gotoxy(32, 9); printf("%cIngresar el valor maximo de monedas a sacar por turno: ", 175);
	scanf("%d", &maximo);
	gotoxy(5,12); printf("\t-------------------------------------------------------------------------------------------------------\n");
}

void Juego(){
	int contador=0, terminar=1, pilaOrg=pila, rltPila=5;
		while(terminar!=0){
			if(turno==2){
				textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
				textcolor(3); printf("\n\t\t\t%cTurno de la computadora%c\n", 175, 174);
				extraccion= minimo + rand()%(maximo + 1 - minimo);
				Sleep(2000);
				textcolor(WHITE); printf("\n\t\t\tLa computadora saco %d monedas\n", extraccion);
				pila-=extraccion;
					if(pila<minimo){
						Sleep(2000);
						textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
						terminar=0;
					}else{
						turno--;
					}
			}
				if(turno==1){
					textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
					textcolor(YELLOW); printf("\n\n\t\t\t%cTurno del usuario%c\n", 175, 174);
					textcolor(WHITE); printf("\n\t\t\tElija la cantidad de monedas a sacar: ");
					scanf("%d", &moneda);
						if(moneda<=maximo and moneda>=minimo){
							pila-=moneda;
						}else{
							printf("\n\n\t\t\tPor favor ingresar un valor que se encuentre entre %d y %d\n ", minimo, maximo);
							
							printf("\n\t\t\tElija la cantidad de monedas a sacar: ");
							scanf("%d", &moneda);
							pila-=moneda;
						}
					textcolor(GREEN);
						if(pila<minimo){
							Sleep(2000);
							textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
							terminar=0;
						}else{
							turno++;	
						}
				}
			contador++;
				if(contador==1){
					Sleep(500);
					system("cls");
					contador=0;
					TituloWC();
					Informacion();
				}
		}
		system("cls");
		TituloWC;
	if(turno==1){
		textcolor(GREEN);
			for(int i=46; i<85; i++){
				gotoxy(i, 7); printf("%c", 205);
				gotoxy(i, 13); printf("%c", 205);
			}
				for(int i=7; i<14; i++){
					gotoxy(46, i); printf("%c", 186);
					gotoxy(84, i); printf("%c", 186);
				}
		gotoxy(46, 7); printf("%c", 201);
		gotoxy(46, 13); printf("%c", 200);
		gotoxy(84, 7); printf("%c", 187);
		gotoxy(84, 13); printf("%c", 188);
		gotoxy(50, 10); printf("GANASTE!!! Puntaje obtenido: 5");
	}else{
		textcolor(LIGHTRED);
			for(int i=37; i<85; i++){
				gotoxy(i, 7); printf("%c", 205);
				gotoxy(i, 13); printf("%c", 205);
			}
				for(int i=7; i<14; i++){
					gotoxy(37, i); printf("%c", 186);
					gotoxy(84, i); printf("%c", 186);
				}	
		gotoxy(37, 7); printf("%c", 201);
		gotoxy(37, 13); printf("%c", 200);
		gotoxy(84, 7); printf("%c", 187);
		gotoxy(84, 13); printf("%c", 188);
		gotoxy(40, 10); printf("LA COMPUTADORA GANO!!! Puntaje obtenido: 0");
	}
}


void GenerarTurno(){
	turno= 1 + rand()%(2+1 - 1);
	turnoIni=turno;
	gotoxy(45, 12);
		if(turno==1){
			textcolor(YELLOW); printf("| Inicia la partida el usuario |");
		}else{
			
			textcolor(CYAN); printf("| Inicia la partida la computadora |");
		}
	gotoxy(0,13);
}

void Informacion(){
	textcolor(WHITE); 
	gotoxy(32, 8); printf("%cLa cantidad minima permitida para sacar monedas es: %d", 175, minimo);
	gotoxy(32, 9); printf("%cLa cantidad maxima permitida para sacar monedas es: %d", 175, maximo);
	gotoxy(5,12); printf("\t-------------------------------------------------------------------------------------------------------\n");
}
