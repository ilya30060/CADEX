#ifndef CURVES_COUNT
#define CURVES_COUNT 10
#endif // !CURVES_COUNT
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include "DLLHeader.h"
struct Point_3D
{
    double x;
    double y;
    double z;
};
int Curve::count = -1;
Curve Curve::collection[CURVES_COUNT];
Curve::Curve(double a, double b, double step) :m_a(a), m_b(b), m_step(step)
{
}

Curve* Curve::add_to_collection()
{
    ++Curve::count;
    Curve::collection[Curve::count] = *this;
    return &(Curve::collection[Curve::count]);
    /*Curve::collection.push_back(*this);
    return &(collection.back());*/
}

Point_3D Curve::get_point(double t) const
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = m_step * t / 2 / M_PI;
    std::cout << "hi";
    return a;
}

std::vector<double> Curve::get_derivative(double t) const
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(m_step / 2 / M_PI);
    std::cout << "hi";

    return temp;
}
//std::vector<Curve> Curve::collection = std::vector<Curve>(0);


//struct Point_3D Curve::get_point(double t)
//{
//    struct Point_3D a;
//    a.x = m_a * cos(t);
//    a.y = m_b * sin(t);
//    a.z = m_step * t / 2 / M_PI;
//    std::cout << "hi";
//    return a;
//}
//
//std::vector<double> Curve::get_derivative(double t)
//{
//    std::vector<double> temp;
//    temp.push_back(-m_a * sin(t));
//    temp.push_back(m_b * cos(t));
//    temp.push_back(m_step / 2 / M_PI);
//    std::cout << "hi";
//
//    return temp;
//}
Helix::Helix(double radius, double step) :Curve(radius, radius, step)
{
}
//std::vector<Helix> Helix::collection = std::vector<Helix>(0);
int Helix::count = -1;
Helix Helix::collection[CURVES_COUNT];

struct Point_3D Helix::get_point(double t) const
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = m_step * t / 2 / M_PI;
    std::cout << "H ";
    return a;
}

std::vector<double> Helix::get_derivative(double t) const
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(m_step / 2 / M_PI);

    return temp;
}

Helix* Helix::add_to_collection()
{
    ++Helix::count;
    Helix::collection[Helix::count] = *this;
    return &(Helix::collection[Helix::count]);
    /*Helix::collection.push_back(*this);
    Helix temp = Helix::collection.back();
    return &(Helix::collection.back());*/
}
//std::vector<Ellipse> Ellipse::collection = std::vector<Ellipse>(0);
int Ellipse::count = -1;
Ellipse Ellipse::collection[CURVES_COUNT];

Ellipse::Ellipse(double a, double b) :Curve(a, b, 0)
{

}

struct Point_3D Ellipse::get_point(double t) const
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = 0;
    std::cout << "E ";
    return a;
}

std::vector<double> Ellipse::get_derivative(double t) const
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(0);

    return temp;
}

Ellipse* Ellipse::add_to_collection()
{
    ++Ellipse::count;
    Ellipse::collection[Ellipse::count] = *this;
    return &(Ellipse::collection[Ellipse::count]);
    /*Ellipse::collection.push_back(*this);
    return &(collection.back());*/
}
//std::vector<Circle> Circle::collection = std::vector<Circle>(0);
int Circle::count = -1;
Circle Circle::collection[CURVES_COUNT];

Circle::Circle(double radius) :Ellipse(radius, radius)
{

}

struct Point_3D Circle::get_point(double t) const
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = 0;
    std::cout << "C ";
    return a;
}

std::vector<double> Circle::get_derivative(double t) const
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(0);

    return temp;
}

Circle* Circle::add_to_collection()
{
    ++Circle::count;
    Circle::collection[Circle::count] = *this;
    return &(Circle::collection[Circle::count]);
    /*Circle::collection.push_back(*this);
    return &(collection.back());*/
}

void Circle::populate(std::vector<Circle*>* output)
{
    for (int i = 0; i <= Circle::count; ++i)
    {
        (*output).push_back(&(Circle::collection[i]));
    }
}
std::ostream& operator<< (std::ostream& stream, std::pair<double, double> b)
{
    stream << b.first << std::endl << b.second;
    return stream;
}
std::ostream& operator<< (std::ostream& stream, std::vector<double> b)
{
    for (double element : b)
        stream << element << ' ';
    return stream;
}
std::ostream& operator<< (std::ostream& stream, struct Point_3D b)
{
    stream << b.x << ' ' << b.y << ' ' << b.z;
    return stream;
}
bool comp(Circle* i, Circle* j) {
    return i->m_a < j->m_a;
}