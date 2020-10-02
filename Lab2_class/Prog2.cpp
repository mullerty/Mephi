#include "Prog2.h"
#include <cmath>
#include <iostream>
#include <string.h>
//#include <stdio.h>
//#include <cstring>

namespace prog2{

    ////////////////////       Evolvent funcs
    // setters
    Evolvent::Evolvent(long double const a, long double x, long double y){
        this->a = a;
        this->cords = Point(x, y);
    }

    Evolvent::Evolvent(long double const a, Point const coords){
        this->a = a;
        this->cords = coords;
    }
  
    int Evolvent::change_params(long double const a){
        this->a = a;
        return 0;
    }

    int Evolvent::change_coords(Point const coords)
    {
      this->cords = coords;
      return 0;
    }

    //getters
    void Point::print_coords(){
        std::cout << "(" << x << ", " << y << ")";
    }

    int Evolvent::get_params(long double &a) const{
        a = this->a;
        return 0;
    }

    int Evolvent::get_coords(Point &coords) const{
        coords = this->cords;
        return 0;
    }

    //main executors
    long double Evolvent::distance_to_center(long double const phi) const{
        return a*sqrt(1+phi*phi);
    }

    Point Evolvent::dot(long double const phi) const{
        Point p = Point(a*cos(phi) + a*phi*sin(phi) - cords.x, a*sin(phi) - a*phi*cos(phi) - cords.y);
        return p;
    }

    /*char * Evolvent::get_equation() const{

        long double a;
        Point coord;
        get_params(a);
        get_coords(coord);
      
        int l;
        char buf[200];

        if (a == 0){
            l = sprintf_s(buf, "dot with coordinates(%.2Lf, %.2Lf)", coord.x, coord.y);
        }
        else if ((coord.x == 0) && (coord.y == 0))
        {
          l = sprintf_s(buf, "X = %.2Lf*cos(phi) + %.2Lf*phi*sin(phi); Y = %.2Lf*sin(phi) - %.2Lf*phi*cos(phi)", a, a, a, a);
        }
        else if (coord.x != 0)
        { 
            if (coord.x < 0)
                l = sprintf_s(buf, "X = %.2Lf*cos(phi) + %.2Lf*phi*sin(phi) + %.2Lf; Y = %.2Lf*sin(phi) - %.2Lf*phi*cos(phi)", a, a, abs(coord.x), a, a);
            else
                l = sprintf_s(buf, "X = %.2Lf*cos(phi) + %.2Lf*phi*sin(phi) - %.2Lf; Y = %.2Lf*sin(phi) - %.2Lf*phi*cos(phi)", a, a, abs(coord.x), a, a);
        }
        else if(coord.y != 0)
        {
            if (coord.y < 0)
                l = sprintf_s(buf, "X = %.2Lf*cos(phi) + %.2Lf*phi*sin(phi); Y = %.2Lf*sin(phi) - %.2Lf*phi*cos(phi) + %.2Lf", a, a, a, a, abs(coord.x));
            else
                l = sprintf_s(buf, "X = %.2Lf*cos(phi) + %.2Lf*phi*sin(phi); Y = %.2Lf*sin(phi) - %.2Lf*phi*cos(phi) - %.2Lf", a, a, a, a, abs(coord.x));
        }
        else if (coord.y != 0 || coord.x != 0)
        {
            if (coord.y < 0 || coord.x < 0)
                l = sprintf_s(buf, "X = %.2Lf*cos(phi) + %.2Lf*phi*sin(phi); Y = %.2Lf*sin(phi) - %.2Lf*phi*cos(phi) + %.2Lf", a, a, a, a, abs(coord.x));
            else
                l = sprintf_s(buf, "X = %.2Lf*cos(phi) + %.2Lf*phi*sin(phi); Y = %.2Lf*sin(phi) - %.2Lf*phi*cos(phi) - %.2Lf", a, a, a, a, abs(coord.x));
        }
        buf[++l] = '\0';
        char *end = new char[l];
        end[0] = '\0';
        strcat_s(end, l, buf);
    
        return end;
     }*/

