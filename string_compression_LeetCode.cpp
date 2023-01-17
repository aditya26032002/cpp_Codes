#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int i = 0, ansIndex = 0, size = chars.size();
    while(i<size){
        int j = i+1;
        while(j<size && chars[j] == chars[i]){
            j++;
        }
        chars[ansIndex++] = chars[i];
        int count = j-i;
        if(count>1){
            string cnt = to_string(count);
            for(char ch:cnt){
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main(){
    // vector<char> chars = {'a','a','b','b','c'};
    // vector<char> chars = {'a'};
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int ansSize = compress(chars);
    for(int i = 0; i<ansSize; i++){
        cout<<chars[i];
    }
    return 0;
}

// Runtime error in Leetcode compiler only
// O(n) space
// int compress(vector<char>& chars) {
//     vector<char> ans;
//     int i = 0, j = 0;
//     while(i<chars.size()){
//         if(chars[i+1] == chars[i]){
//             j = i+1;
//             while(chars[j+1] == chars[j] && j<chars.size()-1){
//                 j++;
//             }
//             ans.push_back(chars[i]);
//             int num = j-i+1;
//             if(num>9){
//                 string str = to_string(num);
//                 for(char i:str){
//                     ans.push_back(i);
//                 }
//             }
//             else
//                 ans.push_back(j-i+1 + '0');
//             i = j+1;
//         }
//         else{
//             ans.push_back(chars[i]);
//             i++;
//         }
//     }
//     chars = ans;
//     return chars.size();
// }