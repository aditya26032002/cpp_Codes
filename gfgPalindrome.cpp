#include <iostream>
using namespace std;

int main()
{
	int n = 101;
	int num = n;
	int reverse = 0;
	while (num)
	{
		reverse = reverse * 10 + num % 10;
		// cout<<reverse<<endl;
		num /= 10;
	}
	// cout<<endl<<reverse<<endl;
	if (reverse == n)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}