#include <stdio.h>
#include <string.h>
#define NUM_LETRAS 30+1

typedef struct DATA{
       char nombre_archivo[NUM_LETRAS];
       FILE *p;
}ARCHIVOS_CREADOS;


int llenar_pila(){
     
     ARCHIVOS_CREADOS archivos[20];
     char s[NUM_LETRAS];
     char o;
     int i = 0;
     
     while(o != 'q'){
             printf("a)Crear un archivo\n");
             printf("q)Salir\n");
             scanf("%c",&o);
             getchar();
             
             switch(o)
             {
                      case 'a':
                           printf("Nombre del archivo: ");
                           gets(archivos[i].nombre_archivo);
                           
                           archivos[i].p = fopen(archivos[i].nombre_archivo,"w");
                           if(archivos[i].p)
                           {
                                            printf("El archivo %s fue creado con exito\n", archivos[i].nombre_archivo);
                                            i++;
                           }
                           else
                               printf("El archivo %s no pudo ser creado\n",archivos[i].nombre_archivo);
                      break;
                      case 'q':
                           return i;         
                      break;
                      default:
                              printf("Ingrese un valor valido");
                      break;
             }
     }
}

void print_pila(int num){
     
     ARCHIVOS_CREADOS archivos[20];
     
     int i;
         for(i=(num - 1); i > -1; i--)
                    printf("Archivo creado-> %s\n",archivos[i].nombre_archivo);
         getchar();
}

int main(){
    print_pila(llenar_pila());
}
