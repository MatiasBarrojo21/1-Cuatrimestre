#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>


int cantLetras(char palabra[]){
	int letras=0;
	for(int i=0; palabra[i]!='\0'; i++){
		if(isalpha(palabra[i])){
			letras++;
		}
		
	}
	
	return letras;
}
