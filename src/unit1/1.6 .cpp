#include<stdio.h>

int A[]={16909060, 84281096, 151653132};

void excercise0106_main(void)
{
	unsigned char *wsk = (unsigned char*)A;
	int i;
	for(i=0;i<12;i++) 
	{	
		if(wsk[i]>=4 && wsk[i]<=7)	printf("%p\n", &wsk[i]);
	}
}
