#include <bits/stdc++.h>
using namespace std;

void reverseString(string &input, int s, int e)
{
    if (s >= e)
        return;
    swap(input[s], input[e]);
    reverseString(input, s + 1, e - 1);
}

// void reverseStringSinglePointer(string &input, int s)
// {
//     if (s >= input.length() / 2)
//         return;
//     swap(input[s], input[input.length() - s - 1]);
//     reverseStringSinglePointer(input, s + 1);
// }

int main()
{
    string input = "hello";
    reverseString(input, 0, input.size() - 1);
    // reverseStringSinglePointer(input, 0);
    cout << input;
    return 0;
}