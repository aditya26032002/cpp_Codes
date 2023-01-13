#include<bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int carry = 0;
    int i = n-1, j = m-1;
    vector<int> ans;
    while(i>=0 && j>=0){
        int sum = a[i] + b[j] + carry;
        carry = sum/10;
        cout<<"Pushing -> "<<sum%10<<endl;
        ans.push_back(sum%10);
        i--;
        j--;
    }
    while(i>=0){
        int sum = a[i] + carry;
        carry = sum/10;
        cout<<"Pushing : "<<sum%10<<endl;
        ans.push_back(sum%10);
        i--;
    }
    while(j>=0){
        int sum = b[j] + carry;
        carry = sum/10;
        cout<<"Pushing :: "<<sum%10<<endl;
        ans.push_back(sum%10);
        j--;
    }
    if(carry){
        ans.push_back(carry);
    }
    for(i = 0, j = ans.size()-1; i<j; i++, j--){
        swap(ans[i], ans[j]);
    }
    return ans;
}

int main(){
    vector<int> A = {1,2,3,4};
    vector<int> B = {6};
    int n = A.size();
    int m = B.size();
    vector<int> ans = findArraySum(A,n,B,m);
    
    for(auto i:ans){
        cout<<i;
    }
    return 0;
}