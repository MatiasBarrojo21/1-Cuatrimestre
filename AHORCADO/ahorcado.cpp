#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include "tools_hanged.h"

using namespace std;

void uploadWord(char word[],char player);
void start();
void readjustWord();
void title();
void game(int &puntaje, char jugador, int num, char palabra[]);
bool verificar(char letra, int n, char aux[], char palabra[]);
void blanquear(char aux[], int num);

//	--------

char word1[20], word2[20];
int cantLetrasP[1], puntaje[1];
string cuerpo[10];

		



main(){
	bool jugarN=true;

	
	while(jugarN==true){
		start();
		
		printf("\n\n\t¿Quieren volver a jugar? (S/N)");
	}
	
	


}



	//pantalla de inicio
void start(){
	title();
	uploadWord(word1, 'A');
	title();
	uploadWord(word2, 'B');
	
	readjustWord();
	system("cls");
	game(puntaje[0], 'A' , cantLetrasP[0], word1);
}

	//Carga de palabras
void uploadWord(char word[],char player){
	
	printf("\tIngresa la palabra el jugador %c para el oponente: ", player);
	scanf("%s", &word);
	system("cls");
	
}

	//Reacondicionamiento de palabras
void readjustWord(){
	
	cantLetrasP[0]=cantLetras(word1);
	cantLetrasP[1]=cantLetras(word2);
	strupr(word1);
	strupr(word2);
	
	
}


void game(int &puntaje, char jugador, int num, char palabra[]){
	char letraInput;
	int contJugadas=0, contCuerpo=0, i=0;
	bool valorResp;
		cuerpo[1]="No hay partes plasmadas";
		cuerpo[1]="Cabeza";
		cuerpo[2]="Tronco";
		cuerpo[3]="Brazo izquierdo";
		cuerpo[4]="Brazo derecho";
		cuerpo[5]="Pierna izquierda";
		cuerpo[6]="pierna derecha";
		cuerpo[7]="mano izquierda";
		cuerpo[8]="mano derecha";
		cuerpo[9]="pie izquierdo";
		cuerpo[10]="pie derecho";
	char aux[20]=palabra[20];
	blanquear(aux, num);
	title();
	
	printf("\n\t\t\t\t----> INICIO <----");
	printf("\n\tTURNO DEL JUGADOR %c\n", jugador);
	while( i<10 ){
		
		printf("\n\tPalabra que debe adivinar: - - - - ");
		scanf("%c", &letraInput);
		valorResp = valoverificar(letraInput, num, aux, palabra);
		if(valorResp==false){
			contCuerpo++;
		}
		cout<<"Estado del muñeco: " << cuerpo[contCuerpo]<<endl;
		
	}
}

void title(){
	printf("\n\n\t\t==============================<|  AHORCADO  |>==============================\n\n\n");
}

bool verificar(char letra, int n, char aux[], char palabra[]){
	bool valor=false;
	for(int i=0; i< num; i++){
		if(letra==palabra[i]){
			aux[i]=letra;
			valor=true;
		}
	}
	return valor;
}

void blanquear(char aux[], int num){
	for(int i=0; i<num ; i++){
		aux[i]="-";
	}
}


