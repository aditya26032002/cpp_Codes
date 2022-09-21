#include <iostream>
using namespace std;

int hcf(int a , int b){
	if(a <= b){
		if((b % a) == 0){
			return a;
		}
		else{
			return hcf(b%a, a);
		}
	}
	else{
		if(a%b == 0){
			return b;
		}
		else{
			return hcf(a%b, b);
		}
	}
}

int main()
{
	int a = 5, b = 30;
	cout<<hcf(a,b);
	return 0;
}