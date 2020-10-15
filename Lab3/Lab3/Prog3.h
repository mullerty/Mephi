#pragma once
#ifndef Prog3_h
#define Prog3_h

#include <stdio.h>
#include <iostream>

#endif /* Prog2_hpp */
using namespace std;
namespace prog3 {

#define ERMSG "Incorrect input.\n"
#define INFO "Enter a number --> "
#define PI 3.14159265358979323846
#define SIZE 74

    template <class T>
    int get_num(T& a, const char* info = INFO, const char* ermsg = ERMSG) {
        cout << info;

        while (!(cin >> a)) {
            if (cin.eof())
                return 1;
            cout << ermsg;
            cout << info;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        return 0;
    }

    class DoubNum {

    private:
        long int length;
        bool sign;
        char num[SIZE];

    public:
        DoubNum(): length(0) // Конструктор по умолчанию
        {
            for (int i = 0; i < SIZE; i++) num[i] = '\0';
        };
        DoubNum(long int initnum); // Конструктор с инициализацией целым числом
        DoubNum(char* initstring); // Конструктор с  инициализацией строкой

        friend std::ostream& DnumOutput(std::ostream& out, DoubNum& item); // Вывод экземпляра класса
        DoubNum DnumInput(int ch); // Ввод экземпляра класса
        void DopCodeNum(); // Перевод числа в двоичный код
        DoubNum DnumSum(); // Сумма чисел
        char DnumInc(); // Увеличение числа на 1
        char DnumDec(); // Уменьшение числа на 1
        bool DnumSign(); // Определение знака числа
        bool InitializedCheck(); // Проверка числа на инициализованность


    };

    int dialog_Input();
    int dialog_Output();
    int dialog_DopCode();
    int dialog_Sum();
    int dialog_Inc();
    int dialog_Dec();
    int dialog_Sign();
    void display_menu();
    bool get_command(int& a);
    void calc(int num, DoubNum& line);
};

