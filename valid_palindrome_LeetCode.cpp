#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size()-1;
    while(i<j){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = s[i]-'A'+'a';
        }
        if(s[j]>='A' && s[j]<='Z'){
            s[j] = s[j]-'A'+'a';
        }
        if(!(s[i]>='a' && s[i]<='z') && !(s[i]>='0' && s[i]<='9'))
            i++;
        else if(!(s[j]>='a' && s[j]<='z') && !(s[j]>='0' && s[j]<='9'))
            j--;
        else{
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    string s = "race a car";
    cout<<isPalindrome(s);
    return 0;
}