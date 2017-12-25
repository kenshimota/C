#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX_CHAR 50+1
#define COUNT_WORK(p) (sizeof(p)/sizeof(JOBS))

typedef struct Swork
{
	int id;
	char name[NAME_MAX_CHAR];
	float money;
}JOBS;


int get_year()
{
	while(1)
	{
		//variable declara para dar la edad al usuario
		int id = 0;

		printf("Ingrese la Cedula de Identidad: \n");

		/** -- obtiene si es verdadero o falso de l valor ingresado es un numero entero -- */
		int count = scanf("%d",&id);
		getchar();
		if(count == 1 && id > 100000)
			return id;
		else
			printf("Ingrese un numero de Cedula valido...\n");
	}
}


int get_name(char *c)
{
	while(1)
	{
		printf("Ingrese el nombre: ");
		gets(c);

		if(strlen(c) > 3 && strlen(c) < NAME_MAX_CHAR - 1)
			return 0;
		else
			printf("El nombre ingresado no es valido...\n");
	}
}

float get_money()
{
	while(1)
	{
		float money;
		printf("Ingrese el sueldo en Bs.F: \n");
		scanf("%2f",&money);
		getchar();

		if(money > 0)
			return money;
		else
			printf("El dato ingresdo no es valido...\n");
	}
}

/** -- En esta seccion del programa el creara a la persona
trabajadora (trabajador) pasando por funciones para obtener y dar a conocer sus datos --*/
int create_people_work()
{
	/** -- la variable people contiene los datos de los trabajadores -- */
	JOBS *people;

	people = (JOBS *)malloc(sizeof(JOBS));

	people[COUNT_WORK(people)].id = get_year(); //obtiene la edad

	get_name(people[COUNT_WORK(people)].name); //atravez de un puntero obtendra el nombre 

	people[COUNT_WORK(people)].money = get_money(); //obtiene sueldo

	printf("personas(%d)\n",sizeof(people));
}

/** -- Main -- */
int main(int argc, char const *argv[])
{
	create_people_work();
	getchar();
	getchar();
	return 0;
}
