#include "Owntools.h"

//Funciones
void Juego();
void PilaMoneda();
void PedirDatos();
void GenerarTurno();
void Informacion();

//Variables Globales
int pila=0, moneda, minimo, maximo,  extraccion=0, turno=0, turnoIni;

main(){
	system("mode 120, 35");
	int verificar;
	bool op=true;
	while(op==true){
		Juego();
		gotoxy(5, 15); printf("\n%c Quieres volver a jugar? (Para SI ingrese '1', para NO ingrese '2'): ", 175);
		scanf("%d", &verificar);
				if(verificar==2){
					op=false;
					textcolor(WHITE);
					printf("\nSaliendo del juego......\n");
					printf("\nAdios....\n");
				}
				else{
					system("cls");
				}
	}
}

void Juego(){
	int contador=0, terminar=1, pilaOrg=pila, rltPila=5;
	PilaMoneda();
	TituloWC();
	PedirDatos();
	GenerarTurno();
		while(terminar!=0){
			if(turno==2){
				textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
				textcolor(3); printf("\n\t\t\t%cTurno de la computadora%c\n", 175, 174);
				extraccion= minimo + rand()%(maximo + 1 - minimo);
				Sleep(2000);
				textcolor(WHITE); printf("\n\t\t\tLa computadora saco %d monedas\n", extraccion);
				pila-=extraccion;
				printf("\n");
					if(pila<minimo){
						textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
						Sleep(2000);
						terminar=0;
						printf("\n");
					}else{
						turno--;
					}
			}
			else{
					textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
					textcolor(YELLOW); printf("\n\n\t\t\t%cTurno del usuario%c\n", 175, 174);
					textcolor(WHITE); printf("\n\t\t\tElija la cantidad de monedas a sacar: ");
					scanf("%d", &moneda);
						if(moneda<=maximo and moneda>=minimo){
							pila-=moneda;
						}else{
							printf("\n\n\t\t\tPor favor ingresar un valor que se encuentre entre %d y %d\n ", minimo, maximo);
							printf("\n\t\t\tElija la cantidad de monedas a sacar: ");
							scanf("%d", &moneda);
							pila-=moneda;
							printf("\n");
						}
					textcolor(GREEN);
							if(pila<minimo){
								textcolor(LIGHTCYAN); printf("\n\n\t\t\t\t========La pila tiene %d modenas========\n",pila);
								Sleep(2000);
								terminar=0;
							}else{
								turno++;	
							}
			}
				if(contador==1){
					system("pause");
					system("cls");
					contador=0;
					TituloWC();
					Informacion();
				}else{
					contador++;
				}
		}
	system("cls");
	MarcoResultadoWC(turno);
}

void PilaMoneda(){
	srand(time(NULL));
	pila=10+rand()%(50+1-10);
}

void PedirDatos(){
	textcolor(WHITE); 
	gotoxy(32, 8); printf("%cIngresar el valor minimo de monedas a sacar por turno: ", 175);
	scanf("%d", &minimo);
	gotoxy(32, 9); printf("%cIngresar el valor maximo de monedas a sacar por turno: ", 175);
	scanf("%d", &maximo);
	gotoxy(5,12); printf("\t-------------------------------------------------------------------------------------------------------\n");
}

void GenerarTurno(){
	turno= 1 + rand()%(2+1 - 1);
	gotoxy(45, 12);
		if(turno==1){
			textcolor(YELLOW); printf("| Inicia la partida el usuario |");
		}else{
			textcolor(CYAN); printf("| Inicia la partida la computadora |");
		}
	gotoxy(0,13);
}

void Informacion(){
	textcolor(WHITE); 
	gotoxy(32, 8); printf("%cLa cantidad minima permitida para sacar monedas es: %d", 175, minimo);
	gotoxy(32, 9); printf("%cLa cantidad maxima permitida para sacar monedas es: %d", 175, maximo);
	gotoxy(5,12); printf("\t-------------------------------------------------------------------------------------------------------\n");
}
