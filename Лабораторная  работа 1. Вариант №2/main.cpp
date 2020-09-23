#include <iostream>
#include "Prog1.h"

using namespace Prog1;

// основная функция
int main()
{
	Line *arr = nullptr; // исходный массив
	int m, n; // количество строк и элементов в матрице

	arr = input(m, n); // ввод матрицы
	if (!arr){
		std::cout << "incorrect data" << std::endl;
		return 1;
	}
	output("Unsorted Matrix", arr, m, n); // вывод изначальной матрицы
	arr = sort(arr); // сортировка
	output("Sorted Matrix", arr, m, n); // вывод отсортированной матрицы
	arr = erase(arr, m); // освобождение памяти
	return 0;
}
