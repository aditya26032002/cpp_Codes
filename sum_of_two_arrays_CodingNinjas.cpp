#include<bits/stdc++.h>
using namespace std;


// Not done
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int num1 = 0;
    for(int i = 0; i<n; i++){
        num1 += a[i] * pow(10,n-1-i);
    }
    cout<<num1;
}

int main(){
    vector<int> A = {4,5,1};
    vector<int> B = {3,4,5};
    int n = A.size();
    int m = B.size();
    vector<int> ans = findArraySum(A,n,B,m);
    // for(auto i:ans){
    //     cout<<i;
    // }
    return 0;
}