#include <iostream>
using namespace std;
class Complex
{
private:
    double real, img;

public:
    Complex(double real, double img) : real(real), img(img) {}

    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
    void println()
    {
        cout << " ( " << real << " , " << img << " ) " << endl;
    }
};
Complex Complex::operator+(const Complex &c)
{
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex &c)
{
    Complex temp(real - c.real, img - c.img);
}
Complex Complex::operator*(const Complex &c)
{
    Complex temp(real * real - img * c.img, c * img + img * c.real);
}
Complex Complex::operator/(const Complex &c)
{
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
int main()
{
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c = a * b;

    c.println();
}