#include "Header.h"

int main() {
	system("chcp 1251");
	int ntask = 0;
	for (;;) {
		PF("\n�������� ������ (1-8) ��� ����� (9):\n");
		PF("1. ����� ����� ������� ���� �� ������� � ������� � � ������� � ������� N (����� ��� ���� � ������� ������������). (��������.)\n");
		PF("2. ����� ��� �������, �� ������� ���������� ���� � ������. (������.)\n");
		PF("3. ����� ������.\n");
		PF("4. �������� �����-��������. (���. �������� ������)\n");
		PF("5. �������� ��������. (���. �������� ������)\n");
		PF("6. �������� ������ ����������� ���� ��������.\n");
		PF("7. �������� ��������. (������������ ���������)\n");
		PF("8. �������� ������. (���������� ���������� ����� ����� ������ ������)\n");
		do {
			SC("%d", &ntask);
		} while (ntask < 0 || ntask > 9);

		switch (ntask) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: travel(); break;
		case 4: Prim(); break;
		case 5: Kruskal(); break;
		case 6: Dijkstra(); break;
		case 7: Warshall(); break;
		case 8: Floyd(); break;
		case 9: _fcloseall(); exit(1);
		default: break;
		}
	}
    return 0;
}

