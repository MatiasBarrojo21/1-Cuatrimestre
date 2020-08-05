#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <conio.c>
#include <iostream>

void generarNum(int container[4], int &Num);
void Titulo();
int Inicio(int Puntaje);
void verificarPosicion(int container[]);
void Resultado();

//Variables globales
int Numero, y, Punt=10;;
int mismaP, diferenteP, container[4];

main(){	
	generarNum(container, y);
	Titulo();
	printf("\n %d", y);
	Inicio(Punt);
}

void Titulo(){
	textcolor(YELLOW);
		for(int i=36; i<45; i++){
  			gotoxy(i, 3); printf("%c", 205);
    		gotoxy(i, 5); printf("%c", 205);
 		 }
  			for(int i=3; i<5; i++){
    			gotoxy(36, i); printf("%c", 186);
    			gotoxy(45, i); printf("%c", 186);
			}
	
	gotoxy(36, 3); printf("%c", 201);
	gotoxy(36, 5); printf("%c", 200);
	gotoxy(45, 3); printf("%c", 187);
	gotoxy(45, 5); printf("%c", 188);
	
	gotoxy(6, 4); printf("============================>");
	gotoxy(37, 4); printf("ADIVINUM");
	gotoxy(47,4); printf("<============================");
}

int Inicio(int Puntaje){
	for(int i=0; i<10; i++){
		textcolor(WHITE);
		printf("\n\n\t\t\tINTENTO %d\n", i+1);
		printf("\n\t\tIngrese el numero: ");
		scanf("%d", &Numero);
			if(Numero>=1000 && Numero<=9999){
				verificarPosicion(container);
				if(Numero==y){
					i=10;
				}
				else{
					printf("\n\t\t° Cant. Misma Posicion: %d  \n\n\t\t° Cant. Otra Posicion: %d\n\n", mismaP, diferenteP);
					Puntaje--;
				}
			}
			else{
				printf("\n\t\tEl numero debe tener 4 cifras. Vuelva a intentarlo.\n");
				i--;
			}
			
			/*if(i==1){
				system("cls");
			}
				if(i==3){
						system("cls");
					}*/
	}
	system("cls");
	Titulo();
		if (Puntaje>=1){
			textcolor(GREEN);
			for(int i=22; i<61; i++){
				gotoxy(i, 9); printf("%c", 205);
				gotoxy(i, 16); printf("%c", 205);
			}
			
				for(int i=9; i<16; i++){
					gotoxy(22, i); printf("%c", 186);
					gotoxy(60, i); printf("%c", 186);
				}
				
				gotoxy(22, 9); printf("%c", 201);
				gotoxy(22, 16); printf("%c", 200);
				gotoxy(60, 9); printf("%c", 187);
				gotoxy(60, 16); printf("%c", 188);
				
			gotoxy(33,11); printf("¡FELICITACIONES!");
			gotoxy(27,13); printf("Acertaste! Puntaje obtenido: %d\n\n\n\n", Puntaje);
			textcolor(WHITE);
		}
		else{
			textcolor(LIGHTRED);
			for(int i=22; i<61; i++){
				gotoxy(i, 9); printf("%c", 205);
				gotoxy(i, 17); printf("%c", 205);
			}
			
				for(int i=9; i<18; i++){
					gotoxy(22, i); printf("%c", 186);
					gotoxy(60, i); printf("%c", 186);
				}
				
				gotoxy(22, 9); printf("%c", 201);
				gotoxy(22, 17); printf("%c", 200);
				gotoxy(60, 9); printf("%c", 187);
				gotoxy(60, 17); printf("%c", 188);
				
			gotoxy(37,11); printf("Perdiste!");
			gotoxy(32,13); printf("Puntaje obtenido: %d", Puntaje);
			gotoxy(27,15); printf("El numero a adivinar era el %d\n\n\n\n", y);
			textcolor(WHITE);
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
