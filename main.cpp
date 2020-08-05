#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include "ahorcado.cpp"
#include "Adivinum.cpp"
//#include "MAYMEN.cpp"

using namespace std;

void menu();
void categorias();
void Juegos();
void letras();
void numeros();

main(){
	menu();
}

void menu(){
	int op;
	printf("\n\n\t\t\t\t\t\tMENU\n");
	cout<<"\n\t";
	textcolor(LIGHTRED);
	crearLineas('=', 100);
	textcolor(WHITE);

	printf("\n\n\n\n\n\n\t\t\t\t1) Categorias.");
	printf("\n\t\t\t\t2) Todos los juegos.");
	printf("\n\t\t\t\t3) Exit.");

	textcolor(LIGHTRED);
	cout<<"\n\n\n\n\n\n\t";
	crearLineas('=', 100);
	textcolor(WHITE);
	cout<<"\n\n\n";

	printf("\n\t\t\tINGRESA LA OPCION: ");
	scanf("%d", &op);

	switch(op){
		case 1: Beep(250, 100);system("cls"); categorias();
		break;
		case 2: Beep(250, 100);system("cls"); Juegos();
		break;
		case 3: Beep(250, 100);system("exit");
		break;
		default: printf("\t\t\tOpcion no valida. Vuelva a ingresar\n\t\t\t"); system("pause"); system("cls"); menu();
	}
}

void categorias(){
	int op;
	printf("\n\n\n\n\n\n\t\t\t\tCATEGORIAS\n");
	cout<<"\n\t";
	textcolor(LIGHTRED);
	crearLineas('=', 100);
	textcolor(WHITE);

	printf("\n\n\n\n\n\n\t\t\t\t1) Juegos con NUMEROS.");
	printf("\n\t\t\t\t2) Juegos con LETRAS.");
	printf("\n\t\t\t\t3) VOLVER ATRAS.");

	textcolor(LIGHTRED);
	cout<<"\n\n\n\n\n\n\t";
	crearLineas('=', 100);
	textcolor(WHITE);
	cout<<"\n\n\n";

	printf("\n\t\t\tINGRESA LA OPCION: ");
	scanf("%d", &op);

	switch(op){
		case 1: Beep(250, 100);system("cls"); numeros();
		break;
		case 2: Beep(250, 100);system("cls"); letras();
		break;
		case 3: Beep(250, 100);system("cls"); menu();
		break;
		default: printf("\t\t\tOpcion no valida. Vuelva a ingresar\n\t\t\t"); system("pause"); system("cls"); Juegos();
	}


}

void letras(){
	int op;
	printf("\n\n\n\n\n\n\t\t\t\tJUEGOS CON LETRAS\n");
	cout<<"\n\t";
	textcolor(LIGHTRED);
	crearLineas('=', 100);
	textcolor(WHITE);

	printf("\n\t\t\t\t1) AHORCADO.");
	printf("\n\t\t\t\t2) VOLVER ATRAS.");

	textcolor(LIGHTRED);
	cout<<"\n\n\n\n\n\n\t";
	crearLineas('=', 100);
	textcolor(WHITE);
	cout<<"\n\n\n";

	printf("\n\t\t\tINGRESA LA OPCION: ");
	scanf("%d", &op);

	switch(op){
		case 1: Beep(250, 100);system("cls"); ahorcado();
		break;
		case 2: Beep(250, 100);system("cls"); categorias();
		break;
		default: printf("\t\t\tOpcion no valida. Vuelva a ingresar\n\t\t\t"); system("pause"); system("cls"); Juegos();
	}


}

void numeros(){
		int op;
	printf("\n\n\t\t\t\t\t\tJUEGOS CON NUMEROS\n");
	cout<<"\n\t";
	textcolor(LIGHTRED);
	crearLineas('=', 100);
	textcolor(WHITE);

	printf("\n\n\n\n\n\n\t\t\t\t1) MAYMEN.");
	printf("\n\t\t\t\t2) WARCOIN - GUERRA DE MONEDAS");
	printf("\n\t\t\t\t3) ADIVINUM");
	printf("\n\t\t\t\t4) VOLVER ATRAS.");

	textcolor(LIGHTRED);
	cout<<"\n\n\n\n\n\n\t";
	crearLineas('=', 100);
	textcolor(WHITE);
	cout<<"\n\n\n";

	printf("\n\t\t\tINGRESA LA OPCION: ");
	scanf("%d", &op);

	switch(op){
		case 1: Beep(250, 100);system("cls"); //maymen();
		break;
		case 2: Beep(250, 100);system("cls"); //warcoin();
		break;
		case 3: Beep(250, 100);system("cls"); adivinum();
		break;
		case 4: Beep(250, 100);system("cls"); categorias();
		break;
		default: printf("\t\t\tOpcion no valida. Vuelva a ingresar\n\t\t\t"); system("pause"); system("cls"); Juegos();
	}




}

void Juegos(){
	int op;
	printf("\n\n\t\t\t\t\t\tMENU\n");
	cout<<"\n\t";
	textcolor(LIGHTRED);
	crearLineas('=', 100);
	textcolor(WHITE);

	printf("\n\n\n\n\n\n\t\t\t\t1) AHORCADO.");
	printf("\n\t\t\t\t2) MAYMEN.");
	printf("\n\t\t\t\t3) WARCOIN - GUERRA DE MONEDAS");
	printf("\n\t\t\t\t4) ADIVINUM");
	printf("\n\t\t\t\t5) VOLVER ATRAS.");

	textcolor(LIGHTRED);
	cout<<"\n\n\n\n\n\n\t";
	crearLineas('=', 100);
	textcolor(WHITE);
	cout<<"\n\n\n";

	printf("\n\t\t\tINGRESA LA OPCION: ");
	scanf("%d", &op);

	switch(op){
		case 1: Beep(250, 100);system("cls"); ahorcado();
		break;
		case 2: Beep(250, 100);system("cls"); // maymen();
		break;
		case 3: Beep(250, 100);system("cls"); //warcoin();
		break;
		case 4: Beep(250, 100);system("cls"); adivinum();
		break;
		case 5: Beep(250, 100);system("cls"); menu();
		break;
		default: printf("\t\t\tOpcion no valida. Vuelva a ingresar\n\t\t\t"); system("pause"); system("cls"); Juegos();
	}

}
