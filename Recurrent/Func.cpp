#include <assert.h>

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

#include "Header.h"

double Ger(int a, int n)
{
	if (n == 0) return 200;
	else return (Ger(a, n - 1) + a / Ger(a, n - 1)) / 2;
}

int task1(void)
{
	int a, b, c;
	printf("Введите три числа: \n");
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= 10; i++)
		printf("№%d.  %.15lf %.15lf %.15lf\n", i, Ger(a, i), Ger(b, i), Ger(c, i));
	system("pause");
	return 0;
}

long long int Fib(int n)
{
	int a = 1, ta,
		b = 1, tb,
		c = 1, rc = 0, tc,
		d = 0, rd = 1;

	while (n)
	{
		if (n & 1)    // Если степень нечетная
		{
			// Умножаем вектор R на матрицу A
			tc = rc;
			rc = rc*a + rd*c;
			rd = tc*b + rd*d;
		}

		// Умножаем матрицу A на саму себя
		ta = a; tb = b; tc = c;
		a = a*a + b*c;
		b = ta*b + b*d;
		c = c*ta + d*c;
		d = tc*tb + d*d;

		n >>= 1;  // Уменьшаем степень вдвое

	}
	return rc;
}

int task2(void) {
	int a, b, c, d , e;
	PF("Введите номера пяти чисел Фибоначчи: ");
	SC("%d%d%d%d%d", &a, &b, &c, &d, &e);
	if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0) {
		PF("Номера должны быть не меньше нуля!\n");
		system("pause");
		return 0;
	}
	PF("F(%d)=%lli\n", a, Fib(a));
	PF("F(%d)=%lli\n", b, Fib(b));
	PF("F(%d)=%lli\n", c, Fib(c));
	PF("F(%d)=%lli\n", d, Fib(d));
	PF("F(%d)=%lli\n", e, Fib(e));
	system("pause");
	return 0;
}

int Soch(int n, int m, int *p)
{
	++*p;
	if (m < 0 || m > n) return 0;
	if (n == m || m == 0) return 1;
	else return (Soch(n-1, m, p)+Soch(n-1, m-1, p));
}

int task3(void) {
	int n, m1, m2, m3, m4, m5, count = 0, *p;
	p = &count;
	PF("Введите значение N: ");
	SC("%d", &n);
	PF("Введите 5 значений M: ");
	SC("%d%d%d%d%d", &m1, &m2, &m3, &m4, &m5);
	if (0 <= m1 || m1 <= n || 0 <= m2 || m2 <= n || 0 <= m3 || m3 <= n || 0 <= m4 || m4 <= n || 0 <= m5 || m5 <= n)
	{
		PF("C(%d,%d)=%d\n", n, m1, Soch(n, m1, p));
		PF("Кол - во рекурсивных вызовов: %d\n", count);
		count = 0;
		PF("C(%d,%d)=%d\n", n, m2, Soch(n, m2, p));
		PF("Кол - во рекурсивных вызовов: %d\n", count);
		count = 0;
		PF("C(%d,%d)=%d\n", n, m3, Soch(n, m3, p));
		PF("Кол - во рекурсивных вызовов: %d\n", count);
		count = 0;
		PF("C(%d,%d)=%d\n", n, m4, Soch(n, m4, p));
		PF("Кол - во рекурсивных вызовов: %d\n", count);
		count = 0;
		PF("C(%d,%d)=%d\n", n, m5, Soch(n, m5, p));
		PF("Кол - во рекурсивных вызовов: %d\n", count);
		count = 0;
	}
	else {
		PF("Неверные значения!");
		return 0;
	}
	system("pause");
	return 0;
}

int NOD(int a, int b)
{
	if (a == 0) return b;
	else return NOD(b % a, a);
}

int task4(void)
{
	int a, b, c, d;
	PF("Введите 4 числа: ");
	SC("%d%d%d%d", &a, &b, &c, &d);
	PF("НОД %d и %d = %d\n", a, b, NOD(a, b));
	PF("НОД %d и %d = %d\n", a, c, NOD(a, c));
	PF("НОД %d и %d = %d\n", a, d, NOD(a, d));
	system("pause");
	return 0;
}

int Sum(int n)
{
	if (n < 1) return 0;
	if (n == 1) return 1;
	else return n+Sum(n-1);
}

int task5(void) {
	int n, k;
	PF("Введите n и k: ");
	SC("%d%d", &n, &k);
	PF("%d\n", Sum(2*n)+Sum(k));
	system("pause");
	return 0;
}

