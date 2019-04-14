#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct t 
{
    t(int v1, int v2) : a(v1), b(v2)
    {}
    int a;
    int b;
};

bool compare(t a, t b) 
{
    return a.a < b.a;
}
int main() 
{
    list<t> lst;
    lst.push_back(t(1, 2));
    lst.push_back(t(2, 3));
    lst.push_back(t(5, 5));
    lst.push_back(t(-1, 2));
    lst.push_back(t(4, 2));

    lst.sort(compare);
    
    for (auto x : lst) 
    {
        cout << x.a << ' ';
    }
    cout << endl;
}