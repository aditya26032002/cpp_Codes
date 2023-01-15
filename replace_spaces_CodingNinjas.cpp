#include<bits/stdc++.h>
using namespace std;

// time :- O(n), space :- O(n)
string replaceSpaces(string &str){
    int len = str.length();
    string ans;
    for(int i = 0; i<len; i++){
        if(str[i]==' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else
            ans.push_back(str[i]);
    }
    return ans;
}

// Changing values inplace i.e. space reduces
// time :- O(n^2), space :- O(1)
// void replaceSpaces(string &str){
//     int len = str.length();
//     string toPush = "@40";
//     // string ans;
//     for(int i = 0; i<len; i++){
//         if(str[i]==' '){
//             str.push_back(' ');
//             str.push_back(' ');

//             int j = str.length()-1;
//             while(j>i+2){
//                 str[j] = str[j-2];
//                 j--;
//             }
//             str[i] = '@';
//             str[i+1] = '4';
//             str[i+2] = '0';
//             i+=2;
//         }
//     }
// }

int main(){
    string s = "Coding Ninjas Is A Coding Platform";
    string ans = replaceSpaces(s);
    for(auto i:ans){
        cout<<i;
    }
    // replaceSpaces(s);
    // for(auto i:s){
    //     cout<<i;
    // }
    return 0;
}