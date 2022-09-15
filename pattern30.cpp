#include<iostream>
using namespace std;

int main(){
    int n = 4;
    int max = 2*n - 1;
    for(int row = 1; row <= max; row++){
        for(int col = 1; col <= max; col++){
            if(((row == 1) || (row == max)) && ((col == 1) || (col == max)))
            cout<<n<<"\t";
            else if(((row == 2) || (row == max-1)) && ((col == 2) || (col == max-1)))
            cout<<n-1<<"\t";
            else if(((row == 3) || (row == max-2)) && ((col == 3) || (col == max-2)))
            cout<<n-2<<"\t";
            else if((row == (max + 1)/2) && (col == (max + 1)/2))
            cout<<n-3<<"\t";
        }
        cout<<endl;
    }
    return 0;
}