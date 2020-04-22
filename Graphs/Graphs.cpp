#include "Header.h"

int main() {
	system("chcp 1251");
	int ntask = 0;
	for (;;) {
		PF("\nВыберите задачу (1-8) или выход (9):\n");
		PF("1. Найти самый длинный путь от вершины с номером К к вершине с номером N (найти все пути и выбрать максимальный). (Неориент.)\n");
		PF("2. Найти все вершины, из которых существует путь в данную. (Ориент.)\n");
		PF("3. Обход графов.\n");
		PF("4. Алгоритм Прима-Дейкстры. (Мин. остовное дерево)\n");
		PF("5. Алгоритм Крускала. (Мин. остовное дерево)\n");
		PF("6. Алгоритм поиска кратчайшего пути Дейкстры.\n");
		PF("7. Алгоритм Воршалла. (Транзитивное замыкание)\n");
		PF("8. Алгоритм Флойда. (Кратчайшее расстояние между всеми парами вершин)\n");
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

