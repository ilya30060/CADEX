// Application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#ifndef CURVES_COUNT
#define CURVES_COUNT 10
#endif // !CURVES_COUNT
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include "Application.h"

int main()
{
    srand(time(nullptr));
    std::cout << "Tip:\nH = Helix\nE = Ellipse\nC = Circle\n";
    int random = 0;
    std::vector<Curve*> first_container;
 
    for (int i = 0; i < CURVES_COUNT; ++i)
    {
        random = rand();
        if (random % 3 == 0)
        {
            first_container.push_back((Helix(rand() % 200, rand() % 200)).add_to_collection());
        }
        else if (random % 3 == 1)
        {
            first_container.push_back((Ellipse(rand() % 200, rand() % 200)).add_to_collection());
        }
        else if (random % 3 == 2)
        {
            first_container.push_back((Circle(rand() % 200)).add_to_collection());
        }
    }
    for (int i = 0; i < CURVES_COUNT; ++i)
    {
        std::cout << i + 1 << ". Parameters(m_a, m_b, m_step):" << first_container[i]->m_a << ' ' << first_container[i]->m_b << ' ' << first_container[i]->m_step << "\nPoint(XYZ) at PI/4: " << first_container[i]->get_point(M_PI / 4) << "\nDerivative(XYZ-vector) at PI/4:" << first_container[i]->get_derivative(M_PI / 4) << "\n\n";
    }
    std::cout << "Circles:\n";
    std::vector<Circle*> second_container;
    Circle::populate(&second_container);
    for (int i = 0; i < second_container.size(); ++i)
    {
        std::cout << i + 1 << ". Parameters(m_a, m_b, m_step):" << second_container[i]->m_a << ' ' << second_container[i]->m_b << ' ' << second_container[i]->m_step << "\nPoint(XYZ) at PI/4: " << second_container[i]->get_point(M_PI / 4) << "\nDerivative(XYZ-vector) at PI/4:" << second_container[i]->get_derivative(M_PI / 4) << "\n\n";
    }
    std::sort(second_container.begin(), second_container.end(), comp);
    std::cout << "Now sorted circles:\n";
    double sum_radii = 0;
    for (int i = 0; i < second_container.size(); ++i)
    {
        sum_radii += second_container[i]->m_a;
        std::cout << i + 1 << ". Parameters(m_a, m_b, m_step):" << second_container[i]->m_a << ' ' << second_container[i]->m_b << ' ' << second_container[i]->m_step << "\nPoint(XYZ) at PI/4: " << second_container[i]->get_point(M_PI / 4) << "\nDerivative(XYZ-vector) at PI/4:" << second_container[i]->get_derivative(M_PI / 4) << "\n\n";
    }
    std::cout << "And their radii sum: " << sum_radii << std::endl;
}

