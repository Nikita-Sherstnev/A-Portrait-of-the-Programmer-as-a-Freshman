#include "Header.h"

FILE *f = fopen("input.txt", "r");
FILE *g = fopen("output.txt", "w");
int n, **gr, *nov, count=0;

void dft(int v) {
	int u;
	fprintf(g, "%d ", v + 1);
	nov[v] = 0;
	for (u = 0; u < n; u++)
		if (gr[v][u] && nov[u])
			dft(u);
}

void dft1(int v) {
	int u, flag, i;
	stack *s;
	init_stack(s);
	push(s, v);
	fprintf(g, "%d ", v + 1);
	nov[v] = 0;
	while (s) {
		flag = 1; 
		i = peek(s); 
		for (u = 0; u < n && flag;)
			if (gr[i][u] && nov[u]) 
				flag = 0; 
			else
				u++; 

		if (!flag) {
			push(s, u);
			fprintf(g, "%d ", u + 1); 
			nov[u] = 0;
		}
		else pop(s); 
	}
}

void bft(int v) {
	int u;
	tqueue *h, *t;
	init_queue(h, t);
	insert(h, t, v);
	nov[v] = 0;
	while (h) {
		v = take(h, t); 
		fprintf(g, "%d ", v + 1);
		for (u = 0; u<n; u++)
			if (gr[v][u] && nov[u]) {
				insert(h, t, u); 
				nov[u] = 0;
			}
	}
}

void travel() {
	int i, j, choice;
	fscanf(f, "%d", &n);
	nov = (int*)malloc(sizeof(int)*n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		nov[i] = 1;
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j<n; j++)
			fscanf(f, "%d", &gr[i][j]);
	}
	PF("Выберите способ обхода:\n 1. В глубину (рекурсивный)\n 2. В глубину (стек)\n 3. В ширину (очередь)\n");
	do {
	SC("%d", &choice);
    } while (choice < 1 || choice > 3);
	switch (choice) {
	    case 1: for (i = 0; i < n; i++) if (nov[i]) dft(i); break;
		case 2: for (i = 0; i < n; i++) if (nov[i]) dft1(i); break;
		case 3: for (i = 0; i < n; i++) if (nov[i]) bft(i); break;
		default: break;
	}
	rewind(f);
	free(nov);
	for (i = 0; i<n; i++)
		free(gr[i]);
	free(gr);
	return;
}

void Prim() { //Миниальное остовное дерево
	int **spanning, u, v, min_distance, *distance, *from;
	int edges, i, j, min_cost;

	fscanf(f, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	spanning = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		spanning[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++)
		{
			fscanf(f, "%d", &gr[i][j]);
			if (gr[i][j] == 0) gr[i][j] = INF;
			spanning[i][j] = 0;
		}
	}

	distance = (int*)malloc(sizeof(int)*n);
	from = (int*)malloc(sizeof(int)*n);
	nov = (int*)malloc(sizeof(int)*n);

	distance[0] = 0;
	nov[0] = 1;

	for (i = 1; i < n; i++) {
		distance[i] = gr[0][i];
		from[i] = 0;
		nov[i] = 0;
	}

	min_cost = 0;
	edges = n - 1;   //При n вершин n-1 итерация

	while (edges > 0) {
		//ищем вершину на минимальном расстоянии от дерева
		min_distance = INF;
		for (i = 1; i < n; i++)
			if (nov[i] == 0 && distance[i]<min_distance) {
				v = i;
				min_distance = distance[i];
			}
		u = from[v];

		//Добавляем ребро в оставное дерево
		spanning[u][v] = distance[v];
		spanning[v][u] = distance[v];
		edges--;
		nov[v] = 1;

		PF("Добавляем ребро %d-%d длиной %d\n", u+1, v+1, distance[v]);

		//Обновляем кайму
		for (i = 1; i<n; i++)
			if (nov[i] == 0 && gr[i][v]<distance[i]) {
				distance[i] = gr[i][v];
				from[i] = v;
			}
		min_cost += gr[u][v];
	}

	PF("Матрица смежности остовного дерева:\n");
	for (u = 0; u < n; u++) {
		for (v = 0; v < n; v++)
			PF("%d", spanning[u][v]);
		PF("\n");
	}

	free(distance);
	free(from);
	free(nov);
	for (i = 0; i<n; i++)
		free(gr[i]);
	free(gr);
	for (i = 0; i<n; i++)
		free(spanning[i]);
	free(spanning);

	PF("Вес дерева: %d", min_cost);
	fprintf(g, "%d", min_cost);

	rewind(f);
	return;
}

void Kruskal() { //Минимальное остовное дерево
	int *parent, min, sum = 0, ne = 0, i, j, u, v, a, b;

	fscanf(f, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &gr[i][j]);
			if (gr[i][j] == 0) gr[i][j] = INF;
		}
	}

	parent = (int*)calloc(n,sizeof(int));

	while (ne < n - 1) {
		min = INF;
		//Поиск ребра с минимальным весом
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				if (gr[i][j]<min) {
					min = gr[i][j];
					u = a = i;
					v = b = j;
				}
			}

		while (parent[u])
			u = parent[u];
		while (parent[v])
			v = parent[v];

		if (u != v) {
			ne++;
			sum += min;
			PF("\nРебро %d-%d длиной %d", a+1, b+1, min);
			parent[v] = u;
		}
		gr[a][b] = gr[b][a] = INF;
	}

	PF("\nВес дерева: %d", sum);
	fprintf(g, "%d", sum);

	free(parent);
	rewind(f);
	for (i = 0; i<n; i++)
		free(gr[i]);
	free(gr);
	return;
}

