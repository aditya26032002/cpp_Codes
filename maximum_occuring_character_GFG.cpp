#include<bits/stdc++.h>
using namespace std;

char maxOccurChar(string s){
    int alphabets[26] = {0};
    for(int i = 0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<'Z')
            s[i] = s[i] - 'A' + 'a';
        alphabets[s[i]-'a']++;
    }
    int max = 0, maxIndex = -1;
    for(int i = 0; i<26; i++){
        if(alphabets[i]>max){
            max = alphabets[i];
            maxIndex = i;
        }
    }
    return ('a' + maxIndex);
}

int main(){
    string s = "Output";
    cout<<maxOccurChar(s);
    return 0;
}