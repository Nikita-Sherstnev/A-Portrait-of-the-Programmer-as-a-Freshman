#include "Header.h"

struct student {
	int group;
	char surname[50];
	char name[50];
	char patronymic[50];
	int year;
	int marks[5];
};

struct student stud_list[MAX];

void int_list(void) {
	int t;
	for (t = 0; t < MAX; t++)
		stud_list[t].group = 0;
	return;
}

void task1(int nsort) {
	int i = 0, j = 0, k=0, sizearr = 0, size=0, **arr, *diagonals;
	FILE *fp;
	FILE *fwrite;
	if ((fp = fopen("array.txt", "r")) == NULL) {
		PF("Error");
		exit(1);
	}
	if ((fwrite = fopen("arraysorted.txt", "w")) == NULL) {
		PF("Error");
		exit(1);
	}
	fscanf(fp, "%d", &sizearr);
	arr = (int**)malloc(sizearr * sizeof(int*));
	for (i = 0; i < sizearr; i++)
		arr[i] = (int*)malloc(sizearr * sizeof(int));

	for (i = 0; i < sizearr; i++)
		for (j = 0; j < sizearr; j++)
			fscanf(fp, "%d", &arr[i][j]);

	for (k = 0; k < sizearr * 2; k++)
	{
		for (j = 0; j <= k; j++)
		{
			i = k - j;
			if (i < sizearr && j < sizearr)
			{
				size++;
			}
		}
		diagonals = (int*)malloc(size * sizeof(int*));
		size = 0;
		for (j = 0; j <= k; j++)
		{
			i = k - j;
			if (i < sizearr && j < sizearr)
			{
				diagonals[size++] = arr[j][i];
			}
		}
		switch (nsort) {
		case 1: Quicksort(diagonals, 0, size-1); break;
		case 2: Shellsort(diagonals, size); break;
		case 3: Insertionsort(diagonals, size); break;
		case 4: Bubblesort(diagonals, size); break;
		case 5: Countingsort(diagonals, size); break;
		}
		size = 0;
		for (j = 0; j <= k; j++)
		{
			i = k - j;
			if (i < sizearr && j < sizearr)
			{
				arr[j][i] = diagonals[size++];
			}
		}
		size = 0;
		free(diagonals);
	}

	for (i = 0; i < sizearr; i++) { //Writing an array
		for (j = 0; j < sizearr; j++)
			fprintf(fwrite, "%d ", arr[j][i]);
		fprintf(fwrite, "\n");
	}

	for (i = 0; i < sizearr; i++)
		free(arr[i]);
	free(arr);
	fclose(fp);
	fclose(fwrite);
	return;
}

void task2(int nsort) {
	int i = 0, j, k, t = 0, count = 0, marks[MAX] = { 0 }, marks2[MAX] = { 0 }, sorted[MAX] = { 0 };
	char c;
	int_list();
	FILE *fp;
	if ((fp = fopen("data.txt", "r")) == NULL) {
		PF("Error!\n");
		exit(1);
	}
		while ((c = fgetc(fp)) != EOF) {
			ungetc(c, fp);
			fscanf(fp, "%d", &stud_list[i].group);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);

			fgets(stud_list[i].surname, 50, fp);
			stud_list[i].surname[strcspn(stud_list[i].surname, "\n")] = 0;

			fgets(stud_list[i].name, 50, fp);
			stud_list[i].name[strcspn(stud_list[i].name, "\n")] = 0;

			fgets(stud_list[i].patronymic, 50, fp);
			stud_list[i].patronymic[strcspn(stud_list[i].patronymic, "\n")] = 0;

			fscanf(fp, "%d", &stud_list[i].year);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);

			for(k=0;k<5;k++)
		    fscanf(fp, "%d", &stud_list[i].marks[k]);
			do { c = fgetc(fp); } while (c != '\n' && c != EOF);
			i++;
		}
	fclose(fp);

	for (j = 0; j <= i; j++)
		for (t = 0; t < 5; t++)
			marks[j] += stud_list[j].marks[t];
	for (j = 0; j <= i; j++)
		marks2[j] = marks[j];

	switch (nsort) {
	case 1: Quicksort(marks, 0, i - 1); break;
	case 2: Shellsort(marks, i); break;
	case 3: Insertionsort(marks, i); break;
	case 4: Bubblesort(marks, i); break;
	case 5: Countingsort(marks, i); break;
	}

	if ((fp = fopen("outdata.txt", "w")) == NULL) {
		PF("Error!\n");
		exit(1);
	}

	for (j = 0; j < i; j++) {
		for (t = 0; t < i; t++)
			if (marks[j] == marks2[t]) {
				for (k = 0; k < i; k++)
					if (t == sorted[k]) count++;
				if (count == 0) sorted[j] = t;
				count = 0;
			}
	}

	for (j = 0; j < i; j++) {
		fprintf(fp, "%d\n", stud_list[sorted[j]].group);

		fputs(stud_list[sorted[j]].surname, fp);
		fputc('\n', fp);
		fputs(stud_list[sorted[j]].name, fp);
		fputc('\n', fp);
		fputs(stud_list[sorted[j]].patronymic, fp);
		fputc('\n', fp);

		fprintf(fp, "%d\n", stud_list[sorted[j]].year);
		for (k = 0; k<4; k++)
			fprintf(fp, "%d ", stud_list[sorted[j]].marks[k]);
		fprintf(fp, "%d\n", stud_list[sorted[j]].marks[4]);
	}

	fclose(fp);
	return;
}

