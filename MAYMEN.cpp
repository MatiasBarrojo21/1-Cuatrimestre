#include "Owntools.h"

//Fucniones
int NumeroGenerado();
void Inicio(int N, int Y, int Puntaje);
void rango(int &mayor, int &menor, int NumOrig, int Num_Ingresado);

main(){
	system("mode 120, 35");
	int n, Punt=10, y;
	bool op=true;
	int verificar;
	while(op==true){
		y= NumeroGenerado();
		Inicio(n, y, Punt);
		gotoxy(5, 18); printf("\n%c Quieres volver a jugar? (Para SI ingrese '1', para NO ingrese '2'): ", 175);
		scanf("%d", &verificar);
				if(verificar==2){
					op=false;
					printf("\nSaliendo del juego......\n");
					printf("\nAdios....\n");
				}
				else{
					system("cls");
				}
	}
}

int NumeroGenerado(){
	srand(time(NULL)); 
	return 1 + rand()%(999+1 - 1);
}

void Inicio(int N, int Y, int Puntaje ){
	int numMay=999, numMen=1;
	int ejeY=15, Contador=1;
	textcolor(WHITE);
	gotoxy(27, 10); printf("===========================================================================");
	textcolor(DARKGRAY);
	gotoxy(34, 12); printf("%cTiene que adivinar un numero de 3 cifras que esta entre 1 y 999%c", 175, 174);
		for (int X=1; X<=10; X++){
			TituloMYM();
			textcolor(LIGHTRED);
			gotoxy(57, ejeY); printf("INTENTO %d/10\n", X);
			textcolor(WHITE);
			printf("\n\t\t\t%cIngrese el numero: ", 175);
			scanf("%d", &N);
				if(N>=1 && N<=999){
					rango(numMay, numMen, Y, N);
					textcolor(LIGHTMAGENTA);
						if (N==Y){
							X=10;
							system("cls");
						}
							if (N>Y){
								printf("\n\t\t\t\tEl numero secreto es menor y se encuentra entre %d y %d\n", numMen, numMay);
								Puntaje--;
							}
								if (N<Y){
									printf("\n\t\t\t\tEl numero secreto es mayor y se encuentra entre %d y %d\n", numMen, numMay);
									Puntaje--;	
								}
				}
				else{
					printf("\n\t\t\t\tTiene que ingresar un numero entre 1 y 999, intente nuevamente\n");
					X--;
				}
			ejeY=ejeY+6;
			Contador++;
					if(Contador==4){
						textcolor(WHITE);
						printf("\n");
						system("pause");
						system("cls");
						gotoxy(27, 10); printf("===========================================================================");
						textcolor(DARKGRAY);
						gotoxy(43, 12); printf("%cEl numero se encuentra entre %d y %d%c", 175, numMen, numMay, 174);
						ejeY=15;
						Contador=1;
					}
		}
	system("cls");
	MarcoResultadoMYM(Puntaje, Y);
}

void rango(int &mayor, int &menor, int NumOrig, int Num_Ingresado){
	if(Num_Ingresado<NumOrig and Num_Ingresado>menor){
		menor=Num_Ingresado;
	}
		if(Num_Ingresado>NumOrig and Num_Ingresado<mayor){
			mayor=Num_Ingresado;
		}
}
