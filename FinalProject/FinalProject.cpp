#include "Header.h"

int main() {
	system("chcp 1251");
	int ntask = 0;
	for (;;) {
		PF("\n�������� ������ (1-7) ��� ����� (8):\n");
		PF("1. ������������ ������� ������ (������������ �������� �����) (��������)\n");
		PF("2. ������ ��������� ���� � ������ �����, �����, ���. (���������)\n");
		PF("3. ������� ��������� ����. ���������� ��� ������ � ������ ����. ������� ����� ������ ���� �������� �� ��������� � �������� ����� � �������� �����. (�����)\n");
		PF("4. ���� ������� ������������ nxn, ���������� ������������ �����. ������������� ������� ��������� ������� �� �������� ������� ��������. (����������)\n");
		PF("5. ������� ������ �� ����. ����������� �������� ������ � �������� �������.(�����)\n");
		PF("6. ��������� ������ ��������� ������ � �������� ��� �������� � ������� ����������� ��������.(�������)\n");
		PF("7. ����� ��� �������, �� ������� ���������� ���� � ������.(������.)(�����)\n");
		do {
			SC("%d", &ntask);
		} while (ntask < 0 || ntask > 8);

		switch (ntask) {
		case 1: task1(); break;
		case 2: task3(); break;
		case 3: task2(); break;
		case 4: task4(); break;
		case 5: task5(); break;
		case 6: task6(); break;
		case 7: task7(); break;
		case 8: _fcloseall(); exit(1);
		default: break;
		}
	}
	return 0;
}

