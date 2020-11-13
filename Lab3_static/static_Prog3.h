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
        DoubNum() : length(0) // Конструктор по умолчанию
        {
            for (int i = 0; i < SIZE; i++) num[i] = '\0';
        };
        DoubNum(long int initnum); // Конструктор с инициализацией целым числом
        DoubNum(char* initstring); // Конструктор с  инициализацией строкой

        friend std::ostream& DnumOutput(std::ostream& out, DoubNum item); // Вывод экземпляра класса
        DoubNum DnumInput(); // Ввод экземпляра класса
        DoubNum& DopCodeNum(); // Перевод числа в двоичный код
        DoubNum& DnumSum(const DoubNum); // Сумма чисел
        DoubNum& DnumInc(); // Увеличение числа на 1
        DoubNum& DnumDec(); // Уменьшение числа на 1
        bool DnumSign() // Определение знака числа
        {
            return sign;
        }; 
        bool InitializedCheck() // Проверка числа на инициализованность
        {
            if (num[0] == '\0') return false;
            else return true;
        };

        void AntiOverflow(DoubNum&);
        friend void SameLength(DoubNum& a, DoubNum& b);
    };

    int dialog_Input(DoubNum&);
    int dialog_Output(DoubNum&);
    int dialog_DopCode(DoubNum&);
    int dialog_Sum(DoubNum&);
    int dialog_Inc(DoubNum&);
    int dialog_Dec(DoubNum&);
    int dialog_Sign(DoubNum&);
    void display_menu();
    bool get_command(int&);
    void calc(int, DoubNum&);
};

