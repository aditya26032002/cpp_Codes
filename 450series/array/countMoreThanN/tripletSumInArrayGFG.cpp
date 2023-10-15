#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.

    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A + n);
        for (int i = 0; i < n; i++)
        {
            int req = X - A[i];
            int pt1 = i + 1, pt2 = n - 1;
            while (pt1 < pt2)
            {
                int sum = A[pt1] + A[pt2];
                if (sum == req)
                    return true;
                if (sum < req)
                    pt1++;
                else
                    pt2--;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}