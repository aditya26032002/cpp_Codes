#include<bits/stdc++.h>
using namespace std;

void countOccurences(string s, int arr[], int st, int end){
    for(int i = st, j = end; i<=j; i++, j--){
        if(i == j){
            arr[s[i] - 'a']++;
        }
        else{
            arr[s[i] - 'a']++;
            arr[s[j] - 'a']++;
        }
    }
}

bool compareCountArrays(int arr1[], int arr2[]){
    int i = 0, j = 25;
    while(i<=j){
        if(arr1[i] != arr2[i] || arr1[j] != arr2[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int s1count[26] = {0};
    countOccurences(s1, s1count, 0, s1.length()-1);
    int windowCount[26] = {0};
    int i = 0, windowend = s1.length()-1;
    while(windowend < s2.length()){
        if(i == 0){
            countOccurences(s2,windowCount,i,windowend);

            // for(int i = 0; i<26; i++){
            // if(windowCount[i] != 0){
            // cout<<(char)('a'+i)<<"->"<<windowCount[i]<<endl;
            // }
            // }
            // cout<<endl<<endl;
        }
        else{
            windowCount[s2[i-1]-'a']--;
            windowCount[s2[windowend]-'a']++;

            // for(int i = 0; i<26; i++){
            // if(windowCount[i] != 0){
            // cout<<(char)('a'+i)<<"->"<<windowCount[i]<<endl;
            // }
            // }
            // cout<<endl<<endl;
        }
        if(compareCountArrays(s1count, windowCount)){
            return true;
        }
        else{
            i++;
            windowend++;
        }
    }
    return false;
}

int main(){
    string s1 = "adc";
    string s2 = "dcda";
    cout<<checkInclusion(s1,s2);
    return 0;
}