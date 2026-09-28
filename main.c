#include <stdio.h>
#include <stdlib.h>
#define tam 12	//Define tamaño de vector meses[]
float suma(float,float);
float suma_vector(float vec[],int);
float promedio(float,int);
void informar(int,float,int,int,float,int,int);
void separador(int);

/* Ejercicio: primer parcial */

void main()
{
	int sensor,b=0,mes,min=0,sensor_minima,suma_sensor=0,suma_sensor_bc=0,sensor_marzo=0;
	float temperatura,temperatura_minima,meses[tam]={0};
	
	printf("\t\t\t***Bienvenido***\n");
	separador(90);
	printf("\nIngrese numero de sensor positivo para inicar o (0) para salir: ");
	scanf("%d",&sensor);
	while(sensor!=0)	//Sale del while con 0
	{	
		if(sensor>0)	//Comprueba si el sensor ingresado es positivo
		{
			b=1;	//Bandera para saber que entro al menos una vez al bucle
			printf("Ingrese el mes de registro del 1 al 12: ");
			scanf("%d",&mes);
			while(mes>12||mes<=0)	//Una condicion en bucle para asegurar el ingreso del mes del 1 al 12
			{
				printf("Ingrese el mes nuevamente del 1 al 12: ");
				scanf("%d",&mes);
			}
			printf("Ingrese temperatura a registrar: ");
			scanf("%f",&temperatura);
			if(min==0||temperatura_minima>temperatura)	//If para registrar la temperatura minima 
			{
				min=1;
				temperatura_minima=temperatura;	//Registra la temperatura minima
				sensor_minima=sensor;	//Registra el sensor que registra la temperatura minima
			}
			if(sensor<=50)	//If para registrar las temperaturas de los sensores del 1 al 50, los menores a 1 quedan descartados del while deade antes
			{
				meses[mes-1]=suma(meses[mes-1],temperatura);	//Llama a la funcion suma para llenar un vector con la sumatoria de los registros por mes
				suma_sensor++;
			}
			if(temperatura<0)	//If para registrar la cantidad de sensores que registraron temperaturas bajo cero
			{
				suma_sensor_bc++;
			}
			if(mes==3)	//If para registrar la cantidad de sensores que se registraron en marzo
			{
				sensor_marzo++;
			}
			printf("\nIngrese numero de sensor positivo para operar o (0) para salir: "); //Decision para continual o salir
			scanf("%d",&sensor);
		}
		else	//Pide un nuevo ingreso si el valor es negativo
		{
			printf("\nIngrese nuevamente un numero positovo o (0) para salir: ");
			scanf("%d",&sensor);
		}
	}
	
	separador(90);
	informar(sensor_minima,suma_vector(meses,tam),suma_sensor,suma_sensor_bc,meses[2],sensor_marzo,b);
	separador(90);
}

float suma(float v1,float v2)	//Funcion para sumar 2 valores
{
	float salida;
	salida=v1+v2;
	return(salida);
}

float suma_vector(float vec[],int tamanio)	//Funcion para sumar los elementos de cada componente del vector
{
	int i;
	float salida=0;
	for(i=0;i<tamanio;i++)
	{
		salida+=vec[i];
	}
	return(salida);
}

float promedio(float v1,int v2)	//Funcion que calcula el promedio entre 2 valores
{
	float salida;
	if(v2!=0)
	{
		salida=v1/v2;
	}
	return(salida);
}

void informar(int sensor_minima,float suma_temperatura,int suma_sensor,int suma_sensor_bc,float temperatura_marzo,int sensor_marzo,int b)	//Funcion para informar los resultados o informar si no se ingresaron datos
{
	if(b==1)	//Si la bandera esta en 1 imprime resultados sino informa que no hubo operacion
	{
		printf("\n\t\t\t***Resultados***\n");
		printf("\n%-65s %-15d\n","Numero de sensor que registro la temperatura mas baja:",sensor_minima);
		if(suma_sensor!=0)	//Imprime un mensaje u otro dependiendo del denominador
		{
			printf("%-65s %-15.2f\n","Promedio de temperaturas de los sensores del 1 al 50:",promedio(suma_temperatura,suma_sensor));
		}
		else
		{
			printf("%-65s %-25s","Promedio de temperaturas de los sensores del 1 al 50:","No hay datos registrados\n");
		}
		printf("%-65s %d\n","Cantidad de sensores que registraron temperaturas bajo 0:",suma_sensor_bc);
		if(sensor_marzo!=0)	//Imprime un mensaje u otro dependiendo del denominador
		{
			printf("%-65s %.2f\n","Promedio de todas las temperaturas para el mes de marzo:",promedio(temperatura_marzo,sensor_marzo));
		}
		else
		{
			printf("%-65s %-25s","Promedio de todas las temperaturas para el mes de marzo:","No hay datos registrados\n");
		}
	}
	else
	{
		printf("\nNo se ingresaron datos\n");
	}
}

void separador(int cantidad)	//Funcion para repetir un caracter como separador
{	
	int i;
	for(i=0;i<cantidad;i++)
	{
		printf("=");
	}
}
