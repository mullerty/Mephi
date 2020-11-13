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
        DoubNum() : length(0) // ����������� �� ���������
        {
            for (int i = 0; i < SIZE; i++) num[i] = '\0';
        };
        DoubNum(long int initnum); // ����������� � �������������� ����� ������
        DoubNum(char* initstring); // ����������� �  �������������� �������

        friend std::ostream& DnumOutput(std::ostream& out, DoubNum item); // ����� ���������� ������
        DoubNum DnumInput(); // ���� ���������� ������
        DoubNum& DopCodeNum(); // ������� ����� � �������� ���
        DoubNum& DnumSum(const DoubNum); // ����� �����
        DoubNum& DnumInc(); // ���������� ����� �� 1
        DoubNum& DnumDec(); // ���������� ����� �� 1
        bool DnumSign() // ����������� ����� �����
        {
            return sign;
        }; 
        bool InitializedCheck() // �������� ����� �� ������������������
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

