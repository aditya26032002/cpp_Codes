#include <bits/stdc++.h>
using namespace std;

void sayDigits(int number, string digits[])
{
    if (number == 0)
    {
        return;
    }
    sayDigits(number / 10, digits);
    cout << digits[number % 10] << " ";
}

int main()
{
    /*
    map<int, string> digits;
    digits[0] = "Zero";
    digits[1] = "One";
    digits[2] = "Two";
    digits[3] = "Three";
    digits[4] = "Four";
    digits[5] = "Five";
    digits[6] = "Six";
    digits[7] = "Seven";
    digits[8] = "Eight";
    digits[9] = "Nine";
    */
    string digits[10] = {"Zero",
                         "One",
                         "Two",
                         "Three",
                         "Four",
                         "Five",
                         "Six",
                         "Seven",
                         "Eight",
                         "Nine"};

    int number = 1;
    if (number == 0)
        cout << "Zero";
    else
        sayDigits(number, digits);
    return 0;
}