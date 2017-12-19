/* librerias que nos permitiran el desarrollo de nuestra aplicacion  */
#include<conio.h>
#include<stdio.h>
#include<math.h>


float f(float x)
{
	return 1.0+x*x*x;
}

/* funcion encargada de obtener un numero ingresado por el usuario 
y retornara el valor flotante */

float get_num(){
	
	float num = 0;
	int count;
	
	//Esto hara que se repita siempre, pues mi while sera un bucle 'infinito' propiamente controlado un codicional
	while(1){
		/* count obtendra el valor retornado de scanf que retorna 1 si el valor ingresado por 
		el usuario es verdadero y 0 cero si no es el valor ingresado no esta asociado a la variable */
		count = scanf("%f",&num);
		getchar();
		
		if(count == 1)
			return num;
		else
			printf("El valor ingresado no es valido...\nIngrese un numero: ");
	}
}

int main()
{
	int i,n;
	float a,b,h,x,s2,s3,sum,integral;
	
	printf("enter the lower limit of the integration");
	a = get_num();
	
	printf("enter the upper limit of the integration");
	b = get_num();
	
	printf("enter the number of intervals");
	n = get_num();
	
	h=(b-a)/n;
	sum=f(a)+f(b);
	s2=s3=0.0;
	
	for(i=1;i<n;i+=3)
	{
		x=a+i*h;
		s3=s3+f(x)+f(x+h);
	}
	for(i=3;i<n;i+=3)
	{
		x=a+i*h;
		s2=s2+f(x);
	}
	intgral=(h/3.0)*(sum+2*s2+4*s3);
	printf("\nvalue of the integral =%9.4f\n",integral);
	getchar();
}
