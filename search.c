


#include <stdio.h>
#include <stdlib.h>
#include "struct_keeper.h"
#include <string.h>
#include "Prototypes.h"

void StringSearch(car *p_car,int * Res)
{

	int i=0;
	char buff[20];

	printf("Plz Input/n");
	scanf("%s",buff);

	while (i<N)
	{
		if(strcmp(buff,p_car[i].mark)==0 || strcmp(buff,p_car[i].model)==0 || strcmp(buff, p_car[i].body)==0 )
		{   Res[i]=i;
            printf("The car number %d has this value", i); }
		else Res[i]=0;
		i++;
	}
}

void YearSearch(car *p_car,int * Res)
{

	int i;
	int yr;

	printf("Plz Input Year/n");
	scanf("%d",&yr);

	for(i=0;i<N;i++)
	{
		if(p_car[i].year == yr)
			Res[i]=i;
		else
			Res[i]=0;
		printf("The car number %d has this",Res[i]);
	}
}

void EngineSearch(car *p_car, int *Res)
{
	int i;
	int n;
 SearchSwtch:
	printf("Plz Input The Type Of Ur Engine: 1 - Diesel, 2 - Gas, 3 - Electric /n");
	scanf("%d",&n);
	switch(n)
	{
	case 1: for(i=0;i<N;i++)
		{
		if(p_car[i].type1 == diesel)
			{Res[i]=i;
		printf("The car number %d has this",i);}
		else
			Res[i]=0;}
			break;
	case 2: for(i=0;i<N;i++)
		{
			if(p_car[i].type1 == gas)
			{Res[i]=i;
			printf("The car number %d has this",i);}
			else
			Res[i]=0;} break;
	case 3: for(i=0;i<N;i++)
		{
			if(p_car[i].type1 == electric)
			{Res[i]=i;
			printf("The car number %d has this",i);}
			else
			Res[i]=0;} break;
	default: printf("Invalid Input");
		goto SearchSwtch;

	}
	
}