    char * Evolvent::get_polar_equation() const{
        long double a;
        Point coord;
        get_params(a);
        get_coords(coord);
          
        int l;
        char buf[200];

        if (a == 0){
            //l = sprintf_s(buf, "dot with coordinates(%.2Lf, %.2Lf)", coord.x, coord.y);
            l = sprintf_s(buf, "r^2 = 0, dot with coordinates(%.2Lf, %.2Lf)", coord.x, coord.y);
        }
        else
        {
            l = sprintf_s(buf, "r^2 = %.2Lf*(1 + phi^2), with center in (%.2Lf, %.2Lf)", a*a, coord.x, coord.y);
        }
        buf[++l] = '\0';
        char *end = new char[l];
        end[0] = '\0';
        strcat_s(end, l, buf);
        
        return end;
    }

    long double Evolvent::arc(long double const phi) const{
      return a*phi*phi/2;
    }

    long double Evolvent::rad_of_curvature(long double const phi) const{
        return a*phi;
    }

    ////////////////////       Dialog funcs
    // setters
    int dialog_chage_params(Evolvent &line)
    {
      long double a;
      if (get_num(a, "Enter new a --> "))
          return 1;
      line.change_params(a);
      return 0;
    }

    int dialog_change_coords(Evolvent &line){
            long double x,y;
            get_num(x,"Enter x coord --> ");
            get_num(y,"Enter y coord --> ");

            Point cd(x,y);
            line.change_coords(cd);
            return 0;
        }

    //getters
    int dialog_get_params(Evolvent &line)
    {
      long double a;
      line.get_params(a);
      std::cout << "a: " << a << std::endl;
      return 0;
    }

    int dialog_get_coords(Evolvent &line)
    {
      Point cd;
      line.get_coords(cd);
      std::cout << "coords: ";
      cd.print_coords();
      std::cout << std::endl;
      return 0;
    }

    int dialog_distance_to_center(Evolvent &line){
        long double phi;
        get_num(phi,"Enter phi angle --> ");
        std::cout << "Distant to center is: " << line.distance_to_center(phi) << std::endl;
        return 0;
    }

    /*int dialog_get_equation(Evolvent &line){
        char *t = line.get_equation();
        std::cout << "Equation: " << t << std::endl;
        delete[] t;
        return 0;
    }*/

    int dialog_get_polar_equation(Evolvent &line){
        char *t = line.get_polar_equation();
        std::cout << "Equation: " << t << std::endl;
        delete[] t;
        return 0;
    }

    int dialog_arc(Evolvent &line){
        long double phi;
        get_num(phi, "Enter phi angle --> ");
        std::cout << "Arc length: " << line.arc(phi) << std::endl;
        return 0;
    }

    int dialog_rad_of_curvature(Evolvent &line){
        long double phi;
        get_num(phi, "Enter phi angle --> ");
        std::cout << "Radius of curvatured: " << line.rad_of_curvature(phi) << std::endl;
        return 0;
    }
  
    int dialog_dot(Evolvent &line){
        long double phi;
        get_num(phi, "Enter phi angle --> ");
        Point cd = line.dot(phi);
        printf_s("Here coords of your dot: (%.2Lf, %.2Lf)", cd.x, cd.y);
        std::cout << std::endl;
        return 0;
    }
  
    ////////////////////       Dialog  display funcs

    void display_menu()
    {
        const char* dialog_menu[]  = {
            "1. Change parameters",
            "2. Change coordinates",
            "3. Get parameters",
            "4. Get coordinates",
            "5. Get distance to center",
           // "6. Get equation",
            "6. Get polar equation",
            "7. Get arc length",
            "8. Get the dot coords",
            "9. Get radius of curvature",
        };
      for (int i=0; i<9; i++)
      {
        std::cout << dialog_menu[i] << std::endl;
      }
    }

    bool get_command(int &a){
        const char *err = "";
        int n = 0;
        n=0;
        cout << err;
        //err = ERMSG;
        if (get_num(n, "Enter command --> ")){
            return false;
        }
        if (n <= 0 || n > 9)
            return false;
        a = n;
        return true;
    }

    void calc(int num, Evolvent &line){
        switch (num) {
            case 1:
                dialog_chage_params(line);
                break;
            case 2:
                dialog_change_coords(line);
                break;
            case 3:
                dialog_get_params(line);
                break;
            case 4:
                dialog_get_coords(line);
                break;
            case 5:
                dialog_distance_to_center(line);
                break;
            case 6:
                dialog_get_polar_equation(line);
                break;
            case 7:
                dialog_arc(line);
                break;
            case 8:
                dialog_dot(line);
                break;
            case 9:
                dialog_rad_of_curvature(line);
                break;
            default:
                cout << "Some thing's wrong... I can feel it." << endl;
                break;
        }
    }
};
