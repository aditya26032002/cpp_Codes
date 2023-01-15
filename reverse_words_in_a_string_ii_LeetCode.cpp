#include<bits/stdc++.h>
using namespace std;

void reverseWords(vector<char> &s){
    int size = s.size();
    int i = 0, j = size-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    i = 0;
    while(i<size){
        
        j = i;
        while(j<size-1 && s[j+1]!=' '){
            j++;
        }
        while(i<=j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        while(i<size){
            if(s[i]!=' ' && s[i-1] == ' ')
                break;
            i++;
        }
    }
}

int main(){
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    reverseWords(s);
    for(auto i:s){
        cout<<i;
    }
    return 0;
}