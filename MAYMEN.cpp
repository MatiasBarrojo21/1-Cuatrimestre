#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumeroGenerado(int Num);
void Inicio(int N, int Y, int Puntaje );

main(){
	int n, P, Punt=10, y;
		y= NumeroGenerado(P);
		printf("\n MAYMEN");
		printf("\n ======");
		Inicio(n, y, Punt);

}

int NumeroGenerado(int Num){
	srand(time(NULL));
	Num= 1 + rand()%(999+1 - 1);
}
void Inicio(int N, int Y, int Puntaje ){
	 for (int X=1; X<=10; X++){
			printf("\n Intento %d: ",X);
			scanf("%d", &N);

			if(N>=1 && N<=999){
				if (N==Y){
					X=10;
				}
					if (N>Y){
						if (Y-50<1){
							printf("\n El numero secreto es menor y se encuentra entre %d y 1\n", N-1);
				}else{
					printf("\n El n�mero secreto es menor y se encuentra entre %d y %d\n", N-1,Y-50);
				}

						Puntaje=Puntaje-1;
					}
						if (N<Y){
								if (Y+50>999){
						 			printf("\n El numero secreto es mayor y se encuentra entre %d y 999\n", N+1);
						}else{
							printf("\n El numero secreto es mayor y se encuentra entre %d y %d\n", N+1,Y+50);
						}

						Puntaje=Puntaje-1;
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
