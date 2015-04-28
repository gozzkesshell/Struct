/*Программа для заполнения структуры связвнной с автомобилями
В данном файле содержатся ф-и main и Output(принимает один экземпляр объекта типа кар)
А так же служебная функция очищения файла
Инициализация массива структур и и выделение под неё памяти происходит тоже в мэйн

*/

#include <stdio.h>
#include <stdlib.h>
#include "struct_keeper.h"
#include "Prototypes.h"



int main()
{
    int i;
    int *SearcResult;
    car *my_car;//екземпляр


    my_car=(car *)malloc(N*sizeof(car));


    SearcResult=(int *)malloc(N*sizeof(int));
mainInputSwtch:
    printf("\nChoose how to full up database: 1 - by hand, 2 - from file ");
    scanf("%d",&i);
    switch(i)
    {
        case 1: for(i=0;i<N;i++)
			{
				printf("\nInput the car number %d",i);
				HandInput(&(my_car[i]));
			}//chtoby ne peredelyvat HandInput,kotoraya prinimaet ukazatel
				break;

        case 2: FileInput(my_car);
				break;
        default: printf("Invalid choose, Plz retry");
			goto mainInputSwtch;
    }

        i=0;
	mainSerachSwtch:
        printf("\nChoose: \n 1 - serch by mark, model or body \n 2 - search by engine type \n 3- search by year \n 4 - clear the file wth structure \n output structure - 5 \n 0 - exit\n");
		scanf("%d",&i);
        switch(i)
        {
			case 1:	StringSearch(my_car, SearcResult);
					for (i = 0; i < N; i++)
					{ if(SearcResult[i]!= 0)
					Output(my_car[i]);}
					goto mainSerachSwtch;
						break;

            case 2: EngineSearch(my_car,SearcResult);
					for (i = 0; i < N; i++)
					{ if(SearcResult[i]!= 0)
					Output(my_car[i]); 
					goto mainSerachSwtch;
						break;

			case 3: YearSearch(my_car, SearcResult);
					for (i = 0; i < N; i++)
					{ if(SearcResult[i]!= 0)
					Output(my_car[i]);}
					goto mainSerachSwtch;
						break;

			case 0: system("Pause");
					exit(EXIT_SUCCESS);

			case 4: Clear();
					goto mainSerachSwtch;
						break;

			case 5: printf("Input the number of car to see the information about it");
					scanf("%d",&i);
					Output(my_car[i]);
					goto mainSerachSwtch;

            default: printf("\nInvalid choose,PLz rerty");
				goto mainSerachSwtch;
        }



		system("Pause");
        return 0;
	}
}

void Clear()
{
	FILE *myfile;
	if((myfile=fopen("Cars.txt","w+")) == NULL)
        perror("File Error");
	

}

void Output(car TheCar)
{

    printf("The mark is %s\n", TheCar.mark);
    printf("\nThe model is %s\n",TheCar.model);
    printf("\nThe body is %s\n",TheCar.body);
    printf("The year of car is %d\n",TheCar.year);
    switch(TheCar.type1)
    {
        case gas : printf("\nThe car has a gas engine \n");
        printf("\nThe volume of engine is %f\n",TheCar.eng1.g_eng.vol);
        printf("\nThe power of engine in horsepow is %d \n",TheCar.eng1.g_eng.h_pow);
        switch(TheCar.eng1.g_eng.Gkpp)
        {
            case akpp: printf("The car has a authomatic transmission\n");
            break;
            case mkpp: printf("The car has a mechanic transmission\n");
            break;
            case variator: printf("The car has a variator transmission\n ");
            break;
            case robot: printf("The car has a robotic transmission\n");
            break;
        }
        break;

        case diesel: printf("\nThe car has a diesel engine ");
        printf("\nThe volume of engine is %lf",TheCar.eng1.d_eng.vol);
        printf("\nThe k_moment of engine in N*m is %lf",TheCar.eng1.d_eng.k_moment);
        switch(TheCar.eng1.d_eng.Dkpp)
        {
            case akpp: printf("\nThe car has a authomatic transmission");
            break;
            case mkpp: printf("\nThe car has a mechanic transmission");
            break;
            case variator: printf("\nThe car has a variator transmission");
            break;
            case robot: printf("\nThe car has a robotic transmission");
            break;
        }
        break;

        break;
        case electric: printf("\nThe car has a electric engine ");
        printf("\nIt has a power in KW: %d",TheCar.eng1.Eeng.el_pow);
        printf("\nIt has a k_moment in N*m: %d",TheCar.eng1.Eeng.k_moment);
        break;
    }

}
