/*
Файл с функциями ввода в структуру
Сначала функция ввода вручную и сохранения в файл
Ниже функция ввода из файла*/

#include <stdio.h>
#include <stdlib.h>
#include "struct_keeper.h"
#include "Prototypes.h"

//Принимает только одну структуру

void HandInput(car *p_car)
{
    FILE *myfile;
    int i=0;
    int j=0;

    //myfile=fopen("CarBase.txt","a+");
    if((myfile=fopen("Cars.txt","a+")) == NULL)
        perror("File Error");
	else
	{


    printf("\nChoose what type of engine in the your car: diesel=1,fuel=2,electric=3");
    scanf("%d",&i);
   if(fwrite(&i,sizeof(int),1,myfile)!=1)
         printf("Error of writing in file\n");
    else
    switch(i)
    {
        case diesel: p_car->type1=diesel;
        printf("\nInput the moment of ur engine ");
        scanf("%d", &(p_car->eng1.d_eng.k_moment));
        //fprintf(myfile," %f",p_car->eng1.d_eng.k_moment);
        if(fwrite(&(p_car->eng1.d_eng.k_moment),sizeof(int),1,myfile)!=1)
         printf("Error of writing in file \n");

        printf("\nInput the volume of ur engine ");
        scanf("%f",&(p_car->eng1.d_eng.vol));
        //fprintf(myfile," %f",p_car->eng1.d_eng.vol);
        if(fwrite(&(p_car->eng1.d_eng.vol),sizeof(float),1,myfile)!=1)
         printf("Error of writing in file \n");

		printf("\nInput the transmission of ur engine: akpp=0, mkpp=1,variator=2,robot=3 ");
		scanf("%d",&j);
		switch(j)//vybor transmissii
        {
            case akpp: p_car->eng1.d_eng.Dkpp=akpp;

            break;
            case mkpp: p_car->eng1.d_eng.Dkpp=mkpp;
            break;
            case variator: p_car->eng1.d_eng.Dkpp=variator;
            break;
            case robot: p_car->eng1.d_eng.Dkpp=robot;
            break;
            default: printf("Invalid value");

            }
            //fprintf(myfile," %d",p_car->eng1.d_eng.Dkpp);
            if(fwrite(&(p_car->eng1.d_eng.Dkpp),sizeof(int),1,myfile)!=1)
             printf("Ошибка при записи файла.\n");
        break;

        case(gas): p_car->type1=gas;
        printf("\nInput the power of ur engine in hors power ");
        scanf("%d",&(p_car->eng1.g_eng.h_pow));
        //fprintf(myfile," %d",p_car->eng1.g_eng.h_pow);
        if(fwrite(&(p_car->eng1.g_eng.h_pow),sizeof(int),1,myfile)!=1)
             printf("Ошибка при записи файла.\n");

		printf("\nInput the volume of ur engine in liters ");
        scanf("%f",&(p_car->eng1.g_eng.vol));
        //fprintf(myfile," %f",p_car->eng1.g_eng.vol);
        if(fwrite(&(p_car->eng1.g_eng.vol),sizeof(float),1,myfile)!=1)
             printf("Ошибка при записи файла.\n");

		printf("\nInput the kpp of ur engine: akpp=0, mkpp=1,variator=2,robot=3 ");
		scanf("%d",&j);
		switch(j)
        {
            case akpp: p_car->eng1.g_eng.Gkpp=akpp;
            break;
            case mkpp: p_car->eng1.g_eng.Gkpp=mkpp;
            break;
            case variator: p_car->eng1.g_eng.Gkpp=variator;
            break;
            case robot: p_car->eng1.g_eng.Gkpp=robot;
            break;
            default: printf("Invalid value");

         }
        //fprintf(myfile," %d",p_car->eng1.g_eng.Gkpp);
        if(fwrite(&(p_car->eng1.g_eng.Gkpp),sizeof(int),1,myfile)!=1)
             printf("Error of writing in file\n");
        break;

        case electric: p_car->type1=electric;
        printf("\nInput the power of ur engine in kW ");
        scanf("%d",&(p_car->eng1.Eeng.el_pow));
        //fprintf(myfile," %d",p_car->eng1.Eeng.el_pow);
        if(fwrite(&(p_car->eng1.Eeng.el_pow),sizeof(int),1,myfile)!=1)
             printf("Error of writing in file\n");

        printf("\nInput the K_moment of ur engine in N*m: ");
        scanf("%d",&(p_car->eng1.Eeng.k_moment));
        //fprintf(myfile," %d",p_car->eng1.Eeng.k_moment);
        if(fwrite(&(p_car->eng1.Eeng.k_moment),sizeof(int),1,myfile)!=1)
             printf("Error of writing in file\n");
        break;
        default: printf("Invalid value,plz retry");

    }


    printf("\nInput the mark of ur car in 10 symbol");
    scanf("%s", p_car->mark);
    //fprintf(myfile," %s", p_car->mark);
    if(fwrite(p_car->mark,sizeof(char),20,myfile)!=20)
     printf("Error of writing in file mark\n");

    printf("\nInput the model of ur car in 10 symbol");
    scanf("%s",p_car->model);
    //fprintf(myfile," %s", p_car->model);
    if(fwrite(p_car->model,sizeof(char),20,myfile)!=20)
     printf("Error of writing in file model\n");

    printf("\nInput the body of ur car in 10 symbol");
    scanf("%s", p_car->body);
    //fprintf(myfile," %s", p_car->body);
    if(fwrite(p_car->body,sizeof(char),20,myfile)!=20)
         printf("Error of writing in file body\n");

	printf("\nInput the year of ur car ");
    scanf("%d", &p_car->year);
    //fprintf(myfile," %d\n",p_car->year);
    if(fwrite(&p_car->year,sizeof(int),1,myfile)!=1)
         printf("Error of writing in file\n");
	}

    fclose(myfile);
}

