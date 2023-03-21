#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class ComplexNumbers
{
    // Complete this class
    int real, imaginary;

public:
    ComplexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    ComplexNumbers plus(ComplexNumbers c2)
    {
        this->real += c2.real;
        this->imaginary += c2.imaginary;
    }
    ComplexNumbers multiply(ComplexNumbers c2)
    {
        int real = (this->real * c2.real) - (this->imaginary * c2.imaginary);
        int img = ((this->real * c2.imaginary) + (this->imaginary * c2.real));
        this->real = real;
        this->imaginary = img;
    }
    void print()
    {
        if (this->imaginary >= 0)
            cout << this->real << " + i" << this->imaginary;
        else
            cout << this->real << " - i" << abs(this->imaginary);
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
}