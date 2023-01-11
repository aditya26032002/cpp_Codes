#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> &heights, int M, int sawHeight)
{
    int cutted = 0;
    for (int i : heights)
    {
        if (i > sawHeight)
        {
            cutted += i - sawHeight;
            if (cutted >= M)
            {
                return true;
            }
        }
    }
    return false;
}

int minHeight(vector<int> &heights, int M)
{
    sort(heights.begin(), heights.end());
    int s = 0, e = heights.back();
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossibleSol(heights, M, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    // int N,M;
    // cin>>N>>M;
    // vector<int> heights(N);
    // for(int i = 0; i<N; i++){
    //     cin>>heights[i];
    // }
    vector<int> heights = {4, 42, 40, 26, 46};
    int M = 20;

    cout << minHeight(heights, M);
    return 0;
}