void Dijkstra() {
	int *distance, *pred, mindistance, nextnode, i, j, n, u, startnode;
	
	fscanf(f, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &gr[i][j]);
			if (gr[i][j] == 0) gr[i][j] = INF;
		}
	}
	PF("\nВведите начальную вершину (отсчёт с 1): ");
	SC("%d", &startnode);
	startnode--;

	distance = (int*)malloc(sizeof(int)*n);
	pred = (int*)malloc(sizeof(int)*n);
	nov = (int*)malloc(sizeof(int)*n);

	for (i = 0; i<n; i++) {
		distance[i] = gr[startnode][i];
		pred[i] = startnode;
		nov[i] = 0;
	}

	distance[startnode] = 0;
	nov[startnode] = 1;
	count = 1;

	while (count < n - 1) {
		mindistance = INF;

		//Находим вершину на минимальном расстоянии
		for (i = 0; i<n; i++)
			if (distance[i]<mindistance && !nov[i]) {
				mindistance = distance[i];
				nextnode = i;
			}
        
		nov[nextnode] = 1;
		for (i = 0; i<n; i++)
			if (!nov[i])
				if (mindistance + gr[nextnode][i]<distance[i]) {
					distance[i] = mindistance + gr[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	for (i = 0; i < n; i++)
		if (i != startnode) {
			PF("\nРасстояние до вершины %d = %d", i+1, distance[i]);
			PF("\nПуть = %d", i+1);
			j = i;
			do {
				j = pred[j];
				PF("<-%d", j+1);
			} while (j != startnode);
		}

	count = 0;
	free(distance);
	free(pred);
	free(nov);
	for (i = 0; i < n; i++)
		free(gr[i]);
	free(gr);
	rewind(f);
	return;
}

void Warshall() {
	//Работает для ориент и неориент графов
	int i, j, k;

	fscanf(f, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &gr[i][j]);
		}
	}

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (gr[i][j] > (gr[i][k] && gr[k][j]))
					gr[i][j] = gr[i][j];
				else
					gr[i][j] = gr[i][k] && gr[k][j];

	PF("\nТранзитивное замыкание: \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			PF("%d ", gr[i][j]);
		PF("\n");
	}

	for (i = 0; i < n; i++)
		free(gr[i]);
	free(gr);
	rewind(f);
	return;
}

void Floyd() {
	//Работает только для ориент графов
	int i, j, k;

	fscanf(f, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &gr[i][j]);
		}
	}

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (i == j)
					gr[i][j] = 0;
				else {
					if (gr[i][j] < (gr[i][k] + gr[k][j]))
						gr[i][j] = gr[i][j];
					else gr[i][j] = gr[i][k] + gr[k][j];
				}

	PF("\nМатрица минимальных расстояний:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			PF("%d ", gr[i][j]);
		PF("\n");
	}

	for (i = 0; i < n; i++)
		free(gr[i]);
	free(gr);
	rewind(f);
	return;
}

void Path(int v, int *lp, int path, int N) {
	int u;
	nov[v] = 1;
	for (u = 0; u < n; u++)
		if (gr[v][u] && !nov[u]) {
			path += gr[v][u];
			if (u == N) {
				lp[count++] = path;
			}
			Path(u, lp, path, N);
			path -= gr[v][u];
			}
	nov[v] = 0;
}

void task1() {
	int i, j, path = 0, *lp, K, N, max = 0;

	fscanf(f, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &gr[i][j]);
		}
	}

	lp = (int*)calloc(n*n, sizeof(int));
	nov = (int*)calloc(n, sizeof(int));
	PF("Введите начальную и конечную вершины: ");
	SC("%d %d", &K, &N);
	--K; --N;
	Path(K, lp, path, N);

	for (i = 0; i < n*n; i++) {
		if (lp[i] > max) max = lp[i];
	}
	PF("Самый длинный путь от %d до %d: %d", K+1, N+1, max);
	PF("\n");
	free(nov);
	for (i = 0; i < n; i++)
		free(gr[i]);
	free(gr);
	rewind(f);
	return;
}

void task2() {
	int i, j, k, vertex;

	fscanf(f, "%d", &n);
	gr = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i<n; i++) {
		gr[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			fscanf(f, "%d", &gr[i][j]);
		}
	}

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (gr[i][j] > (gr[i][k] && gr[k][j]))
					gr[i][j] = gr[i][j];
				else
					gr[i][j] = gr[i][k] && gr[k][j];

	PF("Введите нужную вершину (первая - 1): ");
	SC("%d", &vertex);
	vertex--;
	int check=0;
	PF("Существует путь из вершин ");
	for (i = 0; i < n; i++) {
		if (gr[i][vertex] == 1 && i!=vertex)
			if (check == 0) {
				PF("%d", i + 1);
				check++;
			}
			else PF(", %d", i + 1);
	}

	PF("\n");
	for (i = 0; i < n; i++)
		free(gr[i]);
	free(gr);
	rewind(f);
	return;
}