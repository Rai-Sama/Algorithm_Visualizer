#include "GL/freeglut.h"
#include "GL/gl.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <unistd.h>
void randomizeArray(int* arr, int length)
{
	for(int i = length - 1; i > 0; --i)
	{
		std::swap(arr[i], arr[rand() % (i+1)]);
	}
}

void printArray(int* arr, int length)
{
	for(int i = 0; i < length; ++i)
	{
		printf("%i", arr[i]);

		if(i < length - 1)
		{
			printf(",");
		}
	}

	printf("\n");
}
