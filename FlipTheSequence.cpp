#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int makeFunc(string str) 
{
    string ctr(str);
    reverse(ctr.begin(), ctr.end());
    
}

int main() 
{
    string str;
   
    while (cin >> str) 
    {
        cout << makeFunc(str) << endl;
    }

    return 0;
}