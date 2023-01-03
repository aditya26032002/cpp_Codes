#include<bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> intersection;
    int i = 0, j = 0;
    while((i < n) && (j < m)){
        if(arr1[i] == arr2[j]){
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
        i++;
        else
        j++;
    }
    return intersection;
}

int main(){
    vector<int> arr1 = {1,2,2,2,3,4};
    vector<int> arr2 = {2,2,3,3};
    int n = 6, m = 4;
    vector<int> intersection = findArrayIntersection(arr1,n,arr2,m);
    for(int i:intersection){
        cout<<i<<" ";
    }
    return 0;
}