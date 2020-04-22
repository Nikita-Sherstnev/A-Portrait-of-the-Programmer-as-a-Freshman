#include "Header.h"

/*Линейные алгоритмы*/
double task1func(double x, double y)
{
	return ((cos(x) / (3.14 - 2 * x)) + 16 * x * cos(x * y));
}

int task1(void)
{
	double x, y;
	PF("Input x,y: ");
	scanf("%lf%lf", &x, &y);
	PF("Result f=%f \n", task1func(x, y));
	return 0;
}

int task2func(float a, float b, float c)
{
	if ((a == b) && (a == c) && (b == c))
	{
		return 1;
	}
	else if ((a == b) || (a == c) || (b == c))
	{
		return 2;
	}
	else {
		return 3;
	}
}

int task2(void)
{
	float a, b, c;
	PF("Введите стороны треугольника: ");
	scanf("%f%f%f", &a, &b, &c);

	if (task2func(a, b, c) == 1)
	{
		PF("Треугольник равностронний\n");
	}
	else if (task2func(a, b, c) == 2)
	{
		PF("Треугольник равнобедренный\n");
	}
	else {
		PF("Треугольник не равнобедренный\n");
	}
	return 0;
}

int task3func(int y)
{
	int x, z, a;
	x = (y / 100) * 10;
	z = y % 100;
	a = z % 10;
	z = ((y / 10) % 10) * 100;
	x = z + x + a;
	return x;
}

int task3(void)
{
	int x, y = 0;
	PF("\nEnter the y: ");
	scanf("%d", &y);
	x = (y % 100) / 10;
	if (x == 0) {
		PF("Invalid y\n");
	}
	else if ((y<100) || (y>999)) {
		PF("Invalid y\n");
	}
	else {
		PF("%d", task3func(y));
	}
	return 0;
}


/* Разветвляющиеся алгоритмы*/
double task4func1(double x)
{
	return 2*cos(x)+3*x*x+0.75;
}

double task4func2(double x)
{
	return log(fabs(sin(2 * x)));
}

int task4(void)
{
	double x = 0;
	PF("Enter x: ");
	scanf_s("%lf", &x);
	if (x <= 3) {
		PF("Result z=%lf\n", task4func1(x));
	}
	else {
		PF("Result z=%lf\n", task4func2(x));
	}
	return 0;
}

const char* task5func(int x)
{
	static char a1[15], a2[15], a3[15], a4[15], a5[15], a6[15], a7[15];
	printf("Enter seven words: ");
	scanf("%s%s%s%s%s%s%s", a1, a2, a3, a4, a5, a6, a7);
	switch (x) {
	case 1: return a1; break;
	case 2: return a2; break;
	case 3: return a3; break;
	case 4: return a4; break;
	case 5: return a5; break;
	case 6: return a6; break;
	case 7: return a7; break;
	default: return "This number does not exist.";
	}
}

int task5(void)
{
	int x = 0;
	printf("Enter the number: ");
	scanf("%d", &x);
	const char* b = task5func(x);
	printf("%s\n", b);
	return 0;
}

int task6func(int a, int b, int c, int d)
{
	if ((a < c && b < d) || (a < d && b < c))
		return 1;
	return 0;
}

int task6(void)
{
	int a = 0, b = 0, c = 0, d = 0;
	PF("Enter the sides of first rectangle (a,b): ");
	scanf("%d%d", &a, &b);
	PF("Enter the sides of second rectangle (c,d): ");
	scanf("%d%d", &c, &d);
	if (task6func(a, b, c, d))
		PF("Yes\n");
	else
		PF("No\n");
	return 0;
}


/*Циклические алгоритмы*/
double task7func(int N)
{
	double s = 0;
	for (int k = 2; k <= N; k++)
		s = s + log((1 + k)*(1 + k));
	return s;
}

int task7(void)
{
	int N = 0;
	printf("Введите N: ");
	scanf("%d", &N);
	PF("Сумма=%lf\n", task7func(N));
	return 0;
}

void task8func(void)
{
	int n, x, n1 = 0, i = 0;
	printf("Введите число: ");
	scanf("%d", &n);
	do {
		x = n % 10;
		if (x != 0 && x != 5)
			n1 = n1 + x*pow(10, i++);
	} while ((n /= 10) > 0);
	PF("%d\n", n1);
}

int task8(void)
{
	task8func();
	return 0;
}

