/*  David Riv-DawffyddRiv */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>

int main(){
	//Declaración de datos de variables de identificación
	char nombre[30], paternoApe[30], maternoApe[30], carrera[50];
	
	//Definición y declaración de la fecha actual	
	time_t ahora;
    struct tm *	actual;    
    time(&ahora);
 	actual = localtime(&ahora);    
	printf("La fecha actual es: %d-%d-%d \n", actual->tm_mday, actual->tm_mon+1, actual->tm_year+1900);
	printf("\n");
		
	//Declaración de varialbes correspondientes al inicio  de la licenciatura	
    struct tm iniStrLic={0};     
    	
	//Declaración de variables de posible termino de la licenciatura
    struct tm finStrLic={0};     
	
	//declaración de la fecha de nacimiento	
    struct tm strNacimiento={0}; 
    
    //Declaración de estructuras para comparación
    
	int edadDias;
    int edadMeses;
    int edadAnios;
	
	// Inicio datos de identificación
	//fflush(stdin);
	printf("Introduce el/los nombre(s) del alumno \n");
	scanf("%30[^\n]s",nombre);
	getchar();
	
	printf("Introduce el apellido paterno \n");
	scanf("%s", &paternoApe);
	
	printf("Introduce el apellido materno \n");
	scanf("%s", &maternoApe);	
	fflush(stdin);
	printf("Introduce tu carrera \n");
	fgets(carrera, 50, stdin);
	
	
	//Inicio entrada de fechas correspondientes al inicio de la licenciatura
	printf("Introduce el numero del dia de incio de la licenciatura \n");	
	scanf("%d", &iniStrLic.tm_mday);
	printf("Introduce el numero del mes de incio de la licenciatura \n");	
	scanf("%d", &iniStrLic.tm_mon);
	printf("Introduce el anio de incio de la licenciatura \n");	
	scanf("%d", &iniStrLic.tm_year);
    /*printf("Introduce el dia, mes y anio de incio de la licenciatura \n");
    scanf("%d %d %d",&iniStrLic.tm_mday, &iniStrLic.tm_mon, &iniStrLic.tm_year);*/
	//printf("Fecha de inicio de la licenciatura:\n %d-%d-%d \n", iniStrLic.tm_mday, iniStrLic.tm_mon, iniStrLic.tm_year);
    
	//Inicio entrada de fechas de titulación	
	printf("Introduce el numero del dia estimado de titulacion de la licenciatura \n");	
	scanf("%d", &finStrLic.tm_mday);
	printf("Introduce el numero del mes estimado de titulacion de la licenciatura \n");	
	scanf("%d", &finStrLic.tm_mon);
	printf("Introduce el anio estimado de titulacion de la licenciatura \n");	
	scanf("%d", &finStrLic.tm_year);
	
	//printf("%d-%d-%d \n", finStrLic.tm_mday,finStrLic.tm_mon,finStrLic.tm_year);
    
	//Condicional para entrada correcta de años en la fecha de incio y termino
	while( (iniStrLic.tm_year)>=(finStrLic.tm_year) )
	{
		printf("El anio de la fecha que introduciste de termino es menor o igual a la de inicio \n");				
		printf("Vuelve a introducir las fechas y pulsa enter despues de cada digito solicitado \n");
		printf("Fecha incio de la licenciatura por dia, mes y anio \n");
    	scanf("%d %d %d",&iniStrLic.tm_mday, &iniStrLic.tm_mon, &iniStrLic.tm_year);	
		//printf("La fecha de inicio introducida fue:  %d-%d-%d \n", iniStrLic.tm_mday, iniStrLic.tm_mon, iniStrLic.tm_year);
    
		//Inicio entrada de fechas de termino de la licenciatura	
		printf("Fecha estimada de titulacion de la licenciatura por dia, mes y anio \n");
    	scanf("%d %d %d", &finStrLic.tm_mday,&finStrLic.tm_mon,&finStrLic.tm_year);	
		//printf("La fecha de titulacion introducida fue: %d-%d-%d \n", finStrLic.tm_mday,finStrLic.tm_mon,finStrLic.tm_year);
		
	}

	//Entrada de fecha correspondiente a la fecha de nacimiento
	
	printf("Introduce el numero del dia de la fecha de nacimiento \n");	
	scanf("%d", &strNacimiento.tm_mday);
	printf("Introduce el numero del mes de la fecha de nacimientoi \n");	
	scanf("%d", &strNacimiento.tm_mon);
	printf("Introduce el anio de la fecha de nacimiento \n");	
	scanf("%d", &strNacimiento.tm_year);
	//printf("%d-%d-%d \n", strNacimiento.tm_mday,strNacimiento.tm_mon,strNacimiento.tm_year);
	
	while((strNacimiento.tm_year)>=(iniStrLic.tm_year) || (strNacimiento.tm_year)>= (finStrLic.tm_year) )
	{
		printf("El anio de la fecha de nacimiento que introduciste no es correcta \n");	
		printf("Vuelve a introducir la fecha y pulsa enter despues de cada digito solicitado (día, mes y anio) \n");		
		scanf("%d %d %d",  &strNacimiento.tm_mday,&strNacimiento.tm_mon,&strNacimiento.tm_year);	
		//printf("La fecha de nacimiento introducida es %d-%d-%d \n", strNacimiento.tm_mday,strNacimiento.tm_mon,strNacimiento.tm_year);
    
	}

	//Inicia condicionales
	
	edadAnios=(actual->tm_year+1900)-(strNacimiento.tm_year);
	//printf("diferencia anios %d \n",edadAnios);	
	
	if( (actual->tm_mon+1)< (strNacimiento.tm_mon) ){
		
		edadAnios=edadAnios-1;
		edadMeses=(12-strNacimiento.tm_mon)+(actual->tm_mon+1);
		
		if((actual->tm_mday) < (strNacimiento.tm_mday) ){
			
			edadMeses=edadMeses-1;
			edadDias=(30-strNacimiento.tm_mday)+(actual->tm_mday+1);
			
		}
		else{
			edadDias=(actual->tm_mday)-(strNacimiento.tm_mday);
			
		}
		
	}
	else{
		edadMeses=(actual->tm_mon+1)-(strNacimiento.tm_mon);
		
		if( (actual->tm_mday) < (strNacimiento.tm_mday) ){
			
			//edadDias=(actual->tm_mday);
			edadMeses=edadMeses-1;
			edadDias=(30-strNacimiento.tm_mday)+(actual->tm_mday+1);
			
			
		}
		else{
			
			edadDias=(actual->tm_mday)-(strNacimiento.tm_mday);
						
		}
	}		
	printf("\n");	
	printf("Nombre completo: %s %s %s \n", nombre , paternoApe , maternoApe);
	printf("Carrera: %s",carrera);
	printf("Fecha inicio de carrera: %d-%d-%d \n",iniStrLic.tm_mday, iniStrLic.tm_mon, iniStrLic.tm_year);
	printf("Fecha posible titulacion: %d-%d-%d \n",finStrLic.tm_mday,finStrLic.tm_mon,finStrLic.tm_year);
	printf("Fecha de nacimiento: %d-%d-%d \n",strNacimiento.tm_mday,strNacimiento.tm_mon,strNacimiento.tm_year);
	printf("Edad: %d anios, %d meses, %d dias \n",edadAnios,edadMeses,edadDias);
     
    
