#include "Owntools.h"

//DECLARACION DE FUNCIONES
void generarNum(int container[], int &Num);
void Inicio();
void verificarPosicion(int container[]);
void Resultado();

//Variables globales
int Numero, y, Punt=10;
int mismaP, diferenteP, container[4];
char Jugar;

main(){	
	system("mode 120, 35");
	bool Opcion=true;
		while(Opcion==true){
			generarNum(container, y);
			Inicio();
			printf("\n\n%c Quieres volver a jugar?(s/n): ", 175);
			scanf("%s", &Jugar);
			Jugar=toupper(Jugar);
				if(Jugar=='N'){
					Opcion=false;
					printf("\nSaliendo del juego......\n");
					printf("\nAdios....\n");
				}else{
					Punt=10;
					system("cls");
				}
		}
}

// CUERPO DEL JUEGO

void Inicio(){
	int x=25, ejey=9, contador=0;
	for(int i=0; i<10; i++){
		TituloAV();
		InstruccionesAV();
		textcolor(LIGHTRED);
		gotoxy(x, ejey); printf("%c INTENTO %d\n", 175, i+1);
		textcolor(WHITE);
		printf("\n\t\tIngrese el numero: ");
		scanf("%d", &Numero);
			if(Numero>=1000 && Numero<=9999){
				verificarPosicion(container);
				if(Numero==y){
					i=10;
				}
				else{
					textcolor(3);
					printf("\n\t\t° Cant. Misma Posicion: %d  ° Cant. Otra Posicion: %d\n", mismaP, diferenteP);
					Punt--;
				}
			}
			else{
				textcolor(3);
				printf("\n\t\tEl numero debe tener 4 cifras. Vuelva a intentarlo.\n");
				i--;
			}
		ejey=ejey+8;
					if(contador==1){
						printf("\n\n");
						system("pause");
						system("cls");
						contador=0;
						ejey=9;
					}else{
						contador++;
					}
	}
	system("cls");
	Resultado();
}

// GENERADOR DE NUMERO SECRETO (GENERA NUMEROS UNO POR UNO EN UN ARRAY PARA PODER VERIFICAR LA POSICION 
// Y LOS CONCATENA EN OTRA VARIBLE PARA PODER MOSTRARLO AL FINAL)

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

// VERIFICACION DE POSICIONES DE LOS NUMEROS EN LA CIFRA INGRESADA

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

// VISUALIZADOR DE RESULTADOS FINALES

void Resultado(){
	int Ganador=1, Perdedor=0;
	TituloAV();
	if(Punt>=1){
		MarcoResultadoAV(Ganador);
		textcolor(GREEN);
		gotoxy(53,11); printf("%cFELICITACIONES!", 173);
		gotoxy(47,13); printf("Acertaste! Puntaje obtenido: %d\n\n\n\n", Punt);
		textcolor(WHITE);
		printf("\n\n");
		system("pause");
	}
	else{
		MarcoResultadoAV(Perdedor);
		textcolor(LIGHTRED);			
		gotoxy(57,11); printf("Perdiste!");
		gotoxy(52,13); printf("Puntaje obtenido: %d", Punt);
		gotoxy(47,15); printf("El numero a adivinar era el %d\n\n\n\n", y);
		textcolor(WHITE);
		printf("\n\n");
		system("pause");
	}
}
