#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    int i = 0, j = s.size()-1;
    while(i<j){
        if((s[i]>='A' && s[i]<='Z')){
            s[i] = s[i]-'A'+'a';
        }
        if(s[j]>='A' && s[j]<='Z'){
            s[j] = s[j]-'A'+'a';
        }
        if((s[i] >= 'a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            if((s[j] >= 'a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')){
                if(s[i] != s[j])
                    return false;
                i++;
                j--;
            }
            else
                j--;
        }
        else
            i++;
    }
    return true;
}

int main(){
    string s = "A1b22Ba";
    cout<<checkPalindrome(s);
    return 0;
}