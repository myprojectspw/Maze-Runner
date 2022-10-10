#include<stdio.h>
#include<stdlib.h>
#include <time.h> 
#define a 1
#define b 10
void excercise0103_main(void)
{
	double i, *wsk, s;
	double T[100];
	srand(time(NULL));
	wsk=T;
	printf("%i\n", wsk);
	for(i=0;i<100;i++)
	{
		*wsk = rand()%(b+a);
		printf("%g = %g\n", i, *wsk);
		wsk++;
	}
	wsk=T;
	s=0;
	for(i=0;i<100;i++)
	{
		s+=*wsk;
		wsk++;
	}
	printf("Suma = %g Srednia = %g",s, s/100);
	printf("\n\n");
}
