#include<stdio.h>

void excercise0101_main()
{
	int p = 3, k = 20, i = 90;
	int *ip = &p; 
	int *ik = &k;
	int *ii = &i;
	*ip = *ip + 3;
	*ik = *ik - 8;
	*ii = *ii / 2;
	printf("%i %i %i", *ip, *ik, *ii);
}
