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
        DoubNum(): length(0) // ����������� �� ���������
        {
            for (int i = 0; i < SIZE; i++) num[i] = '\0';
        };
        DoubNum(long int initnum); // ����������� � �������������� ����� ������
        DoubNum(char* initstring); // ����������� �  �������������� �������

        friend std::ostream& DnumOutput(std::ostream& out, DoubNum& item); // ����� ���������� ������
        DoubNum DnumInput(int ch); // ���� ���������� ������
        void DopCodeNum(); // ������� ����� � �������� ���
        DoubNum DnumSum(); // ����� �����
        char DnumInc(); // ���������� ����� �� 1
        char DnumDec(); // ���������� ����� �� 1
        bool DnumSign(); // ����������� ����� �����
        bool InitializedCheck(); // �������� ����� �� ������������������


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

