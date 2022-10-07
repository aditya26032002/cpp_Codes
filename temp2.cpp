#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream file;
    string text, filename;
    filename = "file.txt";
    file.open(filename);
    while (file >> text)
    {
        cout << text << endl;
    }
    return 0;
}