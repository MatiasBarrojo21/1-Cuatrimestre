#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "conio.c"
#include <string.h>
#include <windows.h>

using namespace std;

void uploadWord(char word[],char player, int &letras);
void start();
void title();
void game(int &puntaje, char jugador, int num, char palabra[]);
bool verificar(char letra, int n, char aux[], char palabra[], int &aciertos);
void rellenar(char aux[], int num);
void vaciar(char palabra[]);
void crearLineas(char simbolo, int cantidad);
void cuerpo(int numParte);
bool agrLetra(char listLetras[], char letra, int intentos, int &cantIntegradas);
void mostrarLetras(char letras[], int cantIntegradas);
void mostrarPalabra(char palabra[]);
void grafPersona(int numParte);

//	--------

int cantLetrasP[1], puntaje[1];

ahorcado(){
	bool Opcion=true;
	char Jugar;
	while(Opcion==true){
		start();
		printf("\n\n\tQuieres volver a jugar?(s/n): ");
		scanf("%s", &Jugar);
		Jugar=toupper(Jugar);
		if(Jugar=='N'){
			Opcion=false;
		}else{
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
	textcolor(YELLOW);
	if(puntaje[0]>puntaje[1]){
		printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\tEl ganador es el JUGADOR A.\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	if(puntaje[0]<puntaje[1]){
		printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\tEl ganador es el JUGADOR B.\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	if(puntaje[0]==puntaje[1]){
		printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\t\t\tFUE EMPATE.\t\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}

	textcolor(WHITE);
}
//	limpia la variable
void vaciar(char palabra[]){
	for(int i=0; i<22; i++){
		palabra[i]=' ';
	}
}
//	Carga de palabra
void uploadWord(char word[],char player, int &letras){
	letras=0;
	vaciar(word);
	printf("\tIngresa la palabra el jugador %c para el oponente, letra por letra (despues de cada letra presione ENTER).\n\t(Ingresar '0' para terminar de agregar letras) \n", player);
	printf("\t%c%c%c Palabras recomendadas: \n\n", 205, 205,185);
	textcolor(YELLOW);
	textbackground(RED);
	printf("\t\t\t1. Compilador\t2. Entorno\t3. Computadora\t4. Estructura\t\n\t\t\t5. Seleccion\t6. Repeticion\t7. Directiva\t8. Algoritmo\t\n\t\t\t9. Program\t10.Ejecucion\t11.Int\t\t12.Float\t\n\t\t\t13.Char\t\t14.Double\t15.Long\t\t16.If\t\t\n\t\t\t17.Else\t\t18.For\t\t19.While\t20.Return\t\n\t\t\t21.Break\t22.Switch\t23.Case\t\t24.Main\t\t\n\t\t\t25.Include\t26.Define\t27.Struct\t28.Cin\t\t\n");
	textcolor(WHITE);
	textbackground(BLACK);
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
	int cantLetras=0;
	char letras[contJugadas];

	rellenar(aux, num);

	while( i<11 and aciertos!=num){
		title();
		printf("\n\t\t\t----> INICIO <----");
		printf("\n\t\t\tTURNO DEL JUGADOR %c\n", jugador);
		strupr(aux);
		printf("\n\n\t°°°°°°°°°°°°°°JUGADA #%d°°°°°°°°°°°°°°\t\n", contJugadas);
		cout<<"\n\tLetras ya ingresadas: ";textcolor(YELLOW);
		mostrarLetras(letras, cantLetras);
		textcolor(WHITE);
		cout<<"\n\tPalabra que debe adivinar:" << aux <<endl;
		cout<<"\tEstado del muñeco: ";
		cuerpo(contCuerpo);
		printf("\n\tIngrese una letra: ");
		textbackground(BLUE);
		scanf("%s", &letraInput);
		textbackground(BLACK);
		if(isalpha(letraInput)){
			if(agrLetra(letras, letraInput, contJugadas, cantLetras)==true){
				valorResp = verificar(letraInput, num, aux, palabra, aciertos);
				if(valorResp==false){
					contCuerpo++;
					i++;
				}
			}
			else{
				printf("\n\tLa letra ya fue ingresada. Vuelva a intentar.");
				system("pause");
			}
			cout<<"\n\t";
			crearLineas('=', 40);
		}
		else{
			printf("\n\tEl valor ingresado no es una letra. Vuelva a ingresar.");
			cout<<"\n\t";
			crearLineas('=', 40);
			system("pause");
		}
		contJugadas++;
		system("cls");
	}
	if(i==11){
		puntaje=0;
		textcolor(LIGHTRED);
		printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tPerdiste, tienes 0 puntos. La palabra era: ");
		for(int l=0; l<num; l++){
			cout<<palabra[l];
		}
		printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n");
		textcolor(WHITE);
	}
	else{
		puntaje=50-(2*contCuerpo);
		textcolor(LIGHTGREEN);
		printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\tObtuviste %d puntos.\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n", puntaje);
		textcolor(WHITE);
	}
	system("pause");
	system("cls");
}

void title(){
	textcolor(LIGHTRED);
	printf("\n\n\t\t\t==============================<|  AHORCADO  |>==============================\n\n\n");
	textcolor(WHITE);
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
// 	Cuerpo del ahorcado
void cuerpo(int numParte){
	string partesCuerpo[12];
	partesCuerpo[0]="No hay partes plasmadas ";
	partesCuerpo[1]=" Cabeza ";
	partesCuerpo[2]="- Tronco ";
	partesCuerpo[3]="- Brazo izquierdo ";
	partesCuerpo[4]="- Brazo derecho ";
	partesCuerpo[5]="- Pierna izquierda ";
	partesCuerpo[6]="- Pierna derecha ";
	partesCuerpo[7]="- Mano izquierda ";
	partesCuerpo[8]="- Mano derecha ";
	partesCuerpo[9]="- Pie izquierdo ";
	partesCuerpo[10]="- Pie derecho. ";

	if(numParte==0){
		cout<<partesCuerpo[0];
	}
	else{
		if(numParte==10){
			textcolor(LIGHTRED);
			Beep(250, 100);
			Beep(400, 100);
		}
		for(int i=1; i<numParte+1; i++){
			if(i==4){
				cout<<"\n\t";
			}
			if(i==7){
				cout<<"\n\t";
			}
		cout<<partesCuerpo[i];
		}
	}
	grafPersona(numParte);
	textcolor(WHITE);
}
// parte del cuerpo
void grafPersona(int numParte){
	
	for(int i=0; i<numParte+1; i++){
		if(i==0){
			for(int a=3; a<8; a++){
				textcolor(YELLOW);
				gotoxy(95, a); printf("%c", 178); 
			}
		}
		if(i==1){
			for(int b=90; b<101 ;b++){
				textcolor(WHITE);
				gotoxy(b, 8);printf("%c", 219);
				gotoxy(b, 9);printf("%c", 219);
				gotoxy(b, 10);printf("%c", 219);
				gotoxy(b, 11);printf("%c", 219);
			}
		}
		if(i==2){
			textcolor(YELLOW);
			gotoxy(93, 12);crearLineas(178, 5);
			for(int c=13; c<21 ;c++){
				textcolor(RED);
				gotoxy(93, c);printf("%c", 219);
				gotoxy(94, c);printf("%c", 219);
				gotoxy(95, c);printf("%c", 219);
				gotoxy(96, c);printf("%c", 219);
				gotoxy(97, c);printf("%c", 219);
			}
		}
		if(i==3){
			for(int d=13; d<19 ;d++){
				gotoxy(91, d);printf("%c%c", 254,254);

			}
		}
		if(i==4){
			for(int d=13; d<19 ;d++){
				gotoxy(98, d);printf("%c%c", 254,254);

			}
		}
		if(i==5){
			textcolor(BLUE);
			for(int d=21; d<26 ;d++){
				gotoxy(93, d);printf("%c", 219);
				gotoxy(94, d);printf("%c", 219);
			}
		}
		if(i==6){
			for(int d=21; d<26 ;d++){
				gotoxy(96, d);printf("%c", 219);
				gotoxy(97, d);printf("%c", 219);
			}
		}
		if(i==7){
			textcolor(WHITE);
				gotoxy(91, 19);printf("%c%c", 219,219);
		}
		if(i==8){
				gotoxy(98, 19);printf("%c%c", 219,219);
		}
		if(i==9){
			textcolor(DARKGRAY);
				gotoxy(93, 26);printf("%c%c", 219,219);
		}
		if(i==10){
				gotoxy(96, 26);printf("%c%c", 219,219);
		}
	}
	if(numParte<4){
		gotoxy(9, 15);
	}
	if(numParte>=4){
		gotoxy(9, 16);
	}
	if(numParte>=7){
		gotoxy(9, 17);
	}
}
// 	Verificar si la letra ya esta integrada
bool agrLetra(char listLetras[], char letra, int intentos, int &cantIntegradas){
	bool valor=true;
	letra=toupper(letra);

	for(int i=0; i<cantIntegradas ; i++){
		if(letra==listLetras[i]){
			valor=false;
		}
	}
	if(valor==false){
		return false;
	}
	else{
		cantIntegradas++;
		listLetras[intentos-1]=letra;
		return true;
	}
}
void mostrarLetras(char letras[], int cantIntegradas){
	for(int i=0; i<cantIntegradas; i++){
		cout<<letras[i];
		cout<<"-";
	}
}
