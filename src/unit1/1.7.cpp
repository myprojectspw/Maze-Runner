#include<stdio.h>

int B[]={16909060, 84281096, 151653132, -1};

void excercise0107_main(void)
{
	int i = 0, liczba = 0;
	while(1)
	{
		if(B[i] == -1) break;
		liczba++;
		i++;
	}	
	printf("Wynosi: %i", liczba);
}
