#include "header.h"

int main(void)
{
	system("chcp 1251");
	int ntask, nsort = 0;
	for (;;) {
		PF("\n�������� ������ (1-4) ��� ����� (5):\n");
		PF("1. ���� ������� ������������ nxn, ���������� ����� �����. ������������� ��������� �������, ������������ �������� �� �������� ��������� ������� �������.\n");
		PF("2. ���������� ������ �� ����� data.txt � ���� outdata.txt, ������������ ��: �� ����������� ����� ������ ������� �������.\n"); 
		PF("3. ���� ������� ������������ nxn, ���������� ������������ �����. ������������� ������� ��������� ������� �� �������� ������� ��������.\n"); 
		PF("4. ���������� ������ �� ����� data.txt � ���� outdata.txt, ������������ ��: �� �������� ���������� �2� ������� ������� (���������� ������� ������� � ���� outdata.txt ��� ������� ��������).\n");
		do {
			SC("%d", &ntask);
		} while (ntask < 0 || ntask>5);
		if (ntask != 3) {
			PF("\n�������� ����� ����������: ");
			PF("\n1. �������");
			PF("\n2. �����");
			PF("\n3. ���������");
			PF("\n4. ���������");
			PF("\n5. ���������\n");
			do {
				SC("%d", &nsort);
			} while (nsort < 0 || nsort > 5);
		}
		switch (ntask) {
		case 1: task1(nsort); break;
		case 2: task2(nsort); break;
		case 3: task3(); break;
		case 4: task4(nsort); break;
		}
	}
	return 0;
}

