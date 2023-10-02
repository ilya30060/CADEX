#pragma once
#ifndef CURVES_COUNT
#define CURVES_COUNT 10
#endif // !CURVES_COUNT
#define DLL_API __declspec(dllexport)

#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
const double M_PI = 3.141592653589793; // 15 знаков после точки
class DLL_API Curve;
class DLL_API Helix;
class DLL_API Ellipse;
class DLL_API Circle;
struct DLL_API Point_3D;
DLL_API std::ostream& operator<< (std::ostream&, std::pair<double, double>);
DLL_API std::ostream& operator<< (std::ostream&, std::vector<double>);
DLL_API std::ostream& operator<< (std::ostream&, struct Point_3D);
DLL_API bool comp(Circle*, Circle*);
class  Curve
{
    static Curve collection[CURVES_COUNT];
    static int count;
protected:
    Curve(double, double, double);

    Curve* add_to_collection();
public:
    Curve() {}

    double m_step;
    double m_a;
    double m_b;
    virtual struct Point_3D get_point(double t) const;
    virtual std::vector<double> get_derivative(double t) const;
};
class Helix : public Curve
{
    //static std::vector<Helix> collection;
    static Helix collection[CURVES_COUNT];
    static int count;
protected:

public:
    Helix() {}

    Helix(double, double);
    virtual struct Point_3D get_point(double) const override;
    virtual std::vector<double> get_derivative(double) const override;
    Helix* add_to_collection();
};
class Ellipse : public Curve
{
    //static std::vector<Ellipse> collection;
    static Ellipse collection[CURVES_COUNT];
    static int count;
protected:

public:
    Ellipse() {}

    Ellipse(double, double);
    virtual struct Point_3D get_point(double) const override;
    virtual std::vector<double> get_derivative(double) const override;
    Ellipse* add_to_collection();

};
class Circle : public Ellipse
{
    //static std::vector<Circle> collection;
    static Circle collection[CURVES_COUNT];
    static int count;
protected:

public:

    Circle() {}

    Circle(double);
    virtual struct Point_3D get_point(double) const override;
    virtual std::vector<double> get_derivative(double) const override;
    Circle* add_to_collection();
    static void populate(std::vector<Circle*>*);
};