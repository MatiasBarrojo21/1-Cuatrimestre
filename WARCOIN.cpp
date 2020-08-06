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
void juego();
int turno();
void usuario();
void computadora();
void GraficMonedas();
//Global
int pila=0, moneda, minimo, maximo,  extraccion=0;
bool comienza;

main(){
	int verificar;
	bool op=true;
	while(op==true){
		PilaMoneda();
		Titulo();
		juego();
		gotoxy(5, 15); printf("\nQuieres volver a jugar? (Para SI ingrese '1', para NO ingrese '2'): ");
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
	pila=rand()%(51-1);
	if(pila<10){
		pila+=10;
	}
}
void Titulo(){
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

void juego(){
	int verificar;
	textcolor(WHITE);
	gotoxy(35, 8); printf("%cIngresar el valor minimo de monedas a sacar por turno: ", 175);
	scanf("%d", &minimo);
	gotoxy(35, 10); printf("%cIngresar el valor maximo de monedas a sacar por turno: ", 175);
	scanf("%d", &maximo);
	gotoxy(5,11); printf("----------------------------------------------------------------------------------------------------------------\n");
	verificar=turno();
		if(verificar==1){
			textcolor(LIGHTRED);
			printf("\n\t\tInicia la partida el usuario.\n");
		}
		else{
			textcolor(LIGHTRED);
			printf("\n\tInicia la partida la computadora.\n");
		}
			while(pila>0 and pila>minimo){
				if(verificar==2){
					computadora();
					textcolor(GREEN);
					printf("\n\t\tQuedan %d monedas\n",pila);
					verificar--;
				}
					if(verificar==1){
						usuario();
						textcolor(GREEN);
						printf("\n\t\tQuedan %d monedas\n",pila);
						verificar++;
					}
			}
	Sleep(500);
	system("cls");
	
	if(verificar==1 and pila==0){
		textcolor(LIGHTRED);
		for(int i=39; i<47; i++){
			gotoxy(i, 5); printf("%c", 205);
			gotoxy(i, 11); printf("%c", 205);
		}
		for(int i=5; i<12; i++){
			gotoxy(39, i); printf("%c", 205);
			gotoxy(46, i); printf("%c", 205);
		}
		gotoxy(55, 8); printf("LA COMPUTADORA GANO!!! Puntaje obtenido: 0");
	}
		if(verificar==2 and pila==0){
			textcolor(GREEN);
				for(int i=53; i<80; i++){
					gotoxy(i, 5); printf("%c", 205);
					gotoxy(i, 11); printf("%c", 205);
				}
					for(int i=5; i<12; i++){
						gotoxy(53, i); printf("%c", 205);
						gotoxy(79, i); printf("%c", 205);
					}
					
					gotoxy(55, 8); printf("GANASTE!!! Puntaje obtenido: 5");
		}
			if(pila!=0){
				textcolor(LIGHTRED);
					for(int i=52; i<72; i++){
						gotoxy(i, 5); printf("%c", 205);
						gotoxy(i, 11); printf("%c", 205);
					}
						for(int i=5; i<12; i++){
							gotoxy(52, i); printf("%c", 186);
							gotoxy(71, i); printf("%c", 186);
						}
						gotoxy(52, 5); printf("%c", 201);
						gotoxy(52, 11); printf("%c", 200);
						gotoxy(71, 5); printf("%c", 187);
						gotoxy(71, 11); printf("%c", 188);
						gotoxy(55, 8); printf("NO HAY GANADOR");
			}
}

int turno(){
	return 1 + rand()%(2+1 - 1);	
}

void usuario(){
	textcolor(YELLOW);
	printf("\n\t%cTurno del usuario%c\n", 175, 174);
	textcolor(WHITE);
	printf("\n\tElija la cantidad de monedas a sacar: ");
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
	textcolor(3);
	printf("\n\t%cTurno de la computadora%c\n", 175, 174);
	textcolor(WHITE);
	extraccion= minimo + rand()%(maximo + 1 - minimo);
	printf("\n\tLa computadora saco %d monedas\n", extraccion);
	pila-=extraccion;
}
