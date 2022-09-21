#include<iostream>
using namespace std;

// Very expensive
// long long sumOfDivisors(long long num){
//     int sum = 0;
//     for(int i = 1; i<=num; i++){
//         if(num % i == 0){
//             sum += i;
//         }
//     }
//     return sum;
// }
// ------XXX-----

// Time limit exceeded n*root(n)
// long long sumOfDivisors(int num){
//     long long sum = 0;
//     long long i = 1, j = num;
//     while (i <= j)
//     {
//         if(num % i == 0){
//             j = num / i;
//             if (i != j)
//             {
//                 sum += (i + j);
//             }
//             else{
//                 sum += i;
//             }
//         }
//         i++;
//         j--;
//     }
//     return sum;
// }

// long long F(int num){
//     int sum = 0;
//     while (num)
//     {
//         sum += sumOfDivisors(num);
//         num--;
//     }
//     return sum;
// }
// ------XXXX-----

long long F(long long N){
    long long sum = 0;
    for(long long i = 1; i <= N; i++){
        sum += (N/i)*i;
    }
    return sum;
}

int main(){
    long long N = 4;
    cout<<F(N);
    return 0;
}