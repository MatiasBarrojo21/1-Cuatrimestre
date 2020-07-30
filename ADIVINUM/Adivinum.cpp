#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Semilla();
int AnalizaryMostrar(int Numero, int NumGenerado, int Puntaje);

main(){	
	int n, P, Punt=10, y;
	
	y=Semilla();
	printf("\n %d", y);
	printf("\nADIVINUM");
	printf("\n======");
	AnalizaryMostrar(n, y, Punt);
}

int Semilla(){
	int Num_Generado;
	srand(time(NULL));
	return Num_Generado= 1000 + rand()%(9999+1-1000);
}

int AnalizaryMostrar(int Numero, int NumGenerado, int Puntaje){
	for(int i=0; i<10; i++){
		printf("\nIntento %d: ", i+1);
		scanf("%d", &Numero);
			if(Numero>=1000 && Numero<=9999){
				if(Numero==NumGenerado){
					i=10;
				}
					if(Numero<NumGenerado){
						printf("\nCant. Misma Posicion: 0 -Cant. Otra Posicion: 0");
						Puntaje--;
					}
						if(Numero>NumGenerado){
							printf("\nCant. Misma Posicion: 0 -Cant. Otra Posicion: 0");
							Puntaje--;
						}
			}else{
				printf("\nEl numero debe tener 4 cifras. Vuelva a intentarlo.\n");
				i--;
			}
	}
		if (Puntaje>=1){
			printf("\nAcertaste! Puntaje obtenido: %d", Puntaje);
		}else{
			printf("\nPuntaje obtenido: %d", Puntaje);
			printf("\nEl numero a adivinar era el %d", NumGenerado);
		}	
}
