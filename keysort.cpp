/*
We need to sort a matrix and show a highest number in a row

*/


#include "stdafx.h"


#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


#pragma warning(disable:4996)




int main()
{

	setlocale(LC_ALL, "rus");


	const int N = 100; //макс. размер матрицы
	int m[N][N];
	int r = 0, c = 0;

	printf("\n Введите количество строк и столбцов матрицы: ");
	scanf("%d%d", &r, &c);

	//Заполняем случайными значениями
	srand((unsigned)time(NULL));

	int i, j;
	for (i = 0; i <= r - 1; i++)
	{
		printf("\n\t");
		for (j = 0; j <= c - 1; j++)
		{
			m[i][j] = rand() % 1000;
		}
	}


	int MaxInRow[N];  //находим макс. элемент в каждой строке, его сохраняем в 1мерный массив
	int IndexRow[N];//в другой 1мерный массив сохраняем индекс соотв. строки

	for (i = 0; i <= r - 1; i++)
	{
		MaxInRow[i] = m[i][0];
		IndexRow[i] = i;
		for (j = 1; j <= c - 1; j++)
		{
			if (MaxInRow[i]<m[i][j])
				MaxInRow[i] = m[i][j];
		}
	}




	//Вывод в консоль исходного
	printf("\n Исходная матрица: ");

	for (i = 0; i <= r - 1; i++)
	{
		printf("\n\t");
		for (j = 0; j <= c - 1; j++)
		{
			printf("%5d", m[i][j]);
		}

		printf("       ");
		printf("%5d", MaxInRow[i]);
	}


	//сортируем ключи (пузырьком)
	int temp = 0;
	for (i = 0; i <= r - 2; i++)
	{
		for (j = 0; j <= r - 2 - i; j++)
		{
			if (MaxInRow[j]<MaxInRow[j + 1])
			{
				temp = MaxInRow[j];
				MaxInRow[j] = MaxInRow[j + 1];
				MaxInRow[j + 1] = temp;

				temp = IndexRow[j];
				IndexRow[j] = IndexRow[j + 1];
				IndexRow[j + 1] = temp;
			}
		}
	}


	//Вывод в консоль полученного
	int CurrentIndex = 0;
	printf("\n Матрица, отсортированная по ключам: ");
	for (i = 0; i <= r - 1; i++)
	{
		printf("\n\t");
		CurrentIndex = IndexRow[i];
		for (j = 0; j <= c - 1; j++)
		{
			printf("%5d", m[CurrentIndex][j]);
		}
		printf("       ");
		printf("%5d", MaxInRow[i]);
	}


	getch();
	return 0;
}


