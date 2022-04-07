// 19. Имеются два файла с целыми числами.Требуется создать новый файл, включив в него без
// повторов только те из чисел первого файла, которые не встречаются во втором файле.
// Я сделал программу без файлов, но со случайным заполнением чисел, а класс я поместил в файл Header1.h

#include <fstream>
#include <windows.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

#include "Header1.h"
int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		cout << "Введите число: 1 - начало работы, 0 - конец работы" << endl;
		int z = _getch();
		switch (z)
		{
		case 49:
		{
			int u, y, t, o;
			cout << endl;
			cout << "Укажите кол-во чисел в 1-ом списке: ";
			cin >> u;
			cout << endl;
			cout << "Укажите диапазон чисел в 1-ом списке: ";
			cin >> y;
			cout << endl;
			if ((u < 0) || (y < 0))
			{
				cout << "Ошибка! Укажите положительные значения. " << endl << endl;
				continue;
			}
			List<int> lst_1;
			for (int j = 0; j < u; j++)
			{
				lst_1.push_front(rand() % y + 1);
			}
			cout << "_________________" << endl << "1 СПИСОК:" << endl << "_________________" << endl;
			for (int i = 0; i < lst_1.GetSize(); i++)
			{
				cout << i + 1 << " элемент - " << lst_1[i] << endl;
			}
			cout << endl;
			cout << "Укажите кол-во чисел во 2-ом списке: ";
			cin >> t;
			cout << endl;
			cout << "Укажите диапазон чисел во 2-ом списке: ";
			cin >> o;
			cout << endl;
			if ((t < 0) || (o < 0))
			{
				cout << "Ошибка! Укажите положительные значения. " << endl << endl;
				continue;
			}
			List<int> lst_2;
			for (int j = 0; j < t; j++)
			{
				lst_2.push_front(rand() % o + 1);
			}
			cout << "_________________" << endl << "2 СПИСОК:" << endl << "_________________" << endl;
			for (int i = 0; i < lst_2.GetSize(); i++)
			{
				cout << i + 1 << " элемент - " << lst_2[i] << endl;
			}

			cout << endl << "_____________________________________________________________________________________________" << endl << "По итогу вычитания получаем Элементы, которые входят в 1-ое множество, не входят во 2-ое и не повторяются: " << endl << "_____________________________________________________________________________________________" << endl;
			int g = 1;
			for (int k = 0; k < lst_1.GetSize(); k++)
			{
				int q = 0;
				for (int j = 0; j < lst_2.GetSize(); j++)
				{
					if (lst_1[k] == lst_2[j])
						q += 1;
				}
				if (q == 0)
				{
					int v = 0;
					for (int r = 0; r < k; r++)
					{
						if (lst_1[r] == lst_1[k])
							v+=1;
					}
					if (v == 0)
						cout << k + 1 << " Элемент - " << lst_1[k] << endl;
				}
				else
				{
					g += 1;
				} 
				if (g == lst_1.GetSize())
					cout << "Таких чисел нет." << endl;
			}
			cout << endl;
			Sleep(8000);
			continue;
		}

		case 48:
		{
			cout << "Конец работы." << endl;
			return 1;
		}

		default:
			cout << "Ошибка. Введите 1 или 0" << endl;
		}

	}
}

