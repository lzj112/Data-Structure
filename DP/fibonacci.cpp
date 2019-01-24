#include <vector>
#include <iostream>

using namespace std;

int Fib(int n, vector<int>& fib) 
{
    if (fib[n - 1] != -1) 
        return fib[n - 1];
    if (n <= 2) 
        fib[n - 1] = 1;
    else 
        fib[n - 1] = Fib(n - 1, fib) + Fib(n - 2, fib);

    return fib[n - 1];
}

int Fibonacci(int n) 
{
    if (n <= 0) 
    {
        return n;
    }
    vector<int> fib(n, -1);
    return Fib(n, fib); 
}


int main() 
{
    int n;
    cin >> n;
    cout << "Fibonacci` " << n << " = " << Fibonacci(n) << endl;

    return 0;
}