#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* countingSort(int* array, int arraySize, int rangeSize)
{
	int* countArray = (int*) malloc(sizeof(int) * rangeSize);
	if (countArray)
	{
		memset(countArray, 0, sizeof(int) * rangeSize);
		for (int i = 0; i < arraySize; i++)
		{
			countArray[array[i]]++;
		}
		for (int i = 1; i < rangeSize; i++)
		{
			countArray[i] = countArray[i] + countArray[i - 1];
		}
		for (int i = rangeSize - 1; i > 0; i--)
		{
			countArray[i] = countArray[i - 1];
		}
		countArray[0] = 0;

		int* resultArray = (int*) malloc(sizeof(int) * arraySize);
		if (resultArray)
		{
			memset(resultArray, 0, sizeof(int) * arraySize);
			for (int i = 0; i < arraySize; i++)
			{
				int index = countArray[array[i]];
				resultArray[index] = array[i];
				countArray[array[i]]++;
			}
			free(countArray);
			return resultArray;
		}
		free(countArray);
		return NULL;
	}
}

int main(void)
{
	int rangeSize = 4;
	int array[] = {2, 3, 0, 3, 1, 1, 2, 2};
	int arraySize = sizeof(array) / sizeof(array[0]);

	int* result = countingSort(array, arraySize, rangeSize);

	for (int i = 0; i < arraySize; i++)
	{
		printf("%d ", result[i]);
	}

	return 0;
}