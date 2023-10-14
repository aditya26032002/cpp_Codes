#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> commonEls;
        int pt1, pt2, pt3;
        pt1 = pt2 = pt3 = 0;
        while (pt1 < n1 && pt2 < n2 && pt3 < n3)
        {
            while (pt2 < n2 && B[pt2] <= A[pt1])
            {
                if (B[pt2] == A[pt1])
                    break;
                pt2++;
            }
            while (pt3 < n3 && C[pt3] <= A[pt1])
            {
                if (C[pt3] == A[pt1])
                    break;
                pt3++;
            }
            int size = commonEls.size();
            if ((A[pt1] == B[pt2]) && (A[pt1] == C[pt3]))
            {
                if (size != 0 && A[pt1] != commonEls[size - 1])
                {
                    commonEls.push_back(A[pt1]);
                }
                else if (size == 0)
                    commonEls.push_back(A[pt1]);
            }
            pt1++;
        }
        return commonEls;
    }
};

int main()
{
    return 0;
}