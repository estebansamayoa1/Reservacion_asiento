#include <stdio.h>
#include <stdlib.h>

//Definiciones Globales
int asientos[32][7];
int filas[1][32]; 
char columnas[4]={' ','A','B','C'};
char vuelo[10];
char c2[3]={'D','E','F'};
char asiento[3];
int fila; 
int i;
int j;
int x, y; 
int disponibles=0; 
int ocupados=0; 

//Función de colores 
void blue(){
  printf ("\033[0;34m");
} 
void green(){
  printf ("\033[0;32m");
}
void red(){
  printf("\033[0;31m");
}
void yellow(){
  printf("\033[0;33m");
}
void reset (){
  printf ("\033[0m");
}

//Clear Screen
void clearscreen (){
  system("@cls||clear");
}

//Llenar arreglo
void llenar(){
for (i=0;i<32;i++){
        for (j=0;j<1;j++){
        asientos[i][j] = 0;   
        } 
    }
}



//Función de Bienvenida
void bienvenida(){
  red();
  printf("     ****\n");
  yellow();
  printf("      *****\n");
  red();
  printf("       ******\n");
  yellow();
  printf("       *******\n");
  red();
  printf("        **********************************\n");
  blue();
  printf("         \\                            ////////\n");
  reset();
  red();
  printf("          \\                              *****\n");
  printf("           ***************    ***************\n");
  printf("                         *   *\n");
  printf("                        *   *\n");
  printf("                       *   *\n");
  printf("                         *\n");

  reset(); 
  printf("\nBIENVENIDO A SAMALTE AIRLINES!\n");
  printf("------------------------------\n");
  printf("Escribe el número de vuelo:\n"); 
  scanf("%s", vuelo); 
  printf("\n"); 
  printf("Bienvenido al vuelo %s\n", vuelo); 
} 

//Escoger Asiento
void escoger(){
  printf("Escoja un asiento:\n");
  printf("POR FAVOR ESCRIBA LA LETRA EN MAYUSCULA\n"); 
        scanf("%s", asiento); 
        if (asiento[0] =='A'){
        x = (asiento[0]-asiento[0])+0;
        }
        else if (asiento[0] == 'B'){
        x = (asiento[0]-asiento[0])+1;
        }
        else if (asiento[0]=='C'){
        x = (asiento[0]-asiento[0])+2;
        }
        else if (asiento[0]=='D'){
        x = (asiento[0]-asiento[0])+3;
        }
         else if (asiento[0]=='E'){
        x = (asiento[0]-asiento[0])+4;
        }
         else if (asiento[0]=='F'){
        x = (asiento[0]-asiento[0])+5;
        }
        y = atoi(&asiento[1]);
        y =y-1;     
}




int main (void){
     //Definiciones Locales 
    int opcion;
    //LLenar arreglo
    llenar(); 
    //Código  
    bienvenida();
    Menu: 
    printf("----------------------\n");
    printf("MENÚ PRINCIPAL\n");
    printf("1.Reservar Asientos\n2.Ver Mapa de Asientos\n3.Ver Resumen\n4.Salir\n");
    printf("----------------------\n");
    scanf("%d", &opcion); 
    //Escoger Asientos
    if (opcion==1){
        Escoger:
        escoger(); 
        if (asientos[x][y] == 0){
          asientos[x][y] = 1; 
          green();
          printf("Listo, hemos reservado su asiento!\n");
          reset(); 
          printf("\n");
        }   else if (asientos[x][y] == 1){
        printf("El asiento ya esta ocupado\n\n"); 
        goto Escoger;  
        }

          Mapa:
          for (int a=0;a<4;a++){
        printf(" |%c| ", columnas[a]);
         }
         printf("       ");   
          for (int h=0;h<3;h++){
           printf(" |%c| ", c2[h]);
         }
        printf("\n");
          for (i=0;i<32;i++){
              printf ("%2d  ", i + 1);
              for (j=0;j<3;j++){
                  printf("| %d |", asientos[j][i]);
              }
              printf("  ↑  "); 
              for (int j=3;j<6;j++){ 
                printf(" | %d |", asientos[j][i]);
              }
              printf("\n"); 
          } 
          goto Menu;        
    }
           
    
    //MAPA de Asientos
    else if(opcion==2){
        clearscreen(); 
        goto Mapa; 
        goto Menu;  
    }
    //Resumen
    else if (opcion==3){
        Resumen: 
        printf("-----------------------------------------------\n");
        printf("Resumen de los asientos del vuelo:\n");
        printf("-----------------------------------------------\n");
        for (i=0;i<32;i++){
            for (j=0;j<6;j++){
            if (asientos[j][i]==0){
                    disponibles = disponibles+1; 
            }
            else {
                    ocupados = ocupados+1;
            }
        }
        }
        
        green();
        printf("Los asientos libres son:%d\n", disponibles);
        red(); 
        printf("Los asientos ocupados son:%d\n", ocupados);
        reset();  
        goto Menu;
    }
    //Salir
    else if(opcion==4){
        clearscreen(); 
        printf("GRACIAS POR UTILIZAR NUESTROS SERVICIOS!\n"); 
        exit(0); 
    }
    else{
        clearscreen();
        printf("Opción Invalida");
        goto Menu; 
    }
    
    return 0; 
}