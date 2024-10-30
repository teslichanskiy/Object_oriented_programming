#include <iostream>

using namespace std;

class Complex
{
private:
    double real, imaginary;
public:
    Complex() { real = 1; imaginary = 2; }
    Complex(double re, double im) { real = re, imaginary = im; }
    friend Complex operator+(const Complex& c1, const Complex& c2); //Перегрузка операторов через дружественные функции
    friend Complex operator-(const Complex& c1, const Complex& c2);
    Complex operator*(const Complex& c) const; //Перегрузка операторов через обычные функции
    Complex operator/(const Complex& c) const;
    friend ostream& operator<<(ostream& out, const Complex& c); //Перегрузка оператора вывода через дружественную функцию
};

Complex operator+(const Complex& c1, const Complex& c2)
{
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    return sum;
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    Complex diff;
    diff.real = c1.real - c2.real;
    diff.imaginary = c1.imaginary - c2.imaginary;
    return diff;
}

Complex Complex::operator*(const Complex& c) const
{
    Complex comp;
    comp.real = real * c.real + (-1) * imaginary * c.imaginary;
    comp.imaginary = real * c.imaginary + c.real * imaginary;
    return comp;
}

Complex Complex::operator/(const Complex& c) const
{
    Complex frac;
    frac.real = (real * c.real + imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary);
    frac.imaginary = (c.real * imaginary + (-1) * real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary);
    return frac;
}

ostream& operator<<(ostream& out, const Complex& c)
{
    if (c.imaginary == 0)
        out << c.real << endl;
    if (c.imaginary == 1)
        out << c.real << "+i" << endl;
    if (c.imaginary == -1)
        out << c.real << "-i" << endl;
    if (c.imaginary < 0 && c.imaginary != -1)
        out << c.real << c.imaginary << "i" << endl;
    if (c.imaginary > 0 && c.imaginary != 1)
        out << c.real << "+" << c.imaginary << "i" << endl;
    return out;
}

int main()
{
    Complex c1(3.25, -3.75)/*, c2(3, -1)*/;
    Complex c2;
    cout << "c1 = " << c1;
    cout << "c2 = " << c2 << '\n';
    cout << "c1 + c2 = " << c1 + c2;
    cout << "c1 - c2 = " << c1 - c2;
    cout << "c1 * c2 = " << c1 * c2;
    cout << "c1 / c2 = " << c1 / c2;

    return 0;
}
