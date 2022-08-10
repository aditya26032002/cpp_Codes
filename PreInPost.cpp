#include <iostream>
using namespace std;

void fun(int n){
    if(n == 0){
        return;
    }
    else{
        cout<<"Pre " << n<<endl;
        fun(n-1);
        cout<<"In "<<n<<endl;
        fun(n-1);
        cout<<"Post "<< n<<endl;
    }
}
int main(){
    fun(3);
    return 0;
}