void task3() {
	int i = 0, j = 0, k = 0, sizearr = 0, size = 0, **arr, m=0, x=0;
	FILE *fp;
	FILE *fwrite;
	if ((fp = fopen("array.txt", "r")) == NULL) {
		PF("Error");
		exit(1);
	}
	if ((fwrite = fopen("arraysorted.txt", "w")) == NULL) {
		PF("Error");
		exit(1);
	}
	fscanf(fp, "%d", &sizearr);
	arr = (int**)malloc(sizearr * sizeof(int*));
	for (i = 0; i < sizearr; i++)
		arr[i] = (int*)malloc(sizearr * sizeof(int));

	for (i = 0; i < sizearr; i++)
		for (j = 0; j < sizearr; j++)
			fscanf(fp, "%d", &arr[i][j]);

	for (k = 0; k < sizearr - 1; k++) {
		m = sizearr - k;
		for (i = 0; i <= m; i++) {
			for (j = m - 1; j >= i + 1; j--) {
				if (arr[j - 1][j + k - 1] < arr[j][j + k]) {
					x = arr[j - 1][j + k - 1];
					arr[j - 1][j + k - 1] = arr[j][j + k];
					arr[j][j + k] = x;
				}
				if (arr[j - 1 + k][j - 1] < arr[j + k][j]) {
					x = arr[j - 1 + k][j - 1];
					arr[j - 1 + k][j - 1] = arr[j + k][j];
					arr[j + k][j] = x;
				}
			}
		}
	}

	for (i = 0; i < sizearr; i++) { //Writing an array
		for (j = 0; j < sizearr; j++)
			fprintf(fwrite, "%d ", arr[i][j]);
		fprintf(fwrite, "\n");
	}

	for (i = 0; i < sizearr; i++) //Free memory
		free(arr[i]);
	free(arr);
	fclose(fp);
	fclose(fwrite);
	return;
}

void task4(int nsort) {
	int i = 0, j, k, t = 0, count = 0, marks2[MAX] = { 0 }, marks22[MAX] = { 0 }, sorted[MAX] = { 0 };
	char c;
	int_list();
	FILE *fp;
	if ((fp = fopen("data.txt", "r")) == NULL) {
		PF("Error!\n");
		exit(1);
	}
	while ((c = fgetc(fp)) != EOF) {
		ungetc(c, fp);
		fscanf(fp, "%d", &stud_list[i].group);
		do { c = fgetc(fp); } while (c != '\n' && c != EOF);

		fgets(stud_list[i].surname, 50, fp);
		stud_list[i].surname[strcspn(stud_list[i].surname, "\n")] = 0;

		fgets(stud_list[i].name, 50, fp);
		stud_list[i].name[strcspn(stud_list[i].name, "\n")] = 0;

		fgets(stud_list[i].patronymic, 50, fp);
		stud_list[i].patronymic[strcspn(stud_list[i].patronymic, "\n")] = 0;

		fscanf(fp, "%d", &stud_list[i].year);
		do { c = fgetc(fp); } while (c != '\n' && c != EOF);

		for (k = 0; k<5; k++)
			fscanf(fp, "%d", &stud_list[i].marks[k]);
		do { c = fgetc(fp); } while (c != '\n' && c != EOF);
		i++;
	}
	fclose(fp);

	for (j = 0; j <= i; j++) {
		for (t = 0; t < 5; t++)
			if (stud_list[j].marks[t] == 2) marks2[j]++;
		marks2[j] = 5 - marks2[j];
	}
	for (j = 0; j <= i; j++)
		marks22[j] = marks2[j];

	switch (nsort) {
	case 1: Quicksort(marks2, 0, i - 1); break;
	case 2: Shellsort(marks2, i); break;
	case 3: Insertionsort(marks2, i); break;
	case 4: Bubblesort(marks2, i); break;
	case 5: Countingsort(marks2, i); break;
	}

	if ((fp = fopen("outdata.txt", "w")) == NULL) {
		PF("Error!\n");
		exit(1);
	}

	for (j = 0; j < i; j++) {
		for (t = 0; t < i; t++)
			if (marks2[j] == marks22[t]) {
				for (k = 0; k < i; k++)
					if (t == sorted[k]) count++;
				if (count == 0) sorted[j] = t;
				count = 0;
			}
	}

	for (j = 0; j < i; j++) {
		fprintf(fp, "%d\n", stud_list[sorted[j]].group);

		fputs(stud_list[sorted[j]].surname, fp);
		fputc('\n', fp);
		fputs(stud_list[sorted[j]].name, fp);
		fputc('\n', fp);
		fputs(stud_list[sorted[j]].patronymic, fp);
		fputc('\n', fp);

		fprintf(fp, "%d\n", stud_list[sorted[j]].year);
		for (k = 0; k<4; k++)
			fprintf(fp, "%d ", stud_list[sorted[j]].marks[k]);
		fprintf(fp, "%d\n", stud_list[sorted[j]].marks[4]);
		for (k = 0; k < 5; k++)
			if (stud_list[sorted[j]].marks[k] == 5) count++;
		fprintf(fp,"Количество пятерок: %d\n", count);
		count = 0;
	}

	fclose(fp);
	return;
}
