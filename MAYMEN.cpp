#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ahorcado.cpp"


int NumeroGenerado();
void Inicio(int N, int Y, int Puntaje);
void rango(int &mayor, int &menor, int NumOrig, int Num_Ingresado);
void titleMM();
void barracarga();;


main(){
	int n, Punt=10, y;
		y= NumeroGenerado();
		Inicio(n, y, Punt);
}

int NumeroGenerado(){
	srand(time(NULL)); 
	return 1 + rand()%(999+1 - 1);
}
void Inicio(int N, int Y, int Puntaje ){
	
	int numMay=999, numMen=1;
	titleMM();
	for (int X=1; X<=10; X++){
			printf("\n\n\t\t\t============================== Intento %d/10 ============================== \n\n\n\t\t\t",X);
			printf("EL numero se encuentra entre %d y %d\n\t\t\t", numMen, numMay);
			printf("Ingrese el numero: ");
			scanf("%d", &N);

			if(N>=1 && N<=999){
				rango(numMay, numMen, Y, N);
				if (N==Y){
					X=10;
				}
					if (N>Y){
						printf("\t\t\tEl numero secreto es menor y se encuentra entre %d y %d\n\n\n\t\t\t", numMen, numMay);
						Puntaje--;
						crearLineas('=', 71);
					}
					if (N<Y){
						printf("\t\t\tEl numero secreto es mayor y se encuentra entre %d y %d\n\n\n\t\t\t", numMen, numMay);
						Puntaje--;
						crearLineas('=', 71);
					}
			}
			else{
				printf("\t\t\tTiene que ingresar un numero entre 1 y 999, intente nuevamente\n\n\n\t\t\t");
				X--;
				crearLineas('=', 71);
			}
			if(X<10){
				barracarga();
			}
			system("cls");
			titleMM();
		}
		
	if(Puntaje>=1){
		textcolor(GREEN);
		for(int i=43; i<80; i++){
			gotoxy(i, 9); printf("%c", 205); //63 28
			gotoxy(i, 15); printf("%c", 205);
		}
		
			for(int i=9; i<16; i++){
				gotoxy(43, i); printf("%c", 186);
				gotoxy(79, i); printf("%c", 186);
			}
		
			gotoxy(43, 9); printf("%c", 201);
			gotoxy(43, 15); printf("%c", 200);
			gotoxy(79, 9); printf("%c", 187);
			gotoxy(79, 15); printf("%c", 188);
			gotoxy(46, 12); printf("Acertaste! Puntaje obtenido: %d", Puntaje);
			textcolor(WHITE);
			printf("\n\n\n\n\n\n\n");
	}else{
		textcolor(LIGHTRED);
		for(int i=45; i<79; i++){
			gotoxy(i, 9); printf("%c", 205); //63 28
			gotoxy(i, 16); printf("%c", 205);
		}
		
			for(int i=9; i<17; i++){
				gotoxy(45, i); printf("%c", 186);
				gotoxy(78, i); printf("%c", 186);
			}
		
			gotoxy(45, 9); printf("%c", 201);
			gotoxy(45, 16); printf("%c", 200);
			gotoxy(78, 9); printf("%c", 187);
			gotoxy(78, 16); printf("%c", 188);
		
			gotoxy(48, 12); printf("Perdiste! Puntaje Obtenido %d", Puntaje);
			gotoxy(48, 13); printf("El nuemero a adivinar era: %d", Y);
			textcolor(WHITE);
			printf("\n\n\n\n\n\n\n");
	}
}

void rango(int &mayor, int &menor, int NumOrig, int Num_Ingresado){
	if(Num_Ingresado<NumOrig and Num_Ingresado>menor){
		menor=Num_Ingresado;
	}
	if(Num_Ingresado>NumOrig and Num_Ingresado<mayor){
		mayor=Num_Ingresado;
	}
	
}

void barracarga(){
	textcolor(YELLOW);
	gotoxy(25, 18);
	
	for(int i=0; i<4;i++){
		Sleep(400);
		crearLineas(219, 13);
		cout<<"      ";
	}
	textcolor(WHITE);
	cout<<"\n";
}

void titleMM(){
	textcolor(YELLOW);
	gotoxy(11, 5);crearLineas(205, 42);cout<<">";
	gotoxy(72, 5);cout<<"<";crearLineas(205, 42);
	textcolor(LIGHTGREEN );
			gotoxy(60, 5);printf("MAYMEN");
		for(int i=54; i<71; i++){
			gotoxy(i, 4); printf("%c", 205);
			gotoxy(i, 6); printf("%c", 205);
		}
			for(int i=4; i<7; i++){
			gotoxy(54, i); printf("%c", 186);
			gotoxy(71, i); printf("%c", 186);
		}
		
		gotoxy(54, 4); printf("%c", 201);
		gotoxy(54, 6); printf("%c", 200);
		gotoxy(71, 4); printf("%c", 187);
		gotoxy(71, 6); printf("%c", 188);
		textcolor(WHITE);
}
