#include <map>
#include <string>
#include <iostream>
using namespace std;

char func(string s) 
{
    map<char, int> mp;
    int len = static_cast<int> (s.size());
    for (int i = 0; i < len; i++) 
    {
        auto it = mp.find(s[i]);
        if (it != mp.end())
            it->second++;
        else
            mp.insert(make_pair(s[i], 1));
    }
    auto it = mp.begin();
    auto end = mp.end();
    for (; it != end; it++)
    {
        if (it->second == 1)
            return it->first;
    }
}

int main() 
{
    string s("abceaacffee");
    cout << func(s) << endl;
}