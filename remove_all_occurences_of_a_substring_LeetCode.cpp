#include<bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part){
    while(s.length()!=0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    string s = "qtbxqtbxelkekgcdnelkeqtbxelkekgcdnqtbxelkekgcdnkgcdnwqchzunbvyjoq";
    string part = "qtbxelkekgcdn";
    string ans = removeOccurrences(s,part);
    for(auto i:ans){
        cout<<i;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Runtime error in leetcode compiler but runs well in my pc
// 
// pair<bool,string> findSubStrAndUpdateAns(string s, string part, string ans) {
//     int partLen = part.length();
//     int strLen = s.length();
//     pair<bool,string> ret;
//     for(int i = 0; i<strLen; i++){
//         if((s[i] == part[0] && s[i+partLen-1] == part[partLen-1]) && i<strLen-(partLen-1)){
//             bool isSubStr = 1;
//             int st = 0, end = partLen-1;
//             while (st<=end)
//             {
//                 if(s[i+st] != part[st] || s[i+end] != part[end]){
//                     isSubStr = false;
//                 }
//                 st++;
//                 end--;
//             }
//             if(isSubStr){
//                 int j = i + partLen;
//                 for(j; j<strLen; j++){
//                     ans.push_back(s[j]);
//                 }
//                 ret.first = 1;
//                 ret.second = ans;
//                 return ret;
//             }
//             else
//                 ans.push_back(s[i]);
//         }
//         else{
//             ans.push_back(s[i]);
//         }
//     }
//     ret.first = 0;
//     ret.second = ans;
//     return ret;
// }

// string removeOccurrences(string s, string part){
//     string ans = "";
//     while(1){
//         pair<bool, string> send = findSubStrAndUpdateAns(s,part,ans);
//         // for(auto i:send.second){
//         //     cout<<i;
//         // }
//         // cout<<endl;
//         if(send.first == 0){
//             break;
//         }
//         else{
//             s = send.second;
//         }
//     }
//     return s;
// }
/////////////////////////////////////////////////////////////////////////////////