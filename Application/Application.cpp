// Application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define CURVES_COUNT 10
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <time.h>

const double M_PI = 3.141592653589793; // 15 знаков после точки
//double SIN(double);
class Curve;
class Helix;
class Ellipse;
class Circle;

struct Point_3D
{
    double x;
    double y;
    double z;
};


class Curve
{
    
protected:
    Curve(double, double, double);   
public:

    const double m_step;
    const double m_a;
    const double m_b;
    virtual struct Point_3D get_point(double);
    virtual std::vector<double> get_derivative(double);
};

Curve::Curve(double a, double b, double step) :m_a(a), m_b(b), m_step(step)
{
}

struct Point_3D Curve::get_point(double t)
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = m_step * t / 2 / M_PI;
    std::cout << "hi";
    return a;
}

std::vector<double> Curve::get_derivative(double t)
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(m_step / 2 / M_PI);
    std::cout << "hi";

    return temp;
}



class Helix : public Curve
{
public:
    Helix(double, double);
    virtual struct Point_3D get_point(double) override;
    virtual std::vector<double> get_derivative(double) override;
};

Helix::Helix(double radius, double step) :Curve(radius, radius, step)
{

}

struct Point_3D Helix::get_point(double t)
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = m_step * t / 2 / M_PI;
    return a;
}

std::vector<double> Helix::get_derivative(double t)
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(m_step / 2 / M_PI);

    return temp;
}

class Ellipse : public Curve
{
public:
    Ellipse(double, double);
    virtual struct Point_3D get_point(double) override;
    virtual std::vector<double> get_derivative(double) override;
};

Ellipse::Ellipse(double a, double b) :Curve(a, b, 0)
{

}

struct Point_3D Ellipse::get_point(double t)
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = 0;
    return a;
}

std::vector<double> Ellipse::get_derivative(double t)
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(0);

    return temp;
}

class Circle : public Ellipse
{
public:
    Circle(double);
    virtual struct Point_3D get_point(double) override;
    virtual std::vector<double> get_derivative(double) override;
};

Circle::Circle(double radius) :Ellipse(radius, radius)
{

}

struct Point_3D Circle::get_point(double t)
{
    struct Point_3D a;
    a.x = m_a * cos(t);
    a.y = m_b * sin(t);
    a.z = 0;
    return a;
}

std::vector<double> Circle::get_derivative(double t)
{
    std::vector<double> temp;
    temp.push_back(-m_a * sin(t));
    temp.push_back(m_b * cos(t));
    temp.push_back(0);

    return temp;
}

//std::pair<double, double> Curve::Point_2D(double t)
//{
//    double x, y;
//    x = m_a * cos(t);
//    y = m_b * sin(t);
//    return std::pair<double, double>(x, y);
//}










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



//double SIN(double radians)
//{
//    while (radians < 0)
//        radians += 2 * M_PI;
//    while (radians >= 2 * M_PI)
//        radians -= 2 * M_PI;
//
//    if (radians >= 0 && radians <= M_PI / 2)
//}



int main()
{
    srand(time(NULL));
    int random = 0;
    std::vector<Curve> collection;
    for (int i = 0; i < CURVES_COUNT; ++i)
    {
        random = rand();
        if (random % 3 == 0)
        {
            collection.push_back(Helix(rand() % 200, rand() % 200));
        }
        else if (random % 3 == 1 || random % 3 == -1)
        {
            collection.push_back(Ellipse(rand() % 200, rand() % 200));

        }
        else if (random % 3 == 2 || random % 3 == -2)
        {
            collection.push_back(Circle(rand() % 200));

        }
    }

    for (Curve curve : collection)
    {
        std::cout << curve.m_a << ' ' << curve.m_b << ' ' << curve.m_step << " Point " << curve.get_point(M_PI / 4) << " derivative " << curve.get_derivative(M_PI / 4) << '\n';
    }
}

