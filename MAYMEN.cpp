#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <conio.c>

int NumeroGenerado();
void Inicio(int N, int Y, int Puntaje);
void rango(int &mayor, int &menor, int NumOrig, int Num_Ingresado);


main(){
	int n, Punt=10, y;
		y= NumeroGenerado();
		printf("\n MAYMEN %d", 537);
		printf("\n ======");
		Inicio(n, 537, Punt);
}

int NumeroGenerado(){
	srand(time(NULL));
	return 1 + rand()%(999+1 - 1);
}
void Inicio(int N, int Y, int Puntaje ){
	
	int numMay=999, numMen=1;
	
	for (int X=1; X<=10; X++){
			printf("\n Intento %d: ",X);
			scanf("%d", &N);

			if(N>=1 && N<=999){
				rango(numMay, numMen, Y, N);
				if (N==Y){
					X=10;
				}
					if (N>Y){
						printf("\n El numero secreto es menor y se encuentra entre %d y %d\n", numMen, numMay);
						Puntaje--;
					}
					if (N<Y){
						printf("\n El numero secreto es mayor y se encuentra entre %d y %d\n", numMen, numMay);
						Puntaje--;
					}
			}
			else{
				printf("\nTiene que ingresar un numero entre 1 y 999, intente nuevamente\n");
				X--;

			}
		}
	if(Puntaje>=1){
		printf("\n Acertaste! Puntaje obtenido: %d", Puntaje);
	}else{
		printf("\n Perdiste! Puntaje Obtenido %d", Puntaje);
		printf("\n El nuemero a adivinar era %d", Y);
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
