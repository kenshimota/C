#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX_CHAR 40+1

int num_jobs = 0;

struct Swork{
	int id;
	char name[NAME_MAX_CHAR];
	float money;
}jobs[100];


int read_name(char *c){
	do{
		printf("Ingrese el nombre: ");
		scanf("%s",*c);
		getchar();

		if(strlen(*c) >= 3)
			return 0;
		else
			printf("El nombre ingresado no es valido...\n");

	}while(2 == 2);
}

int read_num(char s[]){

	do{
		int num;
		printf("Ingrese su %s: \n",s);
		int count = scanf("%d",&num);
		getchar();

		if(count == 1 && num > 0)
			return num;
		else
			printf("El de %s no es valido...\n",s);
	}while(2 == 2);
}

int create_jobs(){

    char name[20];

	read_name(name);

	jobs[num_jobs].id = read_num("Cedula de identidad");

	printf("Cantidad de ingreso mensual en Bs.F: \n");
	scanf("%f",&jobs[num_jobs].money);
	getchar();

	num_jobs++;
}

void show_jobs(){
	int i;
	printf("| N | Nombre y Apellido | Ci | Sueldo |\n");
	if(num_jobs == 0)
		printf("No hay Datos\n");
	for(i=0; i < num_jobs; i++)
	{
		printf("| %d | %s | %d | %d Bs.F |\n",(i+1), jobs[i].name, jobs[i].id, jobs[i].money);
		printf("__________________________________");
	}
}

int up_money(){
	show_jobs();

	int id;
	do{
		printf("Seleccione empleado: \n");
		scanf("%d",&id);
		getchar();
		if(id < num_jobs)
		{
			int porcentaje;
			printf("Ingrese el porcentaje del aumento (%): ");
			scanf("%d",&porcentaje);
			getchar();

			jobs[id - 1].money = ((porcentaje * jobs[id - 1].money) / 100) + jobs[id - 1].money;
			return 0;
		}
		else
			printf("No ha seleccionado a ningun empleado...\n");

	}while(id > num_jobs);
}

void print_option(){

	printf("1)Registrar empleado\n");
	printf("2)Aumentar sueldo de empleado\n");
	printf("3)Mostrar lista de empleados\n");
	printf("4)Salir\n");
}

int read_options(){

	do{
		print_option();
		int option = 0;

		printf("Seleccione su opcion: ");
		scanf("%d", &option);
		getchar();

		switch(option){
			case 1:
				create_jobs();
				return 0;
			break;
			case 2:
				up_money();
				return 0;
			break;
			case 3:
				show_jobs();
				return 0;
			break;
			case 4:
				exit(1);
			break;
			default:
				printf("La opcion ingresada no es valida...");
			break;
		}
	}while(2 == 2);
}

void print_welcome(){
	printf("-------------------Daga Empleados---------------------------\n");
}

int main(){
	do{

		print_welcome();

		read_options();

	}while(2 == 2);
}
