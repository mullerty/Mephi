#ifndef Prog2_h
#define Prog2_h

#include <stdio.h>
#include <iostream>

#endif /* Prog2_hpp */
using namespace std;
namespace prog2 {

    #define ERMSG "Incorrect input.\n"
    #define INFO "Enter a number --> "
    #define PI 3.14159265358979323846

    template <class T>
    int get_num(T &a, const char *info=INFO, const char *ermsg=ERMSG){
      cout << info;
      
      while (!(cin >> a)){
        if (cin.eof())
          return 1;
        cout << ermsg;
        cout << info;
        cin.clear();
        cin.ignore(10000, '\n');
      }
      
      return 0;
    }

    struct Point{
        long double x, y;
        
        Point(long double x, long double y) : x(x), y(y) {}
        Point() : x(0), y(0) {}

        void print_coords();
    };

    class Evolvent{
      
    private:
        long double a;
        
        Point cords;

      public:
        Evolvent() : a(0), cords(Point()) {}
        Evolvent(long double const a, long double x=0, long double y=0);
        Evolvent(long double const a, Point const cords);
//        ~Cardioid() {}; ???????????????

        // Изменения параметров кривой
        int change_params(long double const a);
        int get_params(long double &a) const;
        int get_coords(Point &coords) const;
        int change_coords(Point const coords);
        
        // Вывод формул кривой
       // char *get_equation() const;
        char *get_polar_equation() const;
        
        //Вывод расчетных значений
        long double distance_to_center(long double const phi) const;
        Point dot(long double const phi) const;
        long double rad_of_curvature(long double const phi) const;
        long double arc(long double const phi) const;
    };

    int dialog_chage_params(Evolvent&line);
    int dialog_get_params(Evolvent&line);
    int dialog_get_coords(Evolvent&line);
    int dialog_change_coords(Evolvent&line);
    int dialog_distance_to_center(Evolvent&line);
    //int dialog_get_equation(Evolvent&line);
    int dialog_get_polar_equation(Evolvent&line);
    int dialog_arc(Evolvent&line);
    int dialog_dot(Evolvent&line);
    int dialog_rad_of_curvature(Evolvent&line);

    void display_menu();

    bool get_command(int &a);

    void calc(int num, Evolvent&line);
};

