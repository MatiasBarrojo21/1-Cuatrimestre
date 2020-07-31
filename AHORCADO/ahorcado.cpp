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
void rellenar(char aux[], int num);
void vaciar(char palabra[]);
void crearLineas(char simbolo, int cantidad);

//	--------

int cantLetrasP[1], puntaje[1];
	
	

main(){
	bool jugarN=true;
	char op;
	
	while(jugarN==true){
		start();
		
		printf("\n\n\t¿Quieren volver a jugar? (S/N)\n\t----------->");
		scanf("%s", &op);
		op=toupper(op);
		if(op=='N'){
			jugarN=false;
			printf("\n\n\n");
		}
		else{
			system("cls");
		}
		
	}
	
	


}

//	pantalla de inicio
	
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
		printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\tEl ganador es el JUGADOR A.\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	if(puntaje[0]<puntaje[1]){
		printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\tEl ganador es el JUGADOR B.\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	if(puntaje[0]==puntaje[1]){
		printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\t\tFUE EMPATE.\t\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
}

//	limpia la variable

void vaciar(char palabra[]){
	for(int i=0; i<21; i++){
		palabra[i]=' ';
	}
}

//	Carga de palabra
	
void uploadWord(char word[],char player, int &letras){
	letras=0;
	vaciar(word);
	printf("\tIngresa la palabra el jugador %c para el oponente, letra por letra (despues de cada letra presione ENTER).\n\t(Ingresar '0' para terminar de agregar letras) \n", player);
	printf("\t%c%cPalabras recomendadas: \n\n", 205, 205);
	printf("\t\t\t1. Compilador\t2. Entorno\t3. Computadora\t4. Estructura\n\t\t\t5. Seleccion\t6. Repeticion\t7. Directiva\t8. Algoritmo\n\t\t\t9. Program\t10.Ejecucion\t11.Int\t\t12.Float\n\t\t\t13.Char\t\t14.Double\t15.Long\t\t16.If\n\t\t\t17.Else\t\t18.For\t\t19.While\t20.Return\n\t\t\t21.Break\t22.Switch\t23.Case\t\t24.Main\n\t\t\t25.Include\t26.Define\t27.Struct\t28.Cin\n");
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

//	juego

void game(int &puntaje, char jugador, int num, char palabra[]){
	char letraInput;
	int contJugadas=1, contCuerpo=0, i=0;
	bool valorResp;
	bool partida=true;
	int aciertos=0;
	char aux[num];

	rellenar(aux, num);
	title();
	
	printf("\n\t\t\t----> INICIO <----");
	printf("\n\t\t\tTURNO DEL JUGADOR %c\n", jugador);
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
			cout<<"\n\tEstado del muñeco: " << contCuerpo<<endl;
			
		}
		else{
			printf("\n\tEl valor ingresado no es una letra. Vuelva a ingresar.");
		}
		contJugadas++;
	}
	if(i==11){
		puntaje=0;
		printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tPerdiste, tienes 0 puntos.\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	else{
		puntaje=50-(2*contCuerpo);
		printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\tObtuviste %d puntos.\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	system("pause");
	system("cls");
	
}

void title(){
	
	printf("\n\n\t\t\t==============================<|  AHORCADO  |>==============================\n\n\n");
}

//	verifica que la letra ingresada se encuentra

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

//	rellena de guiones la variable

void rellenar(char aux[], int num){
	vaciar(aux);
	for(int i=0; i<num ; i++){
		aux[i]= '-';
	}
	
}

void crearLineas(char simbolo, int cantidad){
	for(int i=0; i<cantidad; i++){
		cout<< simbolo;
	}
}



