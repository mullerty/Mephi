namespace Prog1{
	// структура для задания строки матрицы
	struct Elems
	{
		int row;
		double a;
		Elems* next;
	};
	struct Line
	{
		int l;
		Elems* Rows = NULL;
		Line* next;
	};
	struct Mas {
		int l;
		double a;
	};

	// шаблон функций ввода одного значения
	template <class T>
	int getNum(T &a)
	{
		std::cin >> a;
		if (!std::cin.good())	// обнаружена ошибка ввода или конец файла
			return -1;
		return 1;
	}

	// прототипы функций
	Line* input(int &,int &); // ввод матрицы
	void output(const char *msg, Line*& a, int m, int n); // вывод матрицы
	Line *erase(Line *&a, int m); // освобождение занятой памяти
	Line* sort(Line *a); // вычисление главного результата
}
