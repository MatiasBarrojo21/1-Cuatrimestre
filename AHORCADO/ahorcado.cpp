#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

void uploadWord(char word[],char player, int &letras);
void start();
void title();
void game(int &puntaje, char jugador, int num, char palabra[]);
bool verificar(char letra, int n, char aux[], char palabra[], int &aciertos);
void blanquear(char aux[], int num);
int cantLet(char palabra[]);
void vaciar(char palabra[]);
//	--------


int cantLetrasP[1], puntaje[1];

		



main(){
	bool jugarN=true;
	char op[0];
	
	while(jugarN==true){
		start();
		
		printf("\n\n\t¿Quieren volver a jugar? (S/N)\n\t----------->");
		scanf("%s", &op);
		op[0]=toupper(op[0]);
		if(op=="N"){
			jugarN=false;
			
		}
		else{
			system("cls");
		}
		
	}
	
	


}



	//pantalla de inicio
void start(){
	char word1[20], word2[20];
	vaciar(word1);
	vaciar(word2);
	
	title();
	uploadWord(word2, 'B', cantLetrasP[1]);
	game(puntaje[0], 'A' , cantLetrasP[1], word2);
	title();
	uploadWord(word1, 'A', cantLetrasP[0]);
	game(puntaje[1], 'B' , cantLetrasP[0], word1);
	title();
	if(puntaje[0]>puntaje[1]){
		printf("\n\tEl ganador es el JUGADOR A.");
	}
	if(puntaje[0]<puntaje[1]){
		printf("\n\tEl ganador es el JUGADOR B.");
	}
	if(puntaje[0]==puntaje[1]){
		printf("\n\tEs un empate.");
	}
}

void vaciar(char palabra[]){
	for(int i=0; i<21; i++){
		palabra[i]=' ';
	}
}

	//Carga de palabras
void uploadWord(char word[],char player, int &letras){
	letras=0;
	vaciar(word);
	printf("\tIngresa la palabra letra por letra el jugador %c para el oponente.\n\t(Ingresar '0' para terminar de determinar letras) \n", player);
	for(int i=0; i<20 ; i++){
		printf("\n\t%d° = ", i+1);
		scanf("%s", &word[i]);
		if(isalpha(word[i])){
			letras++;
		}
		else{
			if(isalnum(word[i])){
				i=20;
				word[i]=' ';
			}
			else{
				printf("\n\tSi desea terminar el valor debe ser '0'.");
			}
		}
		
	}
	strupr(word);
	system("cls");
}


void game(int &puntaje, char jugador, int num, char palabra[]){
	char letraInput;
	int contJugadas=1, contCuerpo=0, i=0;
	bool valorResp;
	bool partida=true;
	int aciertos=0;
		
	char aux[num];
	blanquear(aux, num);
	title();
	
	printf("\n\t\t\t\t----> INICIO <----");
	printf("\n\tTURNO DEL JUGADOR %c\n", jugador);
	cout<<"\n\tPalabra que debe adivinar:" << aux <<endl;
	while( i<11 and aciertos!=num){
		strupr(aux);
		printf("\n\tJUGADA #%d", contJugadas);
		printf("\n\tIngrese una letra: ");
		scanf("%s", &letraInput);
	
		if(isalpha(letraInput)){
			valorResp = verificar(letraInput, num, aux, palabra, aciertos);
			if(valorResp==false){
				contCuerpo++;
				i++;
			}
			cout<<"\n\tPalabra que debe adivinar:" << aux <<endl;
			cout<<"\n\tEstado del muñeco: " << contCuerpo <<endl;
			
		}
		else{
			printf("\n\tEl valor ingresado no es una letra. Vuelva a ingresar.");
		}
		contJugadas++;
	}
	if(i==11){
		puntaje=0;
		printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\tPerdiste, tienes 0 puntos.\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	else{
		puntaje=50-(2*contCuerpo);
		printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\tObtuviste %d puntos.\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	system("pause");
	system("cls");
	
}

void title(){
	printf("\n\n\t\t==============================<|  AHORCADO  |>==============================\n\n\n");
}

bool verificar(char letra, int n, char aux[], char palabra[], int &c){
	letra=toupper(letra);
	bool valor=false;
	for(int i=0; i<n; i++){
		if(letra==palabra[i]){
			aux[i]=letra;
			valor=true;
			c++;
		}
	}
	return valor;
}

void blanquear(char aux[], int num){
	vaciar(aux);
	for(int i=0; i<num ; i++){
		aux[i]= '-';
	}
	
}





