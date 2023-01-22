#include <bits/stdc++.h>
using namespace std;

vector<int> unionof(int a[], int n, int b[], int m)
{
    vector<int> ans;
    set<int> temp;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        temp.insert(a[i]);
        i++;
        temp.insert(b[j]);
        j++;
    }
    while (i < n)
    {
        temp.insert(a[i]);
        i++;
    }
    while (j < m)
    {
        temp.insert(b[j]);
        j++;
    }
    for (int i : temp)
    {
        ans.push_back(i);
    }
    return ans;
}

// Not done
vector<int> intersction(int a[], int n, int b[], int m)
{
    vector<int> ans;
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[i])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
            j++;
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    return ans;
}

int main()
{
    int a[] = {85, 25, 1, 32, 54, 6};
    int b[] = {85, 2};
    // vector<int> un = unionof(a, 7, b, 2);
    // cout << "Union is : ";
    // for (int i : un)
    // {
    //     cout << i << " ";
    // }
    vector<int> intersect = intersction(a, 6, b, 2);
    cout << "\nIntersection is : ";
    for (int i : intersect)
    {
        cout << i << " ";
    }
    return 0;
}