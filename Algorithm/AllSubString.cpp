#include <string>
#include <iostream>
using namespace std;

void getAllSubstrings(std::string str)
{
    if (str.size() == 0)
        return;
    else
    {
        for (int i = 0; i < str.size(); i++)
        {
            for (int j = i; j < str.size() - 1; j++)
            {
                std::cout << str.substr(i, i + j) << ' ';
            }
            cout << endl;
        }
    }
}

int main() 
{
    string s("abcar2");
    getAllSubstrings(s);
}