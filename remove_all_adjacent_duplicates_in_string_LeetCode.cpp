#include<bits/stdc++.h>
using namespace std;

// Not done
string removeDuplicates(string s) {
    string ans = s;
    int i = 0;
    while(ans.size() != 0 && i<ans.size()-1){
        cout<<"i: "<<i<<endl;
        if(ans[i] == ans[i+1]){
            ans.erase(i,i+1);
            i=0;
            cout<<ans<<endl;
        }
        else{
            i++;
        }
    }
    return ans;
}

int main(){
    string s = "abbaca";
    string ans = removeDuplicates(s);
    for(auto i:ans){
        cout<<i;
    }
    return 0;
}