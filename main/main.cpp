#include <iostream>
using namespace std;

class Employer
{
public:
    virtual void Print() = 0;
};

class President : public Employer
{
public:
    virtual void Print()
    {
        cout << "This is a president.\n";
    }
};

class Manager : public Employer
{
public:
    virtual void Print()
    {
        cout << "This is a manager.\n";
    }
};

class Worker : public Employer
{
public:
    virtual void Print()
    {
        cout << "This is a worker.\n";
    }
};

class Equation
{
public:
    virtual void roots() = 0;
};

class LinearEquation : public Equation // ax = b
{
    double a, b;
public:
    LinearEquation(double A, double B) : a(A), b(B)
    {
    }

    void roots()
    {
        if (a == 0 && b == 0)
        {
            cout << "Уравнение имеет бесконечно много корней." << "\n";
        }
        else if (a == 0 && b != 0)
        {
            cout << "Уравнение не имеет корней." << "\n";
        }
        else
        {
            double x = -b / a;
            cout << "Уравнение имеет один корень: " << x << "\n";
        }
    }
};

class QuadraticEquation : public Equation // ax^2 + bx + c = 0
{
    double a, b, c;
public:
    QuadraticEquation(double A, double B, double C) : a(A), b(B), c(C)
    {
    }

    void roots()
    {
        double D = b * b - 4 * a * c;

        if (a == 0)
        {
            LinearEquation eq(b, c);
            eq.roots();
        }
        else if (D > 0)
        {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            cout << "Уравнение имеет два корня: " << x1 << " и " << x2 << "\n";
        }
        else if (D == 0)
        {
            double x = -b / (2 * a);
            cout << "Уравнение имеет один корень: " << x << "\n";
        }
        else
        {
            cout << "Уравнение не имеет действительных корней.\n";
        }
    }
};

int main()
{
    setlocale(0, "ukr");

    Employer* employers[3] = { new President(), new Manager(), new Worker() };

    for (int i = 0; i < 3; i++)
        employers[i]->Print();

    Equation* equation[2] =
    {
        new LinearEquation(0, 5), // ax = b, 0x = 5
        new QuadraticEquation(5, 3, -26) // ax^2 + bx + c = 0, 5x^2 + 3x - 26 = 0
    };
   
    for (int i = 0; i < 2; i++)
        equation[i]->roots();
}
