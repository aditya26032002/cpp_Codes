#include<iostream>
using namespace std;

int main(){
    int amt = 1330;
    switch(1){
        case 1: {
            cout<<"Num of Rs 100 notes : "<<amt/100<<endl;
            amt = amt % 100;
        }

        case 2: {
            cout<<"Num of Rs 50 notes : "<< amt / 50 << endl;
            amt = amt % 50;
        }

        case 3: {
            cout<<"Num of Rs 20 notes : "<< amt / 20 << endl;
            amt = amt % 20;
        }

        case 4: {
            cout<< "Num of Rs 1 notes : "<<amt <<endl;
            break;
        }

    }
    return 0;
}