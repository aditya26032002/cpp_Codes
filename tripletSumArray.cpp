#include <bits/stdc++.h>
using namespace std;

void triplet(int arr[], int size, int sum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == sum)
                {
                    cout << "Found triplet : " << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
                }
            }
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 12;
    triplet(arr, 10, sum);
    return 0;
}