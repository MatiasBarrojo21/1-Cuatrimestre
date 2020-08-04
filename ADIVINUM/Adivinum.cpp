#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <iostream>

int AnalizaryMostrar(int Puntaje);
void generarNum(int container[4], int &Num);
void verificarPosicion(int container[]);

int Numero, y;
int mismaP, diferenteP, container[4];


main(){	
	int P, Punt=10;
	
	
	generarNum(container, y);
	
	printf("\n %d", y);
	printf("\n\t\tADIVINUM");
	printf("\n\t=========================");
	AnalizaryMostrar(Punt);
}

int AnalizaryMostrar(int Puntaje){
	for(int i=0; i<10; i++){
		printf("\n\tIntento %d: ", i+1);
		scanf("%d", &Numero);
			if(Numero>=1000 && Numero<=9999){
				verificarPosicion(container);
				if(Numero==y){
					i=10;
				}
				else{
					printf("\t°Cant. Misma Posicion: %d ° Cant. Otra Posicion: %d", mismaP, diferenteP);
					Puntaje--;
				}
			}
			else{
				printf("\n\tEl numero debe tener 4 cifras. Vuelva a intentarlo.\n");
				i--;
			}
			printf("\n\t=========================");
			
	}
		if (Puntaje>=1){
			printf("\t\nAcertaste! Puntaje obtenido: %d", Puntaje);
		}else{
			printf("\n\tPuntaje obtenido: %d", Puntaje);
			printf("\n\tEl numero a adivinar era el %d", y);
		}	
}

void generarNum(int container[4], int &Num){
	int Num_Generado=0, t=0, k=1;
	bool verif;
	
	srand(time(NULL));
	
	for(int c=0; c<4; c++){
		container[c]=10;
	}
	
	for(int i=0; i<4; i++){
		t=i;
		verif=true;
		Num_Generado=1+rand()%(9-1);
		
		if(Num_Generado>0){
			for(int j=0; j<t+1; j++){
				if(Num_Generado==container[j]){
					verif=false;
					t--;
					i--;
				}
			}
			if(verif==true){
				container[i]=Num_Generado;
			}
		}	
	}
	Num_Generado=0;
	t=0;
	while(k<1001){
		Num_Generado=Num_Generado+(container[t]*k);
		k=k*10;
		t++;
	}
	Num=Num_Generado;
	
	

}

void verificarPosicion(int container[]){
	int x[4], k=1000, t=3, aux=Numero;
	
	mismaP=0;
	diferenteP=0;
	
	while(k>0){
		x[t]=aux/k;
		aux=aux-(x[t]*k);
		k=k/10;
		t--;
	}
	
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(x[j]==container[i] and i==j){
				mismaP++;
			}
			if(x[j]==container[i]  and i!=j){
				diferenteP++;
			}
			
		
		}	
	}
	
	
}