int Draw(unsigned int l, int i, int j)
{
	if (j > i) return PF("\n");
	PF("%c", l);
	Draw(l, i, ++j);
}

int task6(void) {
	for (int i = 0; i < 7; i++)
	{
		if (i < 4)
		{
			Draw(65 + i, 20 - i * 5, 0);
			PF("  ");
			if (i == 1) PF("  ");
			if (i == 2) PF("    ");
			if (i == 3) PF("  ");
		}
		else
		{
			Draw(68 - i + 3, 5 + (i-3) * 5, 0);
			if (i == 4) PF("  ");
		}
	}
	system("pause");
	return 0;
}

int Reverse(int n)
{
	if (n == 0) return 0;
	PF("%d", n%10);
	return Reverse(n / 10);
}

int task7(void) {
	int a, b;
	PF("Введите границы интервала: ");
	SC("%d%d", &a, &b);
	for (a; a <= b; a++)
	{
		Reverse(a);
		PF("\n");
	}
	system("pause");
	return 0;
}

int FindPrimes(int n)
{
	int i, k=0;
	if (n == 0) return 0;
	for (i = 2; i < n; i++)
		if (n % i == 0) k++;
	if (k == 0) PF("%d\n", n);
	k = 0;
	return FindPrimes(n-1);
}

int task8(void) {
	int n;
	PF("Введите n: ");
	SC("%d", &n);
	FindPrimes(n);
	system("pause");
	return 0;
}

int Chislo(int n, int k)
{
	if (k == -1) return 0;
	PF("%d ", n / int(pow(10,k)));
	return Chislo(n % int(pow(10,k)), k - 1);
}

int task9(void) {
	int n, count, k=0;
	PF("Введите число: ");
	SC("%d", &n);
	count = n;
	while (count != 0)
	{
		count /= 10;
		k++;
	}
	Chislo(n,k-1);
	k = 0;
	system("pause");
	return 0;
}

int Dvoich(int n, int *p, int count)
{
	if (n == 0) return 0;
	if (n & 1) *p += 1*pow(10, count);
	count++;
	return Dvoich(n >>= 1, p, count);
}

int task10(void) {
	int n = 0, num = 0, count = 0;
	int *p;
	p = &num;
	PF("Введите число: ");
	SC("%d", &n);
	Dvoich(n, p, count);
	PF("В двоичной системе: %d\n", num);
	system("pause");
	return 0;
}

int Max(int *a, int n, int *p)
{
	if (n == 0) return 0;
	if (*a > *p) *p = *a;
	Max(a + 1, n - 1, p);
}

int task11(void) {
	int n=0, max = 0, *p;
	int* arr;
	p = &max;
	PF("Введите кол-во элементов в массиве: ");
	SC("%d", &n);
	arr = (int*) malloc(n * sizeof(int));
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		PF("%d ", *(arr+i));
	}
	PF("\n");
	Max(arr, n, p);
	PF("Максимальный элемент массива: %d\n", max);
	system("pause");
	return 0;
}

int Min(int *a, int n, int *p) {
	if (n == 0) return 0;
	if (*a < *p) *p = *a;
	Min(a + 1, n - 1, p);
}

int task12(void) {
	int n = 0, min = 0, *p;
	int* arr;
	p = &min;
	PF("Введите кол-во элементов в массиве: ");
	SC("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		PF("%d ", *(arr + i));
	}
	PF("\n");
	min = *arr;
	Min(arr, n, p);
	PF("Минимальный элемент массива: %d\n", min);
	system("pause");
	return 0;
}

int Perevod(int n, int k, int count, char *p) {
	if (n == 0) return count;
	if (n%k < 10) *(p+count) = 48 + n%k;
	else *(p + count) = 65 + (n % k) % 10;
	count++;
	return Perevod(n/k, k, count, p);
}

int task13(void) {
	int n, k, i=0;
	char str[100] = { 0 };
	PF("Введите десятичное число: ");
	SC("%d", &n);
	PF("Введите систему счисления: ");
	SC("%d", &k);
	if (k < 2)
	{
		PF("Некорректная СС");
		return 0;
	}
	int count = Perevod(n, k, 0, str);
	str[count + 1] = '\0';
	for (count=count-1, i; count != 0; count--, i++)
	{
		char c = str[i];
		str[i] = str[count];
		str[count] = c;
	}
	PF("%d в %d-ой системе: %s\n", n, k, str);
	system("pause");
	return 0;
}

