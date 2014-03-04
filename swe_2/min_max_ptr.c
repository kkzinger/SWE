//Filename: min_max_ptr.c
//Author: G. Katzinger


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define STD_SIZE 10

void rand_arr(int *arr,unsigned int size)
{
	int i;
	printf("%d\n", size);
	srand(time(NULL));
	for(i=0;i<size;i++)
	{
		arr[i]=rand()%100;
	}
}

void min_max_val_pos(int *arr, int size, int *min_pos, int *max_pos, int *min_val, int *max_val)
{
	int i; 
	int *ptr_min, *ptr_max;

	*min_pos = 0;
	*min_val = *arr;
	*max_pos = 0;
	*max_val = *arr;
	ptr_min = arr;
	ptr_max = arr;

	for(i=1;i<size;i++)
	{
		if(*(arr+i) < *ptr_min)
		{
			ptr_min = arr+1;
			*min_val = *(arr+i);
		}

		if(*(arr+i) > *ptr_max)
		{

			ptr_max = arr+1;
			*max_val = *(arr+i);
		}
	}



}

void print_all(int *arr, int size, int min_pos, int max_pos, int min_val, int max_val)
{
	int i;
	printf("------------------------------\n");
	for(i=0;i<size;i++)
	{
		printf("Pos. [%d] -- %d\n", i, arr[i]);
	}
	printf("Min_Pos %6d Min_Val %6d Max_Pos %6d Max_Val %6d\n",min_pos, min_val, max_pos, max_val);
	printf("------------------------------\n");

}

int main(int argc, char *argv[])
{

	int min_val, max_val;
	unsigned int min_pos, max_pos, arr_size;
	int *arr;

	printf("------------%d\n",argc);

	if(argc > 1)
	{
		arr_size = strtol(argv[1],0,10);
	}
	else
	{
		arr_size = STD_SIZE;
	}

	arr = (int*) malloc(arr_size * sizeof(int));

	if(arr == NULL)
	{
		fprintf(stderr,"Could not allocate memory");
		return EXIT_FAILURE;
	}

	rand_arr(arr,arr_size);
	min_max_val_pos(arr, arr_size, &min_pos, &max_pos, &min_val, &max_val);

	print_all(arr, arr_size, min_pos, max_pos, min_val, max_val);

	return EXIT_SUCCESS;
}

