#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int i = 0, j = sizeof(input) / sizeof(input[0]);
    while (i < j)
    {
        while (1)
        {
            if (input[i] >= 0)
                break;
            i++;
        }
        while (1)
        {
            if (input[j] >= 0)
                break;
            j--;
        }
        if (input[i] < input[j])
            swap(input[i], input[j]);
        i++;
        j--;
    }

    for (int i = 0; i < 9; i++)
        cout << input[i] << " ";
    return 0;
}