float task9func(float x, float e)
{
	float y0, y1, y2;
	int n = 0;
	y0 = 0.1;
	y1 = x - 1;
	do
	{
		y2 = (x - 1)*y1 - (3 * x - 2)*y0;
		y0 = y1;
		y1 = y2;
		++n;
	} while ((y2 - y0) >= e && n <= 10);
	return y2;
}

int task9(void)
{
	float x, e;
	printf("Введите x, e: ");
	scanf("%f%f", &x, &e);
	printf("Искомый член: %.4f\n", task9func(x, e));
	return 0;
}


/* Одномерные масссивы*/
void task10(void)
{
	int num = 0, i = 0, k = 0, *arr;
	PF("Введите количество элементов в массиве: ");
	scanf("%d", &num);
	arr = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	for (i; i <= num - 1; i++)
	{
		arr[i] = rand() % 21;
		PF("%d ", arr[i]);
	}
	for (i = 0; i <= num - 2; i++)
		if (arr[i] % arr[i + 1] == 0)
			++k;
	PF("\nКратных элементов: %d\n", k);
	free(arr);
}

void task11(void)
{
	int num = 0, i = 0, *arr;
	printf("Введите количество элементов в массиве: ");
	scanf("%d", &num);
	arr = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	for (i; i <= num - 1; i++)
	{
		arr[i] = rand() % 11;
		printf("%d ", arr[i]);
	}
	for (i = 0; i <= num - 2; i++)
		if (arr[i] > arr[i + 1])
		{
			printf("\nНет\n");
			exit(0);
		}
	printf("\nДа\n");
	free(arr);
}

/* Двумерные массивы */

int task12(void)
{
	int **arr, **arr2, i, j, n, max;
	printf("Введите размер квадратной матрицы: ");
	scanf("%d", &n);

	arr = (int**)malloc(n * sizeof(int*)); // Выделение памяти для массива
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(n * sizeof(int));

	arr2 = (int**)malloc(n * sizeof(int*)); // Выделение памяти для второго массива
	for (i = 0; i < n; i++)
		arr2[i] = (int*)malloc(n * sizeof(int));

	srand(time(0)); // Заполнение массива
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < n; i++) // Нахождение максимального элемента в каждой строке
	{
		max = arr[i][0];
		for (j = 0; j < n - 1; j++)
		{
			if (max < arr[i][j + 1])
				max = arr[i][j + 1];
		}
		j = 0;
		arr2[i][j] = max;
		printf("%3d\n", max);
	}
	for (i = 0; i < n; i++) // Освобождение памяти
		free(arr[i]);
	free(arr);

	for (i = 0; i < n; i++) // Освобождение памяти 2
		free(arr2[i]);
	free(arr2);
	return 0;
}

int task13(void)
{
	int **arr, i, j, n, k = 0;
	printf("Введите размер квадратной матрицы: ");
	scanf("%d", &n);

	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(n * sizeof(int));

	srand(time(0));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 == 1 || (arr[i][j] / 2) % 2 == 0)
			{
				k = 0;
				break;
			}
			k++;
		}
	}
	k == n ? printf("\nДа\n") : printf("\nНет\n");
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	return 0;
}

/* Cтроки */

int task14(void)
{
	char str[100] = { 0 };
	char str2[200] = { 0 };
	int i, j = 0;
	do { i = getchar(); } 
	while (i != '\n' && i != EOF);
	fgets(str, 100, stdin);
	for (i = 0; i < 100; i++)
	{
		str2[j] = str[i];
		str2[j + 1] = str[i];
		j += 2;
	}
	printf("%s\n", str2);
	return 0;
}

int task15(void)
{
	char str[100] = { 0 }, str2[100] = { 0 }, word[100] = { 0 };
	int i, j = 0, t, k = 0, words = 0, max = 0;
	do { i = getchar(); } 
	while (i != '\n' && i != EOF);
	fgets(str, 100, stdin);
	for (i = 0; i <= strlen(str); i++)
	{
		if (str[i]>'A' && str[i]<'Z') str[i] += 'z' - 'Z';
		if ((str[i] == ' ') || (i == (strlen(str))))
		{
			word[j++] = ' ';
			for (t = 0; t < j; t++)
				if (word[t] > word[max])
					max = t;
			if (max < 2)
				k = -1;
			for (t = 0; t < max - 1; t++)
			{
				if (word[t] > word[t + 1])
					break;
				k++;
			}
			if (k == (max - 1))
				words++;
			else strcat(str2, word);
			j = 0;
			k = 0;
			memset(word, 0, sizeof(word));
			max = 0;
		}
		else
			word[j++] = str[i];
	}
	if (words == 0)
		PF("No\n");
	else PF("%s\n", str2);
	return 0;
}

