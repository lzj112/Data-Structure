#include <iostream>
using namespace std;

struct tree 
{
    int val;
    tree* left;
    tree* right;
};

void show(tree** t) 
{
    cout << (*t)->val << endl;
}

int main() 
{
    int val1 = 10;
    int val2 = 90;
    int *p = &val1;
    int ** ptr = &p;
    *ptr = &val2;
    cout << *p << endl;
}