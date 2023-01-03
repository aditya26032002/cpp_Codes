#include <bits/stdc++.h>
using namespace std;

// By counting num of 0's and 1's
// void sort012(int *arr, int n)
// {
//     int num0 = 0, num1 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (*(arr + i) == 0)
//             num0++;
//         else if (*(arr + i) == 1)
//             num1++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (num0)
//         {
//             *arr = 0;
//             num0--;
//         }
//         else if (num1)
//         {
//             *arr = 1;
//             num1--;
//         }
//         else
//             *arr = 2;

//         *arr++;
//     }
// }

// By traversing and swapping 0's at first traversal then
// after it, traverse and swap for 1's
void sort012(int *arr, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
    for (int i = j; i < n; i++)
    {
        if (arr[i] == 1)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}

int main()
{
    int arr[6] = {0, 1, 2, 2, 1, 0};
    sort012(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}