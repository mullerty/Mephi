#include "static_Prog3.h"
#include <cmath>
#include <iostream>
#include <string.h>
//#include <stdio.h>
//#include <cstring>

namespace prog3 {

    DoubNum::DoubNum(long int initnum) // Конструктор с инициализацией целым числом
    {
        for (int i = 0; i < SIZE; i++) num[i] = '\0';
        length = 0;
        if (initnum >= 0) sign = true;
        else sign = false;
        while (initnum != 0) 
        {
            num[length] = (abs(initnum) % 2) + '0';
            initnum /= 2;
            ++length;   
        }
    };

    DoubNum::DoubNum(char* initstring) // Конструктор с  инициализацией строкой
    {
        length = 0;
        while (initstring[length] != '\0')
        {
            ++length;
            num[length] = initstring[length];
        }  
    };

    std::ostream& DnumOutput(std::ostream& out, DoubNum item) // Вывод экземпляра класса
    {
        if (item.sign) out << "0.";
        else out << "1.";
        for (int i = item.length-1; i >= 0; i--) 
            out << item.num[i];
        out << endl;
        return out;
    };
    
    DoubNum DoubNum::DnumInput() // Ввод экземпляра класса
    {
        int initnum;
        char initstr[SIZE];
        for (int i = 0; i < SIZE; i++) initstr[i] = '\0';
        get_num(initnum, "Enter number --> ");
        return DoubNum(initnum);
    };

    void DoubNum::AntiOverflow(DoubNum& a) 
    {
        short i = 0, p = 0, b = 1;
        while (i < a.length) 
        {
            if (i > 0 && b == 1) b = 0;
            int sum = p + b + a.num[i] - '0';
            if (sum != 0)
                p = (sum + 1) % 2;
            a.num[i] = '0' + sum%2;
            ++i;
        }
    }

    DoubNum& DoubNum::DopCodeNum() // Перевод числа в двоичный код
    {
        DoubNum a = *this;
        if (!a.DnumSign())
        {
            for (int i = 0; i < a.length; i++)
                if (a.num[i] == '1') a.num[i] = '0';
                else a.num[i] = '1';

            if (a.num[0] == '0') a.num[0] = '1';
            else AntiOverflow(a);
        }
        
        return a;
    };                                                   
                                                     
//Дописать
    DoubNum& DoubNum::DnumSum(const DoubNum b) // Сумма чисел            
    {                                                    
        DoubNum t = b;

        short i = 0, p = 0;
        while (i < length)
        {
            short sum = p + b.num[i] - '0' + num[i] - '0';
            if (sum != 0)
                p = (sum + 1) % 2;
            t.num[i] = '0' + sum % 2;
            ++i;
        }
        i = 0;
        short j = 0;
        if (!sign) i = 1;
        if (!b.sign) j = 1;
        if ((i+j+p)%2 == 1) t.sign = false;
        else t.sign = true;

        return t;
    };

    DoubNum& DoubNum::DnumInc() // Увеличение числа на 1
    {
        DoubNum a = *this;
        DoubNum b = DoubNum(1);
        SameLength(a, b);
        DoubNum sum = a.DnumSum(b);

        return sum;

        return a;
    }

    DoubNum& DoubNum::DnumDec() // Уменьшение числа на 1
    {
        DoubNum a = *this;
        DoubNum b = DoubNum(-1);
        SameLength(a, b);
        b = b.DopCodeNum();
        DoubNum sum = a.DnumSum(b);

        return sum;
    };

    void SameLength(DoubNum& a, DoubNum& b)
    {
        if (a.length > b.length)
        {
            for (int i = b.length; i < a.length; i++) 
                b.num[i] = '0';
            b.length = a.length;
        } 
        else if (a.length < b.length) 
             {
                for (int i = a.length; i < b.length; i++) 
                    a.num[i] = '0';
                a.length = b.length;
             }     
    };

    // Дилоговые функции

    int dialog_Input(DoubNum& item)
    {           
        item = item.DnumInput();
        return 0;
    };

    int dialog_Output(DoubNum& item)
    {

        if (item.InitializedCheck())
        {
            std::cout << "Your number: ";
            DnumOutput(std::cout, item);
        }
        else std::cout << "Number is empty! Initialize it, please." << endl;

        return 0;
    };

    int dialog_DopCode(DoubNum& item)
    {
        DoubNum a = item;
        if (a.InitializedCheck()) 
        {
            a = a.DopCodeNum();
            std::cout << "Here your number (DopCode): ";
            DnumOutput(std::cout, a);
            std::cout << endl;
            a = a.DopCodeNum();
            std::cout << "Here your increased number (PrCode): ";
            DnumOutput(std::cout, a);
            std::cout << endl;
        }
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    int dialog_Sum(DoubNum& item)
    {
        DoubNum a = item;
        DoubNum b = DoubNum();
        b = b.DnumInput();
        
        if (a.InitializedCheck() && b.InitializedCheck())
        {
            SameLength(a,b);
            a = a.DopCodeNum();
            b = b.DopCodeNum();
            DoubNum sum = a.DnumSum(b);
            std::cout << "Here your sum (DopCode): ";
            DnumOutput(std::cout, sum);
            std::cout << endl;
            sum = sum.DopCodeNum();
            std::cout << "Here your sum (PrCode): ";
            DnumOutput(std::cout, sum);
            std::cout << endl;
        }
            
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    int dialog_Inc(DoubNum& item)
    {
        DoubNum a = item.DopCodeNum();
        if (item.InitializedCheck())
        {
            a = a.DnumInc();
            std::cout << "Here your increased number (DopCode): ";
            DnumOutput(std::cout, a);
            std::cout << endl;
            a = a.DopCodeNum();
            std::cout << "Here your increased number (PrCode): ";
            DnumOutput(std::cout, a);
            std::cout << endl;
        }
        else std::cout << "Error! Number is empty!" << endl;

        return 0;
    };

    int dialog_Dec(DoubNum& item)
    {
        DoubNum a = item.DopCodeNum();
        if (item.InitializedCheck())
        {
            a = a.DnumDec();
            std::cout << "Here your decreased number (DopCode): ";
            DnumOutput(std::cout, a);
            std::cout << endl;
            a = a.DopCodeNum();
            std::cout << "Here your decreased number (PrCode): ";
            DnumOutput(std::cout, a);
            std::cout << endl;
        }    
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
