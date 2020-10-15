#include "Prog3.h"
#include <cmath>
#include <iostream>
#include <string.h>
//#include <stdio.h>
//#include <cstring>

namespace prog3 {

   /* DoubNum::DoubNum() // Конструктор по умолчанию
    {
        length = 0;
        for (int i = 0; i < 74; i++) num[i] = '\0';
    };*/

    DoubNum::DoubNum(long int initnum) // Конструктор с инициализацией целым числом
    {
        for (int i = 0; i < SIZE; i++) num[i] = '\0';
        length = 2;
        if (initnum >= 0) sign = true;
        else sign = false;
        while (initnum != 0) 
        {
            num[length] = (initnum % 2) + '0';
            initnum /= 2;
            ++length;   
        }
    };

    DoubNum::DoubNum(char* initstring) // Конструктор с  инициализацией строкой
    {
        int i = 0;
        length = 0;
        while (initstring[i] != '\0') 
        {
            ++length;
            num[i] = initstring[i];
            ++i;
        }  
    };

    std::ostream& DnumOutput(std::ostream& out, DoubNum& item) // Вывод экземпляра класса
    {
        out << "Your number: ";
        for (int i = 0; i < item.length; i++) 
            out << item.num[i];
        out << endl;
    };
    
    DoubNum DoubNum::DnumInput(int ch) // Ввод экземпляра класса
    {
        int initnum;
        char initstr[SIZE];
        for (int i = 0; i < SIZE; i++) initstr[i] = '\0';
        if (ch == 1)
        {
            get_num(initnum, "Enter number --> ");
            return DoubNum(initnum);
        }
        if (ch == 2)
        {
            std::cout << "Enter the number --> ";
            std::cin >> initstr;
            std::cout << endl;
            return DoubNum(initstr);
        }
        if (ch == 3)
            return DoubNum();
    };

    void DoubNum::DopCodeNum() // Перевод числа в двоичный код
    {
        for (int i = 0; i < length; i++)
            if (num[i] == '1') num[i] = '0';
            else num[i] = '1';

        if (num[length - 1] == '0') num[length - 1] = '1';
        else
        {
            i=
            while (num[i])
            {

            }
        }
    };

    DoubNum DoubNum::DnumSum() // Сумма чисел
    {
        
        return;
    };

    char DoubNum::DnumInc() // Увеличение числа на 1
    {

        return'\0';
    };

    char DoubNum::DnumDec() // Уменьшение числа на 1
    {

        return'\0';
    };

    bool DoubNum::DnumSign() // Определение знака числа
    {
        return sign;
    };

    bool DoubNum::InitializedCheck() // Проверка числа на инициализованность
    {
        if (num[0] == '\0') return false;
        else return true;
    };

    int dialog_Input(DoubNum& item)
    {
        int ch = 0;
        const char* msg = "";
        std::cout << "Choose type of input:\n"<<
                    "1. Input by Number\n"<<
                    "2. Input by String\n"<<
                    "3. Initialize as an empty number\n";
        do {
            std::cout << msg << endl;
            msg = "Error! Wrong number!";
            if (get_num(ch, "Enter command --> ")) return 1;
        } while (ch <= 0 || ch > 3);
                
        item = item.DnumInput(ch);

        return 0;
    };

    int dialog_Output(DoubNum& item)
    {
        if (item.InitializedCheck()) DnumOutput(std::cout, item);
        else std::cout << "Number is empty! Initialize it, please." << endl;

        return 0;
    };

    int dialog_DopCode(DoubNum& item)
    {
        if (item.InitializedCheck())
            if (!item.DnumSign()) item.DopCodeNum();
            else DnumOutput(std::cout, item);
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    int dialog_Sum(DoubNum& item)
    {
        if (item.InitializedCheck())
            if (item.DnumSign()) std::cout << "(+) Number is positive" << endl;
            else std::cout << "(-) Number is negative" << endl;
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    int dialog_Inc(DoubNum& item)
    {
        if (item.InitializedCheck())
            std::cout << "Here your increased number: "<< item.DnumInc() << endl;
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    int dialog_Dec(DoubNum& item)
    {
        if (item.InitializedCheck())
            std::cout << "Here your decreased number: " << item.DnumDec() << endl;
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    int dialog_Sign(DoubNum& item)
    {
        if (item.InitializedCheck())
            if (item.DnumSign()) std::cout << "(+) Number is positive" << endl;
            else std::cout << "(-) Number is negative" << endl;
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    void display_menu()
    {
        const char* dialog_menu[] = {
            "1. Initialize the number",
            "2. Output current number",
            "3. Output complementary binary form",
            "4. Summarize numbers",
            "5. Increase current number on 1",
            "6. Decrease current number on 1",
            "7. Output current numbers sign"
        };
        for (int i = 0; i < 7; i++)
        {
            std::cout << dialog_menu[i] << std::endl;
        }
    }

    bool get_command(int& a) {
        const char* err = "";
        int n = 0;
        n = 0;
        cout << err;
        //err = ERMSG;
        if (get_num(n, "Enter command --> ")) {
            return false;
        }
        std::cout << endl;
        if (n <= 0 || n > 9)
            return false;
        a = n;
        return true;
    }

    void calc(int num, DoubNum& item) {
        switch (num) {
        case 1:
            dialog_Input(item);
            break;
        case 2:
            dialog_Output(item);
            break;
        case 3:
            dialog_DopCode(item);
            break;
        case 4:
            dialog_Sum(item);
            break;
        case 5:
            dialog_Inc(item);
            break;
        case 6:
            dialog_Dec(item);
            break;
        case 7:
            dialog_Sign(item);
            break;
        default:
            cout << "Some thing's wrong... I can feel it." << endl;
            break;
        }
    }
};
