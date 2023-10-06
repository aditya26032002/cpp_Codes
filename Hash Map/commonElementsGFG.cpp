#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        unordered_map<int, bool> mpA, mpB, mpC;
        vector<int> ans;

        for (int i = 0; i < n1; i++)
            mpA[A[i]] = true;

        for (int i = 0; i < n2; i++)
            mpB[B[i]] = true;

        for (int i = 0; i < n3; i++)
        {
            if (mpA[C[i]] && mpB[C[i]])
            {
                ans.push_back(C[i]);
                mpA[C[i]] = false;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}