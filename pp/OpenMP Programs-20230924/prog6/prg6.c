#include<stdio.h>
#include<omp.h>
int main()
{
#pragma omp parallel for schedule(static,3) 
	for (int i = 0; i < 24; i++)
	{
		printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
	}
	return 0;
}
