#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int findSumForWindow(vector<int> &arr, int size, int k, int &remainingSize)
{
    int maxIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    int sum = arr[maxIndex], itemsDeleted = 1;
    arr[maxIndex] = -1;
    int left = k, right = k, index = maxIndex - 1;
    while (left-- && index >= 0 && arr[index] != -1)
    {
        sum += arr[index];
        arr[index] = -1;
        index--;
        itemsDeleted++;
    }
    index = maxIndex + 1;
    while (right-- && index < size && arr[index] != -1)
    {
        sum += arr[index];
        arr[index] = -1;
        index++;
        itemsDeleted++;
    }
    // cout << "Items deleted : " << itemsDeleted << endl;
    remainingSize -= itemsDeleted;
    return sum;
}

void toggle(string &booleanNum)
{
    int len = booleanNum.length();
    for (int i = 0; i < len; i++)
    {
        if (booleanNum[i] == '0')
            booleanNum[i] = '1';
        else
            booleanNum[i] = '0';
    }
}

int findXor(string A, string B)
{
    int xorVal = 0;
    int lenA = A.length(), lenB = B.length();
    int sizeA = A.length(), sizeB = B.length();
    int i = 0;
    while (sizeA-- && sizeB--)
    {
        int bit = (A[lenA - i - 1] - '0') ^ (B[lenB - i - 1] - '0');
        if (lenA > lenB)
            A[lenA - i - 1] = '0' + bit;
        else
            B[lenA - i - 1] = '0' + bit;
        i++;
    }
    if (lenA > lenB)
    {
        for (int i = 0; i < lenA; i++)
        {
            xorVal += (A[i] - '0') << (lenA - i - 1);
        }
    }
    else
    {
        for (int i = 0; i < lenA; i++)
        {
            xorVal += (B[i] - '0') << (lenA - i - 1);
        }
    }
    return xorVal;
}

int solve(vector<int> &arr, int size, string rahulA, string rahulB, string rupeshA, string rupeshB, int k)
{
    bool rahulChance = 1;
    int rahulSum = 0, rupeshSum = 0;
    int remainingSize = size;
    while (true)
    {
        if (remainingSize <= 0)
            break;

        if (rahulChance)
        {
            int tempRahulSum = findSumForWindow(arr, size, k, remainingSize);
            // cout << tempRahulSum << endl;
            rahulSum += tempRahulSum;
        }
        else
        {
            int tempRupeshSum = findSumForWindow(arr, size, k, remainingSize);
            // cout << tempRupeshSum << endl;
            rupeshSum += tempRupeshSum;
        }
        // cout << "Size rem : " << remainingSize << endl;
        rahulChance = !rahulChance;
    }

    // cout << "Rahul sum : " << rahulSum << "\nRupesh sum : " << rupeshSum << endl;

    if (rahulSum > rupeshSum)
        toggle(rahulA);
    else
        toggle(rupeshA);

    if (rahulChance)
        toggle(rupeshB);
    else
        toggle(rahulB);

    int rahulXorVal = findXor(rahulA, rahulB);
    // cout << rahulXorVal << endl;
    int rupeshXorVal = findXor(rupeshA, rupeshB);
    // cout << rupeshXorVal << endl;

    if (rahulXorVal == rupeshXorVal)
        return 2;
    if (rahulXorVal > rupeshXorVal)
        return 0;
    else
        return 1;
}

int main()
{
    string arrayElementsLine;
    getline(cin, arrayElementsLine);
    vector<int> arrayElements;

    stringstream ss(arrayElementsLine);
    int num;
    while (ss >> num)
    {
        arrayElements.push_back(num);
    }

    int RahulA, RahulB;
    cin >> RahulA >> RahulB;

    int RupeshA, RupeshB;
    cin >> RupeshA >> RupeshB;

    int k;
    cin >> k;

    // string RahulA = "01010", RahulB = "10";
    // string RupeshA = "1010", RupeshB = "01101";
    // int k = 1;
    int ans = solve(arrayElements, arrayElements.size(), to_string(RahulA), to_string(RahulB), to_string(RupeshA), to_string(RupeshB), k);
    // int ans = solve(arrayElements, arrayElements.size(), RahulA, RahulB, RupeshA, RupeshB, k);
    if (ans == 0)
        cout << "Rahul";
    if (ans == 1)
        cout << "Rupesh";
    if (ans == 2)
        cout << "Rahul\nRupesh";

    return 0;
}