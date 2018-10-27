#include <iostream>
using namespace std;

int main() 
{
    char s1[] = "1234";
    char s2[] = "1234";

    char* s3 = "1234";
    char* s4 = "1234";

    if (s1 == s2) 
    {
        cout << "1 and 2 same" << endl;
    }
    else 
    {
        cout << "1 and 2 not same" << endl;
    }

    if (s3 == s4) 
    {
        cout << "3 and 4 same " << endl;
    }
    else 
    {
        cout << "3 and 4 not same " << endl;
    }
    return 0;
}