#include<bits/stdc++.h>
using namespace std;

// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     int start = 0, end = n-1;
//     int ansStart = 0, ansEnd = n-1;
//     while(1){
//         int mid = start + (end-start)/2;
//         if(arr[mid] == k){
//             ansStart = start;
//             ansEnd = end;
//             break;
//         }
//         else if( start == end){
//             pair<int,int> ans = {-1,-1};
//             return ans;
//         }
//         else if(arr[mid] < k){
//             start = mid+1;
//         }
//         else if(arr[mid] > k){
//             end = mid;
//         }
//     }
//     while(ansStart <= ansEnd){
//         if(arr[ansStart] != k)
//         ansStart++;
//         if(arr[ansEnd] != k)
//         ansEnd--;
//         if(arr[ansStart] == k && arr[ansEnd] == k)
//         break;
//     }
//     pair<int,int> ans {ansStart, ansEnd};
//     return ans;
// }

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> ans = {-1,-1};
    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    while(start <= end){  // For finding first occurence
        if(arr[mid] == k){
            ans.first = mid;
            end = mid - 1;
        }
        else if(start == end)
            break;
        else if( arr[mid] > k)
            end = mid-1;
        else if( arr[mid] < k)
            start = mid + 1;
        mid = start + (end-start)/2;
    }

    if(ans.first == -1){
        return ans;
    }
    else{
        start = ans.first;
    }
    end = n-1;
    while(start <= end){ // For finding last occurence
        if(arr[mid] == k){
            ans.second = mid;
            start = mid + 1;
        }
        else if(start == end)
            break;
        else if( arr[mid] > k)
            end = mid-1;
        else if( arr[mid] < k)
            start = mid + 1;
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    vector<int> arr = {2,4,5,8,10,12};
    int k = 0;
    pair<int,int> ans = firstAndLastPosition(arr,6,k);
    cout<<ans.first<<" "<<ans.second<<endl;
    if(ans.first != -1)
    cout<<"Total number of occurenece : "<<ans.second-ans.first+1<<endl;
    return 0;
}