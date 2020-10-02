#include "pch.h"
#include <C:\Users\Amr\source\repos\Lab2_class\Lab2_class\Prog2.h>
#include <cmath>
#include <iostream>
#include <string.h>

using namespace prog2;

TEST(EvolventTest, ParameterTest)
{
    Evolvent line;
    long double c;
    line.change_params(1000000);
    line.get_params(c);
    EXPECT_EQ(c, 1000000);

    line.change_params(0);
    line.get_params(c);
    EXPECT_EQ(c, 0);

    line.change_params(-1000000);
    line.get_params(c);
    EXPECT_EQ(c, -1000000);
}

TEST(EvolventTest, ConstructorTest)
{
    long double c;
    Point cd;
    Evolvent line1;
    line1.get_coords(cd);
    line1.get_params(c);
    EXPECT_EQ(c, 0);
    EXPECT_EQ(cd.x, 0);
    EXPECT_EQ(cd.y, 0);

    Evolvent line2(1, 3);
    line2.get_coords(cd);
    line2.get_params(c);
    EXPECT_EQ(c, 1);
    EXPECT_EQ(cd.x, 0);
    EXPECT_EQ(cd.y, 0);

    Evolvent line3(-2, 6, 12);
    line3.get_coords(cd);
    line3.get_params(c);
    EXPECT_EQ(c, -2);
    EXPECT_EQ(cd.x, 6);
    EXPECT_EQ(cd.y, 12);

    Evolvent line4((long double)-2.0, Point(4, 4));
    line4.get_coords(cd);
    line4.get_params(c);
    EXPECT_EQ(c, -2);
    EXPECT_EQ(cd.x, 4);
    EXPECT_EQ(cd.y, 4);
}

TEST(EvolventTest, CoordenatesTest)
{
    Point cd;
    Evolvent line;
    line.get_coords(cd);
    EXPECT_EQ(cd.x, 0);
    EXPECT_EQ(cd.y, 0);

    line.change_coords(Point(5, 6));
    line.get_coords(cd);
    EXPECT_EQ(cd.x, 5);
    EXPECT_EQ(cd.y, 6);

    line.change_coords(Point(-5, -6));
    line.get_coords(cd);
    EXPECT_EQ(cd.x, -5);
    EXPECT_EQ(cd.y, -6);
}

TEST(EvolventTest, DotTest)
{
    long double phi;
    Point point;
    Evolvent line;

    phi = 0;
    point = line.dot(phi);
    EXPECT_EQ(point.x, 0);
    EXPECT_EQ(point.y, 0);

    phi = 1.57079;
    point = line.dot(phi);
    EXPECT_EQ(point.x, 0);
    EXPECT_EQ(point.y, 0);

    phi = 3.14159;
    point = line.dot(phi);
    EXPECT_EQ(point.x, 0);
    EXPECT_EQ(point.y, 0);

    line.change_params(2);

    phi = 0;
    point = line.dot(phi);
    EXPECT_EQ(point.x, 2);
    EXPECT_EQ(point.y, 0);

    phi = 1.57079;
    point = line.dot(phi);
    EXPECT_EQ(point.x, 3.14);
    EXPECT_EQ(point.y, 2);

    phi = 3.14159;
    point = line.dot(phi);
    EXPECT_EQ(point.x, -2);
    EXPECT_EQ(point.y, 6.28);

    line.change_coords(Point(1, -1));

    phi = 0;
    point = line.dot(phi);
    EXPECT_EQ(point.x, 1);
    EXPECT_EQ(point.y, 1);

    phi = 1.57079;
    point = line.dot(phi);
    EXPECT_EQ(point.x, 2.14);
    EXPECT_EQ(point.y, 3);

    phi = 3.14159;
    point = line.dot(phi);
    EXPECT_EQ(point.x, -3);
    EXPECT_EQ(point.y, 7.28);
}

TEST(EvolventTest, Rad_of_curvatureTest)
{

    long double phi, a;
    Evolvent line;

    phi = 0;
    a = line.rad_of_curvature(phi);
    EXPECT_EQ(a, 0);

    phi = 1.57079;
    a = line.rad_of_curvature(phi);
    EXPECT_EQ(a, 0);

    phi = 3.14159;
    a = line.rad_of_curvature(phi);
    EXPECT_EQ(a, 0);

    line.change_params(2);

    phi = 0;
    a = line.rad_of_curvature(phi);
    EXPECT_EQ(a, 0);

    phi = 1.57079;
    a = line.rad_of_curvature(phi);
    EXPECT_EQ(a, 3.14);

    phi = 3.14159;
    a = line.rad_of_curvature(phi);
    EXPECT_EQ(a, 6.283);

}

TEST(EvolventTest, ArcTest)
{
    long double phi, a;
    Evolvent line;

    phi = 0;
    a = line.arc(phi);
    EXPECT_EQ(a, 0);

    phi = 1.57079;
    a = line.arc(phi);
    EXPECT_EQ(a, 0);

    phi = 3.14159;
    a = line.arc(phi);
    EXPECT_EQ(a, 0);

    line.change_params(2);

    phi = 0;
    a = line.arc(phi);
    EXPECT_EQ(a, 0);

    phi = 1.57079;
    a = line.arc(phi);
    EXPECT_EQ(a, 2.467);

    phi = 3.14159;
    a = line.arc(phi);
    EXPECT_EQ(a, 9.869);
}

TEST(EvolventTest, PolarEquationTest)
{
    Evolvent line;
    const char* t;

    char tmp[200] = "r^2 = 0, dot with coordinates(0, 0)";
    line.change_params(0);
    t = line.get_polar_equation();
    EXPECT_STRCASEEQ(t, tmp);
    delete t;

    char tmp[200] = "r^2 = 4*(1 + phi^2), with center in (0, 0)";
    line.change_params(2);
    t = line.get_polar_equation();
    EXPECT_STRCASEEQ(t, tmp);
    delete t;

    char tmp[200] = "r^2 = 4*(1 + phi^2), with center in (0, 0)";
    line.change_params(-2);
    t = line.get_polar_equation();
    EXPECT_STRCASEEQ(t, tmp);
    delete t;

    line.change_coords(Point(2, 3));

    char tmp[200] = "r^2 = 0, dot with coordinates(2, 3)";
    line.change_params(0);
    t = line.get_polar_equation();
    EXPECT_STRCASEEQ(t, tmp);
    delete t;

    char tmp[200] = "r^2 = 1*(1 + phi^2), with center in (2, 3)";
    line.change_params(1);
    t = line.get_polar_equation();
    EXPECT_STRCASEEQ(t, tmp);
    delete t;

    char tmp[200] = "r^2 = 1*(1 + phi^2), with center in (2, 3)";
    line.change_params(-1);
    t = line.get_polar_equation();
    EXPECT_STRCASEEQ(t, tmp);
    delete t;

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}