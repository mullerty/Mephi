#pragma once
#ifndef Prog3_h
#define Prog3_h

#include <stdio.h>
#include <iostream>
#endif /* Prog2_hpp */
using namespace std;
namespace prog3 {

#define ERMSG "Incorrect input.\n"/* лучше использовать char const* _ermsg = "..."; */
#define INFO "Enter a number --> "/* или char constexpr* _ermsg = "Incorrect input.\n"; */
/* аналогично для этой строки: int const _size = 74; или int constexpr _size = 74;
директивы предпроцессора в данном случае использовать не стоит,
т.к. они не инкапсулируются => возможны пересечения при использовании вместе с другими библиотеками */
    
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
            cin.ignore(10000, '\n');/*почему 10000*/
        }

        return 0;
    }

    class DoubNum {

    private:
        long int length;/*можно использовать size_t*/
        bool sign;
        char num[SIZE];

    public:
        DoubNum() : length(0) // Êîíñòðóêòîð ïî óìîë÷àíèþ
        {
            for (int i = 0; i < SIZE; i++) num[i] = '\0';
        };
        DoubNum(long int initnum); // Êîíñòðóêòîð ñ èíèöèàëèçàöèåé öåëûì ÷èñëîì
        DoubNum(char* initstring); // Êîíñòðóêòîð ñ  èíèöèàëèçàöèåé ñòðîêîé
        /* произойдет копирование DoubNum item из другого контекста, 
        лучше писать DoubNum const& item */
        friend std::ostream& DnumOutput(std::ostream& out, DoubNum item); // Âûâîä ýêçåìïëÿðà êëàññà
        DoubNum DnumInput(); // Ââîä ýêçåìïëÿðà êëàññà
        DoubNum& DopCodeNum(); // Ïåðåâîä ÷èñëà â äâîè÷íûé êîä
        DoubNum& DnumSum(const DoubNum); // Ñóììà ÷èñåë
        DoubNum& DnumInc(); // Óâåëè÷åíèå ÷èñëà íà 1
        DoubNum& DnumDec(); // Óìåíüøåíèå ÷èñëà íà 1
        bool DnumSign() // Îïðåäåëåíèå çíàêà ÷èñëà
        {
            return sign;
        };
        /* насколько я понял из реализации конструктора с инициализацией целым числом,
        num[0] будет содержать наименее значимый рязряд исходного числа (initnum)
        при этом в конструкторе с инициализацией строкой num[0] будет == '\0'
        проверка будет работать корректно не всегда */
        /*насчёт этого не уверен*/
        bool InitializedCheck() // Ïðîâåðêà ÷èñëà íà èíèöèàëèçîâàííîñòü
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