//input all of  the cars from one file
void FileInput(car *p_car)
{
FILE *myfile;
int i=0;
int c[N]; //variable for compearing with enum eng_type
int kpp[N]; //var for comparing with enum kpp

//myfile = fopen("E:\Gleb's files\create\program\Gleb_structure\CarBase.txt","r+");

//proverka na otrytie
if((myfile=fopen("Cars.txt","r+")) == NULL) {
    printf("Error of opening file,plz input by hand\n");
	HandInput(p_car); }
else
while (i<N)//prohod po vsem car
{

    /*
    	fscanf (myfile, "%d", (c+i));//schitivanie enum eng_type
	printf("%d",c[i]);

	printf("\n%d\n",ftell(myfile));

switch(c[i])
    {
case 1: p_car[i].type1=diesel;
   if( fscanf(myfile," %d %1.1f %d %s %s %s %d",&(p_car[i].eng1.d_eng.k_moment), &(p_car[i].eng1.d_eng.vol), kpp+i, p_car[i].mark,p_car[i].model,p_car[i].body,&(p_car[i].year)) < 0)
	   printf("fscanf error");
	printf(" %d %1.1f %d %s %s %s %d\n",p_car[i].eng1.d_eng.k_moment,p_car[i].eng1.d_eng.vol, kpp[i], p_car[i].mark , p_car[i].model,p_car[i].body, p_car[i].year);

    switch(kpp[i])
        {
            case akpp: p_car[i].eng1.d_eng.Dkpp=akpp;
            break;
            case mkpp: p_car[i].eng1.d_eng.Dkpp=mkpp;
            break;
            case variator: p_car[i].eng1.d_eng.Dkpp=variator;
            break;
            case robot: p_car[i].eng1.d_eng.Dkpp=robot;
            break;
            default: printf("Invalid information in file with car ", i);
			   system("Pause");
				exit(EXIT_FAILURE);

         }
break;

case 2: p_car[i].type1=gas;
    fscanf(myfile,"%d%1.1f%d%s%s%s%d",&(p_car[i].eng1.g_eng.h_pow),&(p_car[i].eng1.g_eng.vol), kpp+i,p_car[i].mark, p_car[i].model, p_car[i].body,&(p_car[i].year));
    switch(kpp[i])
        {
            case akpp: p_car[i].eng1.g_eng.Gkpp=akpp;
            break;
            case mkpp: p_car[i].eng1.g_eng.Gkpp=mkpp;
            break;
            case variator: p_car[i].eng1.g_eng.Gkpp=variator;
            break;
            case robot: p_car[i].eng1.g_eng.Gkpp=robot;
            break;
            default: printf("Invalid information in file with car ", i);
            exit(EXIT_FAILURE);
			system("Pause");
         }
break;

case 3: p_car[i].type1=electric;
    fscanf(myfile,"%d%d%s%s%s%d",&(p_car[i].eng1.Eeng.el_pow),&(p_car[i].eng1.Eeng.k_moment),p_car[i].mark,p_car[i].model,p_car[i].body,&(p_car[i].year));

break;
	default: printf("Smth going wrong in car ",i );
		exit(EXIT_FAILURE);
	fscanf (myfile, "%d", (c+i));//schitivanie enum eng_type
	printf("%d",c[i]);

	printf("\n%d\n",ftell(myfile));

switch(c[i])
    {
case 1: p_car[i].type1=diesel;
   if( fscanf(myfile," %d %1.1f %d %s %s %s %d",&(p_car[i].eng1.d_eng.k_moment), &(p_car[i].eng1.d_eng.vol), kpp+i, p_car[i].mark,p_car[i].model,p_car[i].body,&(p_car[i].year)) < 0)
	   printf("fscanf error");
	printf(" %d %1.1f %d %s %s %s %d\n",p_car[i].eng1.d_eng.k_moment,p_car[i].eng1.d_eng.vol, kpp[i], p_car[i].mark , p_car[i].model,p_car[i].body, p_car[i].year);

    switch(kpp[i])
        {
            case akpp: p_car[i].eng1.d_eng.Dkpp=akpp;
            break;
            case mkpp: p_car[i].eng1.d_eng.Dkpp=mkpp;
            break;
            case variator: p_car[i].eng1.d_eng.Dkpp=variator;
            break;
            case robot: p_car[i].eng1.d_eng.Dkpp=robot;
            break;
            default: printf("Invalid information in file with car ", i);
			   system("Pause");
				exit(EXIT_FAILURE);

         }
break;

case 2: p_car[i].type1=gas;
    fscanf(myfile,"%d%1.1f%d%s%s%s%d",&(p_car[i].eng1.g_eng.h_pow),&(p_car[i].eng1.g_eng.vol), kpp+i,p_car[i].mark, p_car[i].model, p_car[i].body,&(p_car[i].year));
    switch(kpp[i])
        {
            case akpp: p_car[i].eng1.g_eng.Gkpp=akpp;
            break;
            case mkpp: p_car[i].eng1.g_eng.Gkpp=mkpp;
            break;
            case variator: p_car[i].eng1.g_eng.Gkpp=variator;
            break;
            case robot: p_car[i].eng1.g_eng.Gkpp=robot;
            break;
            default: printf("Invalid information in file with car ", i);
            exit(EXIT_FAILURE);
			system("Pause");
         }
break;

case 3: p_car[i].type1=electric;
    fscanf(myfile,"%d%d%s%s%s%d",&(p_car[i].eng1.Eeng.el_pow),&(p_car[i].eng1.Eeng.k_moment),p_car[i].mark,p_car[i].model,p_car[i].body,&(p_car[i].year));

break;
	default: printf("Smth going wrong in car ",i );
		exit(EXIT_FAILURE);
    }*/

    	//fscanf (myfile, "%d", (c+i));
    	fread((c+i),sizeof(int),1,myfile);//schitivanie enum eng_type

switch(c[i])
    {
case 1: p_car[i].type1=diesel;
   //if( fscanf(myfile," %d %1.1f %d %s %s %s %d",&(p_car[i].eng1.d_eng.k_moment), &(p_car[i].eng1.d_eng.vol), kpp+i, p_car[i].mark,p_car[i].model,p_car[i].body,&(p_car[i].year)) < 0)
	  // printf("fscanf error");
	//printf(" %d %1.1f %d %s %s %s %d\n",p_car[i].eng1.d_eng.k_moment,p_car[i].eng1.d_eng.vol, kpp[i], p_car[i].mark , p_car[i].model,p_car[i].body, p_car[i].year);
    fread(&(p_car[i].eng1.d_eng.k_moment),sizeof(int),1,myfile);
    fread(&(p_car[i].eng1.d_eng.vol),sizeof(float),1,myfile);
    fread(kpp+i,sizeof(int),1,myfile);
    fread(p_car[i].mark,sizeof(char),20,myfile);
    fread(p_car[i].model,sizeof(char),20,myfile);
    fread(p_car[i].body,sizeof(char),20,myfile);
    fread(&p_car[i].year,sizeof(int),1,myfile);
    switch(kpp[i])
        {
            case akpp: p_car[i].eng1.d_eng.Dkpp=akpp;
            break;
            case mkpp: p_car[i].eng1.d_eng.Dkpp=mkpp;
            break;
            case variator: p_car[i].eng1.d_eng.Dkpp=variator;
            break;
            case robot: p_car[i].eng1.d_eng.Dkpp=robot;
            break;
            default: printf("Invalid information in file with car ", i);
			   system("Pause");
				exit(EXIT_FAILURE);

         }
break;

case 2: p_car[i].type1=gas;
    //fscanf(myfile,"%d%1.1f%d%s%s%s%d",&(p_car[i].eng1.g_eng.h_pow),&(p_car[i].eng1.g_eng.vol), kpp+i,p_car[i].mark, p_car[i].model, p_car[i].body,&(p_car[i].year));
    fread(&(p_car[i].eng1.g_eng.h_pow),sizeof(int),1,myfile);
    fread(&(p_car[i].eng1.g_eng.vol),sizeof(float),1,myfile);
    fread(kpp+i,sizeof(int),1,myfile);
    fread(p_car[i].mark,sizeof(char),20,myfile);
    fread(p_car[i].model,sizeof(char),20,myfile);
    fread(p_car[i].body,sizeof(char),20,myfile);
    fread(&p_car[i].year,sizeof(int),1,myfile);
    switch(kpp[i])
        {
            case akpp: p_car[i].eng1.g_eng.Gkpp=akpp;
            break;
            case mkpp: p_car[i].eng1.g_eng.Gkpp=mkpp;
            break;
            case variator: p_car[i].eng1.g_eng.Gkpp=variator;
            break;
            case robot: p_car[i].eng1.g_eng.Gkpp=robot;
            break;
            default: printf("Invalid information in file with car ", i);
            exit(EXIT_FAILURE);
			system("Pause");
         }
break;

case 3: p_car[i].type1=electric;
    //fscanf(myfile,"%d%d%s%s%s%d",&(p_car[i].eng1.Eeng.el_pow),&(p_car[i].eng1.Eeng.k_moment),p_car[i].mark,p_car[i].model,p_car[i].body,&(p_car[i].year));
    fread(&(p_car[i].eng1.Eeng.el_pow),sizeof(int),1,myfile);
    fread(&(p_car[i].eng1.Eeng.k_moment),sizeof(int),1,myfile);
    fread(p_car[i].mark,sizeof(char),20,myfile);
    fread(p_car[i].model,sizeof(char),20,myfile);
    fread(p_car[i].body,sizeof(char),20,myfile);
    fread(&p_car[i].year,sizeof(int),1,myfile);
break;
	default: printf("\nSmth going wrong in car %d\n",i );
        system("Pause");
		exit(EXIT_FAILURE);
    }

    i++;
}
    fclose(myfile);
}
