#include "Header.h"

int main(void)
{
	system("chcp 1251");
	int n = 0;
	PF("�������� ����: \n");
	PF("1. �������� ���������\n");
	PF("2. ��������������� ���������\n");
	PF("3. �����\n");
	PF("4. ���������� �������\n");
	PF("5. ��������� �������\n");
	PF("6. ������\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1: 
		PF("�������� ������: \n");
		PF("1. ��������� �������� ��������� cosx / (pi - 2*x) + 16*x*cos(x*y)\n");
		PF("2. �������� ���������, ������� ����������, �������� �� ����������� � ��������� ��������� ��������������.\n");
		PF("3. � ����������� ����� x ���������� ������ �����. ����� � ��������������� ����� ��������� ������ ����� ����� x, �� ���������� ����� y. �� ��������� 99<y<1000 ����� ����� x (����������� � ����� �������� � y �� ������������� �����).\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		default: PF("��� ����� ������!\n");
			break;
		}
		break;
	case 2:
		PF("�������� ������: \n");
		PF("1. z=2*cos(x)+3*x*x+0.75 ��� z=log(fabs(sin(2*x)))\n");
		PF("2. ������� � ���������� 7 ����. ����� �� ��������� ����� ����������, ���������� �� ����� � ����� ���������� �������, �, ���� ����������, �������� ��� �� �����. ��������, ���� ������� ����� \"���� ��� ��� ������ ���� ����� ����\", �� ��� ������� ������� 5 �� ����� ������ ���� �������� ����� \"����\".\n");
		PF("3. ���� ������ ������������� �� ��������� �, � � ������ ������������� �� ��������� �, �. ���� ������ �������������� ���������� ������ ������� ���, ��� ���� �� ����� ���������, ������� �� ����� ��������� \"��\", ����� � ��������� \"���\"\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: task4(); break;
		case 2: task5(); break;
		case 3: task6(); break;
		default: PF("��� ����� ������!\n");
			break;
		}
		break;
	case 3:
		PF("�������� ������: \n");
		PF("1. ���� ����������� ����� N>2. ��������� S(k=2=>N)=ln(1+k)^2.\n");
		PF("2. ��������� �� ������ ���������� ������������ ����� n ����� 0 � 5, ������� ������� ������� ��������� ����. ����������� ��� �����.\n");
		PF("3. (x)=(x-1)*y_n*(x)-(3x-2)*y_(n-1)*(x), y_0=0.1, y_1=x-1\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: task7(); break;
		case 2: task8(); break;
		case 3: task9(); break;
		default: PF("��� ����� ������!\n");
			break;
		}
		break;
	case 4:
		PF("�������� ������: \n");
		PF("1. ������������ ������������� ������ X(N), ���������� �������� �������� ��������� ����� �� ��������� [-3..3].����������, ������� ��� � ��� ����������� ��� ������ ������ ������� ��������.\n");
		PF("2. ��� ���������� ������ � ��������������� ����� �����. ������� �� ����� �������� ����� ������������ ��������� � ������� �������������� ��������� ��� �������������� ���������. ���� ������������� ��������� ���, �� ������� �� ����� ��������� ����.\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: task10(); break;
		case 2: task11(); break;
		default: PF("��� ����� ������!\n");
			break;
		}
		break;
	case 5:
		PF("�������� ������: \n");
		PF("1. � ������ ���������� �������, ���������� ������� �������� ����� �����, ����� ������������ ������� � ������ ������ � �������� ������ � ����� ������.\n");
		PF("2. ���� ������������� ���������� ������� � ������� N, ��� N � �������� ����������� �����. ���� � ������� � ���� ������, ��� �������� ������� �������� ���������� ��������� �������, �� ������� �� ����� ��������� ���, ����� ��������� ����.\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: task12(); break;
		case 2: task13(); break;
		default: PF("��� ����� ������!\n");
			break;
		}
		break;
	case 6:
		PF("�������� ������: \n");
		PF("1. ������������� ������, ������ ������ ������.\n");
		PF("2. ���� ������������������ ��������, ��������� �� ����. �������� � ������ ����� �������� ��������� �� �������� �����. ���� �� ������ ����� �� ��������� ���� ����� ��� ����� ����������� �� �����������, �� ������� ����� ����� � ����������� ��������� ��������. ������� �� ����� ������������������ ����� ��� ��������� ����, ���� �������� ���� �� ����. ����������� ��������������� �� ����������� ������������� ����������� ������� ���� � �����.\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: task14(); break;
		case 2: task15(); break;
		default: PF("��� ����� ������!\n");
			break;
		}
		break;
	default: PF("��� ����� ����!");
	}
}