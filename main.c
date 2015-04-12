/*Программа для заполнения структуры связвнной с автомобилями
В данном файле содержатся ф-и main и Output(принимает один экземпляр объекта типа кар)
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

    printf("\nChoose how to full up database: 1 - by hand, 2 - from file");
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
    }
	
        i=0;
        printf("\nChoose: \n 1 - serch by mark, model or body \n 2 - search by engine type \n3- search by year\n");
		scanf("%d",&i);
        switch(i)
        {
			case 1:	StringSearch(my_car, SearcResult);
				for (i = 0; i < N; i++)
				{ if(SearcResult[i]==NULL)
				Output(my_car[i]);}
						break;

            case 2: EngineSearch(my_car,SearcResult);
					for (i = 0; i < N; i++)
					{ if(SearcResult[i]==NULL)
					Output(my_car[i]);}
						break;
            
			case 3: YearSearch(my_car, SearcResult);
					for (i = 0; i < N; i++)
					{ if(SearcResult[i]==NULL)
					Output(my_car[i]);}
						break;
                     
            default: printf("Invalid choose,PLz rerty");
        }



	
		system("Pause");
        return 0;
}

void Output(car TheCar)
{

    printf("The mark is %s", TheCar.mark);
    printf("\nThe model is %s",TheCar.model);
    printf("\nThe body is %s",TheCar.body);
    printf("The year of car is %d",TheCar.year);
    switch(TheCar.type1)
    {
        case gas : printf("\nThe car has a gas engine ");
        printf("\nThe volume of engine is %f",TheCar.eng1.g_eng.vol);
        printf("\nThe power of engine in horsepow is%d",TheCar.eng1.g_eng.h_pow);
        switch(TheCar.eng1.g_eng.Gkpp)
        {
            case akpp: printf("The car has a authomatic transmission");
            break;
            case mkpp: printf("The car has a mechanic transmission");
            break;
            case variator: printf("The car has a variator transmission");
            break;
            case robot: printf("The car has a robotic transmission");
            break;
        }
        break;

        case diesel: printf("\nThe car has a diesel engine ");
        printf("\nThe volume of engine is %lf",TheCar.eng1.d_eng.vol);
        printf("\nThe k_moment of engine in N*m is%lf",TheCar.eng1.d_eng.k_moment);
        switch(TheCar.eng1.d_eng.Dkpp)
        {
            case akpp: printf("The car has a authomatic transmission");
            break;
            case mkpp: printf("The car has a mechanic transmission");
            break;
            case variator: printf("The car has a variator transmission");
            break;
            case robot: printf("The car has a robotic transmission");
            break;
        }
        break;

        break;
        case electric: printf("\nThe car has a electric engine ");
        printf("It has a power in KW:%d",TheCar.eng1.Eeng.el_pow);
        printf("It has a k_moment in N*m:%d",TheCar.eng1.Eeng.k_moment);
        break;
    }

}
