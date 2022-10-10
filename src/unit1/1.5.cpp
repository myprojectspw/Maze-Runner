#include<stdio.h>

int C[]={16909060, 84281096, 151653132};

void excercise0105_main(void)
{
	unsigned char *wsk = (unsigned char*)C;
	int i;
	printf("[Bajty] = Wartosci bajtow\n");
	for(i=0;i<12;i++) 
	{	
		printf("A[%d] = %d\n", i+1, wsk[i]);
		if((i+1)%4==0) printf("\n");
	}
	printf("Bedzie 12 bajtow, ich wartosci to: 4 3 2 1, 8 7 6 5, 12 11 10 9");
}
