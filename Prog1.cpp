#include <iostream>
#include <cstdlib>  
#include "Prog1.h"

namespace Prog1 {

	// функция ввода
	Line* input(int &rm, int &rn)
	{
		const char *pr = ""; // будущее сообщение об ошибке
		int m, n;	// количество строк матрицы
		Line* lines = NULL;	// массив списков

		// вводим количество строк
		do{
			std::cout << pr << std::endl;
			std::cout << "Enter number of lines: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(m) < 0) // обнаружена ошибка ввода или конец файла
				return nullptr;
		} while (m < 1);
		pr = "";

		// вводим количество столбцов
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of rows: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(n) < 0) // обнаружена ошибка ввода или конец файла
				return nullptr;
		} while (n < 1);
		pr = "";

		std::cout << "Attention! To end filling of the matrix enter negative index!";
		int i, j;

		// вводим индекс строки
		do {
			std::cout << pr << std::endl;
			pr = "You are wrong; repeat please!";
			std::cout << "Enter the line of element: --> ";
			if (getNum(i) < 0) // обнаружена ошибка ввода или конец файла
				return nullptr;
		} while (i > m);
		i -= 1;
		pr = "";
		
		// Проверка на начало/продолжение запонения матрицы
		while (i > -1) { 

			//создание новой строки
			if (lines == NULL)
			{
				Line* ptr = new Line;
				lines = ptr;
				lines->next = NULL;
				lines->l = i + 1;
			}
			else 
			{
				Line* ptr = lines;
				bool k = false;
				while (ptr != NULL)
				{
					if (ptr->l == i + 1) k = true;
					ptr = ptr->next;
				}
				if (!k) 
				{
					Line* ptr = lines;
					Line* last = new Line;
					last->l = i + 1;
					while ((last->l > ptr->l) && ptr->next != NULL)
						ptr = ptr->next;

					if (((ptr->next == NULL) && (last->l > ptr->l)))
					{
						last->next = ptr->next;
						ptr->next = last;
					}

					if (((ptr->next != NULL) && (last->l < ptr->l)) || ((ptr->next == NULL) && (last->l < ptr->l)))
					{
						last->next = ptr;
						if (ptr == lines) lines = last;
						else
						{
							ptr = lines;
							while (ptr->next != last->next)
								ptr = ptr->next;
							ptr->next = last;
						}
					}
				}
			}

			// вводим индекс столбца
			do {
				std::cout << pr << std::endl;
				pr = "You are wrong; repeat please!";
				std::cout << "Enter the row of element: --> ";
				if (getNum(j) < 0)
					return nullptr;
			} while (j > n);
			j -= 1;
			pr = "";
			
			Line* Lptr = lines;

			while (Lptr->l != i + 1) Lptr = Lptr->next;

			// Замена уже существующих элементов
			if (Lptr->Rows != NULL)
			{
				Elems* ptr = Lptr->Rows;
				Elems* kptr = NULL;
				bool ch = false;
				while (ptr != NULL)
				{
					if (ptr->row == j + 1)
					{
						kptr = ptr;
						ch = true;
					}
					ptr = ptr->next;
				}
				if (kptr == Lptr->Rows && ch) Lptr->Rows = Lptr->Rows->next;
				else if (ch)
				{
					Elems* ptr = Lptr->Rows;
					while (ptr->next != kptr) ptr = ptr->next;
					ptr->next = kptr->next;
				}
			}

			// Проверка на продолжение работы в выбранной строке
			while (j > -1)
			{
				// создание нового элемента
				Elems* last = new Elems;
				last->row = j+1;
				std::cout << "Enter item --> ";
				if (getNum(last->a) < 0) {
					return nullptr;
				}
				std::cout << std::endl;

				// добавление нового элемента в список
				if (last->a != 0)
					if (Lptr->Rows == NULL)
					{
						last->next = NULL;
						Lptr->Rows = last;
					}
					else
					{
						Elems* ptr = Lptr->Rows;

						while ((last->row > ptr->row) && ptr->next != NULL)
							ptr = ptr->next;
						if (((ptr->next == NULL) && (last->row > ptr->row)))
						{
							last->next = ptr->next;
							ptr->next = last;
						}

						if (((ptr->next != NULL) && (last->row < ptr->row)) || ((ptr->next == NULL) && (last->row < ptr->row)))
						{
							last->next = ptr;
							if (ptr == Lptr->Rows) Lptr->Rows = last;
							else 
							{
								ptr = Lptr->Rows;
								while (ptr->next != last->next)
									ptr = ptr->next;
								ptr->next = last;
							}
						}
					}

				// вводим индекс столбца
				do {
					std::cout << pr << std::endl;
					pr = "You are wrong; repeat please!";
					std::cout << "Enter the row of element: --> ";
					if (getNum(j) < 0) // обнаружена ошибка ввода или конец файла
						return nullptr;
				} while (j > n);
				j -= 1;
				pr = "";

				// Замена уже существующих элементов
				if (Lptr->Rows != NULL)
				{
					Elems* ptr = Lptr->Rows;
					Elems* kptr = NULL;
					bool ch = false;
					while (ptr != NULL)
					{
						if (ptr->row == j + 1)
						{
							kptr = ptr;
							ch = true;
						}	
						ptr = ptr->next;
					}
					if (kptr == Lptr->Rows && ch) Lptr->Rows = Lptr->Rows->next;
					else if (ch)
					{
						Elems* ptr = Lptr->Rows;
						while (ptr->next != kptr) ptr = ptr->next;
						ptr->next = kptr->next;
					}
				}

			}

			// вводим индекс строки
			do {
				std::cout << pr << std::endl;
				pr = "You are wrong; repeat please!";
				std::cout << "Enter the line of element: --> ";
				if (getNum(i) < 0)
					return nullptr;
			} while (i > m);
			i -= 1;
			pr = "";
		}

		rm = m;
		rn = n;
		return lines;
	}

	// функция вывода
	void output(const char *msg, Line*& a, int m, int n)
	{
		int i;
		std::cout << msg << ":\n";

		if (a != NULL)
			for (i = 0; i < m; ++i){

				int j = 1;
				Line* Lptr = a;
				while ((Lptr != NULL) && (Lptr->l != i + 1)) Lptr = Lptr->next;

				if (Lptr != NULL)
				{
					Elems* ptr = Lptr->Rows;
					while ((ptr != NULL) || (j <= n))
					{
						if (ptr != NULL)
						{
							while ((ptr->row > j) && (j <= n))
							{
								j += 1;
								std::cout << "0 ";
							}
							if ((j <= n) && (ptr->row >= j))
							{
								j += 1;
								std::cout << ptr->a << " ";
							}
							ptr = ptr->next;

						}
						else
							while (j <= n)
							{
								j += 1;
								std::cout << "0 ";
							}
					}
				}
				else 
					while (j <= n)
					{
						j += 1;
						std::cout << "0 ";
					}
				
				std::cout << std::endl;
			}
		else
			for (i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) std::cout << "0 ";
				std::cout << std::endl;
			}		
	}

	// функция освобождения занятой памяти
	Line *erase(Line *&lines, int m)
	{
		while (lines != nullptr) {
			Line* tmp_ln = lines;
			while (lines->Rows != nullptr) {
				Elems* tmp_el = lines->Rows;
				lines->Rows = tmp_el->next;
				delete tmp_el;
			}
			lines = lines->next;
			delete tmp_ln;

		}
		delete lines;
		return nullptr;
	}

	// Сортировка
	void ZapSortMas(Line* lines, Mas*& mas, int n) 
	{
		Line* ptr = lines;
		int a, b;
		for (int i = 0; i < n; i++)
		{
			mas[i].l = ptr->l;
			if (ptr->Rows->row == 1)
				mas[i].a = ptr->Rows->a;
			else
				mas[i].a = 0;
			ptr = ptr->next;
		}

		if (lines->Rows != NULL)
		{
			a = lines->Rows->a;
			b = lines->Rows->row;
		}
		else
		{
			a = 0;
			b = 1;
		}

		if ((a > 0) && (b == 1))
		{
			for (int i = 0; i < n-1; i++)
				for (int j = i; j < n; j++)
					if (mas[i].a < mas[j].a)
					{
						double swapD = mas[i].a;
						mas[i].a = mas[j].a;
						mas[j].a = swapD;
						int swapI = mas[i].l;
						mas[i].l = mas[j].l;
						mas[j].l = swapI;
					}
		}
		else
		{
			for (int i = 0; i < n - 1; i++)
				for (int j = i; j < n; j++)
					if (mas[i].a > mas[j].a)
					{
						double swapD = mas[i].a;
						mas[i].a = mas[j].a;
						mas[j].a = swapD;
						int swapI = mas[i].l;
						mas[i].l = mas[j].l;
						mas[j].l = swapI;
					}
		}
	}

	Line* CreateSortedLine(Line *lines,Mas* mas, int b) 
	{
		Line* NewLine = NULL;
		Line* nptr = NULL;
		Line* ptr;

		for (int i = 1; i < b + 1; i++) 
		{
			ptr = lines;
			while (ptr->l != mas[i - 1].l) ptr = ptr->next;
			if (NewLine == NULL)
			{
				NewLine = new Line;
				*NewLine = *ptr;
				NewLine->l = i;
				NewLine->next = NULL;
				nptr = NewLine;
			}
			else
			{
				nptr->next = new Line;
				*nptr->next = *ptr;
				nptr = nptr->next;
				nptr->l = i;
				nptr->next = NULL;
			}
		}

		return NewLine;
	}

	Line* sort(struct Line* lines)
	{
		Line* ans = NULL;
		if (lines != NULL)
		{
			int b = 0;
			Line* ptr = lines;

			while (ptr != NULL)
			{
				b++;
				ptr = ptr->next;
			}

			Mas* mas = new Mas[b];

			ZapSortMas(lines, mas, b);

			ans = CreateSortedLine(lines, mas, b);
		}
		return ans;			
	}

}
