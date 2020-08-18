#include <stdio.h>
#include <stdlib.h>
#include "conio.c"
#include <string.h>
#include <iostream>
#include <time.h>

using namespace std;

// OWN TOOLS = "HERRAMIENTAS PROPIAS"


// GENERADOR DE TÍTULO Y ENCABEZADO DE ADIVINUM

void TituloAV(){
	textcolor(LIGHTCYAN);
		for(int i=56; i<65; i++){ //36 45
  			gotoxy(i, 3); printf("%c", 205);
    		gotoxy(i, 5); printf("%c", 205);
 		 }
  			for(int i=3; i<5; i++){
    			gotoxy(56, i); printf("%c", 186);
    			gotoxy(65, i); printf("%c", 186);
			}
	
	gotoxy(56, 3); printf("%c", 201);
	gotoxy(56, 5); printf("%c", 200);
	gotoxy(65, 3); printf("%c", 187);
	gotoxy(65, 5); printf("%c", 188);
	gotoxy(10, 4); printf("===========================================>");
	gotoxy(57, 4); printf("ADIVINUM");
	gotoxy(68,4); printf("<============================================");
}

// VISUALIZADOR DE RESULTADO DE LA PARTIDA DEL ADIVINUM

void MarcoResultadoAV(int x){
	if(x==1){
		textcolor(GREEN);
			for(int i=42; i<82; i++){
				gotoxy(i, 9); printf("%c", 205);
				gotoxy(i, 16); printf("%c", 205);
			}
				for(int i=9; i<16; i++){
					gotoxy(42, i); printf("%c", 186);
					gotoxy(81, i); printf("%c", 186);
				}
				
		gotoxy(42, 9); printf("%c", 201);
		gotoxy(42, 16); printf("%c", 200);
		gotoxy(81, 9); printf("%c", 187);
		gotoxy(81, 16); printf("%c", 188);
	}
		if(x==0){
			textcolor(LIGHTRED);
				for(int i=42; i<82; i++){ //39
					gotoxy(i, 9); printf("%c", 205);
					gotoxy(i, 17); printf("%c", 205);
				}
					for(int i=9; i<18; i++){
						gotoxy(42, i); printf("%c", 186);
						gotoxy(81, i); printf("%c", 186);
					}
				
			gotoxy(42, 9); printf("%c", 201);
			gotoxy(42, 17); printf("%c", 200);
			gotoxy(81, 9); printf("%c", 187);
			gotoxy(81, 17); printf("%c", 188);
		}
}

// MUESTRA DE CUADRO CON INFORMACION (INSTRUCCIONES DEL JUEGO) DE ADIVINUM

void InstruccionesAV(){
	textcolor(WHITE);
	for(int i=81; i<119; i++){
		gotoxy(i, 7); printf("%c", 205);
		gotoxy(i, 26); printf("%c", 205);
	}
		for(int i=7; i<27; i++){
			gotoxy(81, i); printf("%c", 186);
			gotoxy(118, i); printf("%c", 186);
		}
		
	gotoxy(81, 7); printf("%c", 201);
	gotoxy(81, 26); printf("%c", 200);
	gotoxy(118, 7); printf("%c", 187);
	gotoxy(118, 26); printf("%c", 188);
	gotoxy(94, 9); printf("INSTRUCCIONES:");
	gotoxy(83, 12); printf("%cDebe adiivinar un numero de 4", 175);
	gotoxy(84, 13); printf("cifras que esta entre 1000 y 9999");
	gotoxy(83, 16); printf("%cEl numero a adivinar no se", 175);
	gotoxy(84, 17); printf("repite ninguno de sus 4 digitos");
	gotoxy(83, 20); printf("%cTiene 10 intentos, no se le", 175);
	gotoxy(84, 21); printf("tiene en cuenta el intento si");
	gotoxy(84, 22); printf("ingresa un numero mayor o menor");
	gotoxy(84, 23); printf("de 4 cifras");
}

// GENERADOR DE TÍTULO Y ENCABEZADO DE MAYMEN

void TituloMYM(){
	textcolor(YELLOW);
		for(int i=50; i<73; i++){
			gotoxy(i, 2); printf("%c", 205);
			gotoxy(i, 8); printf("%c", 205);
		}
			for(int i=2; i<9; i++){
				gotoxy(50, i); printf("%c", 186);
				gotoxy(72, i); printf("%c", 186);
			}
	gotoxy(50, 2); printf("%c", 201);
	gotoxy(50, 8); printf("%c", 200);
	gotoxy(72, 2); printf("%c", 187);
	gotoxy(72, 8); printf("%c", 188);		
	
				for(int i=7; i<51; i++){ 
					gotoxy(i, 5); printf("%c", 205);
				}
					for(int i=72; i<115; i++){
						gotoxy(i, 5); printf("%c", 205);
					}
	gotoxy(50, 5); printf("%c", 185);
	gotoxy(72, 5); printf("%c", 204);
	
	textcolor(LIGHTGREEN );
		for(int i=53; i<70; i++){
			gotoxy(i, 4); printf("%c", 205);
			gotoxy(i, 6); printf("%c", 205);
		}
			for(int i=4; i<7; i++){
			gotoxy(53, i); printf("%c", 186);
			gotoxy(69, i); printf("%c", 186);
		}
	gotoxy(53, 4); printf("%c", 201);
	gotoxy(53, 6); printf("%c", 200);
	gotoxy(69, 4); printf("%c", 187);
	gotoxy(69, 6); printf("%c", 188);
	gotoxy(59, 5);printf("MAYMEN");
}

