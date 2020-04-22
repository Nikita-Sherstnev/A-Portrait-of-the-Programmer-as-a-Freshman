#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define PF printf
#define SC scanf
#define MAX 100

void task1(int nsort); 
void task2(int nsort);
void task3(); 
void task4(int nsort);

void swap(int *arr, int num1, int num2);
void Quicksort(int *arr, int first, int last);
void Insertionsort(int *arr, int n);
void Shellsort(int *arr, int n);
void Bubblesort(int *arr, int n);
void Countingsort(int *arr, int n);