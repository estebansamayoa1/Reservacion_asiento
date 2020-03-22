#include <stdio.h>
#include <stdlib.h>


char columna; 
char fila; 
int asi1=0;
int asi2; 
int i;
int j; 

void escoger(){
Inicio:
  printf("Escoja un número de columna:\n"); 
  scanf("%c", &columna); 
  if (columna =='A'){
    columna = (columna-columna)+1;
    printf("%d\n", columna);
    goto Inicio;
  }
  else if (columna=='B'){
    columna = (columna-columna)+2;
    printf("%d\n", columna);
    goto Inicio; 
  }
  else if (columna=='C'){
    columna = (columna-columna)+3;
    printf("%d\n", columna); 
    goto Inicio;
  }
  else if (columna=='D'){
    columna = (columna-columna)+4;
    printf("%d\n", columna); 
    goto Inicio;
  }
  else if (columna=='E'){
    columna = (columna-columna)+5;
    printf("%d\n", columna); 
    goto Inicio;
  }
  else if (columna=='F'){
    columna = (columna-columna)+6;
    printf("%d\n", columna);
    goto Inicio; 
  }
  else{
      printf("Columna invalida\n"); 
      goto Inicio;
  }
}


int main() { 
    escoger();  

    return 0;
}