// GENERADOR DE MARCO CON RESULTADO (GANADOR O PERDEDOR, PUNTAJE) DE MAYMEN

void MarcoResultadoMYM(int PUNTAJE, int Numero){
	if(PUNTAJE>=1){
		textcolor(GREEN);
				for(int i=43; i<80; i++){
					gotoxy(i, 6); printf("%c", 205);
					gotoxy(i, 15); printf("%c", 205);
				}
		
					for(int i=6; i<16; i++){
						gotoxy(43, i); printf("%c", 186);
						gotoxy(79, i); printf("%c", 186);
					}
		gotoxy(43, 6); printf("%c", 201);
		gotoxy(43, 15); printf("%c", 200);
		gotoxy(79, 6); printf("%c", 187);
		gotoxy(79, 15); printf("%c", 188);
		gotoxy(56, 9); printf("FELICIDADES");
		gotoxy(46, 12); printf("Acertaste! Puntaje obtenido: %d", PUNTAJE);
		textcolor(WHITE);
	}else{
		textcolor(LIGHTRED);
			for(int i=45; i<81; i++){
				gotoxy(i, 9); printf("%c", 205); 
				gotoxy(i, 16); printf("%c", 205);
			}
		
				for(int i=9; i<17; i++){
					gotoxy(45, i); printf("%c", 186);
					gotoxy(80, i); printf("%c", 186);
				}
		
		gotoxy(45, 9); printf("%c", 201);
		gotoxy(45, 16); printf("%c", 200);
		gotoxy(80, 9); printf("%c", 187);
		gotoxy(80, 16); printf("%c", 188);
		gotoxy(48, 12); printf("Perdiste! Puntaje Obtenido %d", PUNTAJE);
		gotoxy(48, 13); printf("El nuemero a adivinar era: %d", Numero);
		textcolor(WHITE);
	}
}

// GENERADOR DE TÍTULO Y ENCABEZADO DE WARCOIN
void TituloWC(){
	textcolor(LIGHTMAGENTA);
		for(int i=56; i<65; i++){
  			gotoxy(i, 3); printf("%c", 205);
    		gotoxy(i, 5); printf("%c", 205);
 		 }
  			for(int i=3; i<5; i++){
    			gotoxy(56, i); printf("%c", 186);
    			gotoxy(64, i); printf("%c", 186);
			}
	gotoxy(56, 3); printf("%c", 201);
	gotoxy(56, 5); printf("%c", 200);
	gotoxy(64, 3); printf("%c", 187);
	gotoxy(64, 5); printf("%c", 188);
	gotoxy(10, 4); printf("===========================================>");
	gotoxy(57, 4); printf("WARCOIN");
	gotoxy(67,4); printf("<============================================");
}

//GENERADOR DE MARCO DEL RESULTADO, E INDICA SI EL USIARIO GANÓ O PERDIÓ (WARCOIN)

void MarcoResultadoWC(int TURNO){
	if(TURNO==1){
		textcolor(GREEN);
			for(int i=46; i<85; i++){
				gotoxy(i, 7); printf("%c", 205);
				gotoxy(i, 13); printf("%c", 205);
			}
				for(int i=7; i<14; i++){
					gotoxy(46, i); printf("%c", 186);
					gotoxy(84, i); printf("%c", 186);
				}
		gotoxy(46, 7); printf("%c", 201);
		gotoxy(46, 13); printf("%c", 200);
		gotoxy(84, 7); printf("%c", 187);
		gotoxy(84, 13); printf("%c", 188);
		gotoxy(50, 10); printf("GANASTE!!! Puntaje obtenido: 5");
	}else{
		textcolor(LIGHTRED);
			for(int i=37; i<85; i++){
				gotoxy(i, 7); printf("%c", 205);
				gotoxy(i, 13); printf("%c", 205);
			}
				for(int i=7; i<14; i++){
					gotoxy(37, i); printf("%c", 186);
					gotoxy(84, i); printf("%c", 186);
				}	
		gotoxy(37, 7); printf("%c", 201);
		gotoxy(37, 13); printf("%c", 200);
		gotoxy(84, 7); printf("%c", 187);
		gotoxy(84, 13); printf("%c", 188);
		gotoxy(40, 10); printf("LA COMPUTADORA GANO!!! Puntaje obtenido: 0");
	}
}
 //TÍTULO Y ENCABEZADO DEL AHORCADO
 
void TituloAH(){
	textcolor(LIGHTRED);
	printf("\n\n\t\t\t==============================<|");
	textcolor(WHITE);cout<<"  AHORCADO  ";textcolor(LIGHTRED); cout<<"|>==============================\n\n\n";
	textcolor(WHITE);
}

// GENERADOR DE LINEAS 

void crearLineas(char simbolo, int cantidad){
	for(int i=0; i<cantidad; i++){
		cout<< simbolo;
	}
}

//  VISUALIZADOR DE PARTES DEL CUERPO DEL AHORCADO EN FORMA GRÁFICA

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
