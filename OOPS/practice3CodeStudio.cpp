#include <bits/stdc++.h>
#include <iostream>

#include <algorithm>

// Not done

using namespace std;

class Fraction
{

    // Complete the class
    int numerator, denominator;

public:
    Fraction(int num, int denom)
    {
        this->numerator = num;
        this->denominator = denom;
    }
    void add(Fraction &f2)
    {
        int num = this->numerator * f2.denominator + this->denominator * f2.numerator;
        int denom = this->denominator + f2.denominator;
        this->numerator = num;
        this->denominator = denom;
        simplify();
    }
    void multiply(Fraction &f2)
    {
        int num = this->numerator * f2.numerator;
        int denom = this->denominator * f2.denominator;
        this->numerator = num;
        this->denominator = denom;
    }
    // Not done
    void simplify()
    {
        int temp;
        if (numerator >= denominator)
            temp = numerator;
        else
            temp = denominator;
        int i = 2;
        while (i <= temp)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;
                i = 2;
                if (numerator >= denominator)
                    temp = numerator;
                else
                    temp = denominator;
            }
            else
                i++;
        }
    }
    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{

    Fraction f1(47, 71);
    Fraction f2(91, 78);

    f1.add(f2);
    f1.print();

    return 0;
}