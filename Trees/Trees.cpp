#include "Header.h"

int main()
{
	system("chcp 1251");
	int ntask;
	for (;;) {
		PF("\n�������� ������ (1-2) ��� ����� (3):\n");
		PF("1. ��������� ������ ��������� ������ � ���������� ������� ��������� ���� a.\n");
		PF("2. ��������� ������ ��������� ������ � �������� ��� �������� � ������� ����������� ��������.\n");
		do {
			SC("%d", &ntask);
		} while (ntask < 0 || ntask > 3);
		
		switch (ntask) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: _fcloseall(); exit(0);
		}
	}
    return 0;
}

