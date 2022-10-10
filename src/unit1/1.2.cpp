#include<stdio.h>
void excercise0102_main(void)
{
	int i, *wsk;
	int T[10];
	wsk=T;
	for(i=0;i<10;i++)
	{
		*wsk = i;
		printf("%i = %i\n", i, *wsk);
		wsk++;
	}
}
