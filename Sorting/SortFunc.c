#include "Header.h"

void swap(int *arr, int num1, int num2) {
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
	return;
}

void Quicksort(int *arr, int first, int last) {
	if (first < last)
	{
		int left = first, right = last, middle = arr[(left + right) / 2];
		do
		{
			while (arr[left] < middle) left++;
			while (arr[right] > middle) right--;
			if (left <= right)
			{
				swap(arr, left, right);
				left++;
				right--;
			}
		} while (left <= right);
		Quicksort(arr, first, right);
		Quicksort(arr, left, last);
	}
	return;
}

void Shellsort(int *arr, int n) {
	int gap, i, temp, j;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i += 1) {
			temp = arr[i];
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return;
}

void Insertionsort(int *arr, int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	return;
}

void Bubblesort(int *arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
	return;
}

void Countingsort(int *arr, int n) {
	int *count, m, i, j, k=0, min, max;
	count = NULL;
	min = max = arr[0];
	for (i = 0; i < n; i++)
		if (arr[i] < min) min = arr[i];
	else if (arr[i] > max) max = arr[i];
	m = max - min + 1;

	count = (int *)calloc(m, sizeof(int));
	if (count == NULL) return;

	for (i = 0; i < n; i++)
		count[arr[i] - min]++;
	for (i = 0; i < m; i++)
		for (j = 0; j < count[i]; j++)
			arr[k++] = i + min;
	free(count);
	return;
}