int Akk(int n, int m)
{
	if (n == 0) return m + 1;
	if (n != 0 && m == 0) Akk(n - 1, 1);
	if (n > 0 && m > 0) Akk(n - 1, Akk(n, m - 1));
}

int task14(void) {
	int n, m;
	PF("Введите n и m: ");
	SC("%d%d", &n, &m);
	PF("%d\n", Akk(n, m));
	system("pause");
	return 0;
}

int Geom(int q, int n)
{
	if (n == 1) return 1;
	return q*Geom(q, n - 1);
}

int task15(void) {
	int b, q, n;
	PF("Введите первый член, знаменатель и нужный член геом. прог.: ");
	SC("%d%d%d", &b, &q, &n);
	PF("%d\n", b*Geom(q, n));
	system("pause");
	return 0;
}

int Arif(int d, int n) {
	if (n == 1) return 0;
	return d+Arif(d, n - 1);
}

int task16(void) {
	int a, d, n;
	PF("Введите первый член, разность и нужный член геом. прог.: ");
	SC("%d%d%d", &a, &d, &n);
	PF("%d\n", a+Arif(d, n));
	system("pause");
	return 0;
}

int Proizv(int a, int b) {
	if (b == 0) return 0;
	return a + Proizv(a, b - 1);
}

int task17(void) {
	int a, b;
	PF("Введите 2 числа: ");
	SC("%d%d", &a, &b);
	PF("a*b=%d\n", Proizv(a, b));
	system("pause");
	return 0;
}

double SQRT(int x)
{
	if (x == 1) return sqrt(2);
	return sqrt(2 + SQRT(x - 1));
}

int task18(void) {
	int x;
	PF("Введите количество радикалов: ");
	SC("%d", &x);
	PF("%lf\n", SQRT(x));
	system("pause");
	return 0;
}

int Func(int n)
{
	if (n > 100) return n - 10;
	else return Func(Func(n + 11));
}

int task19(void) {
	int n;
	PF("Введите n: ");
	SC("%d", &n);
	PF("%d\n", Func(n));
	system("pause");
	return 0;
}

int Reverse(int n, int *p, int count)
{
	if (n == 0) return 0;
	*p += n % 10 * int(pow(10,count));
	Reverse(n / 10, p, count-1);
}

int task20(void) {
	int n, *p, count=0;
	PF("Введите n: ");
	SC("%d", &n);
	int num = n;
	p = &num;
	while (num)
	{
		num /= 10;
		count++;
	}
	Reverse(n, p, count-1);
	PF("%d\n", *p);
	system("pause");
	return 0;
}

int F(int x0, int x1, int q, int r, int b, int n) {
	if (n == 0) return x0;
	if (n == 1) return x1;
	return q*F(x0, x1, q, r, b, n - 1) + r*F(x0, x1, q, r, b, n - 2) + b;
}

int task21(void) {
	int x0, x1, q, r, b, n;
	PF("Введите значения:\n");
	PF("x0="); SC("%d", &x0);
	PF("x1="); SC("%d", &x1);
	PF("q="); SC("%d", &q);
	PF("r="); SC("%d", &r);
	PF("b="); SC("%d", &b);
	PF("n="); SC("%d", &n);
	if (n < 0)
	{
		PF("k должно быть неотрицательным!");
		return 0;
	}
	PF("%d\n", F(x0, x1, q, r, b, n));
	system("pause");
	return 0;
}

int Funct(int n, int i, int *p)
{
	if (n == 1) return 1;
	if (i > n) return 0;
	*p+=Funct(n%(i+1), i+1, p);
	return 0;
}

int task22(void) {
	int n, i=1, sum=0, *p;
	p = &sum;
	PF("Введите число n>0: ");
	SC("%d", &n);
	if (n<=0)
	{
		PF("n должно быть больше нуля!");
		return 0;
	}
	if (n == 1) sum = 1;
	for (i; i<=n; i++)
	Funct(n, i, p);
	PF("%d\n", *p);
	system("pause");
	return 0;
}


#ifdef TEST_MAIN
void testSoch();

int main(int argc, char **argv)
{
	assert(Fib(1) == 1);
	assert(Fib(2) == 1);
	assert(Fib(3) == 2);
	assert(Fib(4) == 3);
	assert(Fib(15) == 610);

	testSoch();

	assert(NOD(5,10) == 5);

	assert(Sum(10) == 55);

	// FindPrimes(10);

	printf("Tests passed\n");
}

void testSoch() {
	int count = 0;
	int* p = &count;
	assert(Soch(4,2,p) == 6);
	assert(Soch(7,3,p) == 35);
}

#endif