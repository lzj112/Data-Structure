#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

void getAllSubStr(set<string>& tmp, vector<string>& str) 
{
    if (str.empty())
        return ;
    for (auto x : str) 
    {
        tmp.insert(x);
        for (int i = 0; i < x.size(); i++) 
        {
            for (int j = 1; j < x.size(); j++) 
            {
                string t = x.substr(i, i + j);
                tmp.insert(t);
            }
        }
    }
}

void getAllSubStr(set<pair<int, int> >& tmp, string t) 
{
    for (int i = 0; i < t.size(); i++) 
    {
        for (int j = 1; j < t.size(); j++) 
        {
            tmp.insert(make_pair(i, i + j));
            string tmpSub = t.substr(i, i + j);
        }
    }
}

int sFunc(string t, set<string>& subArr, set<pair<int, int> >& subT) 
{
    int count = 0;
    int preEnd = -1;
    for (auto x : subT) 
    {
        string tmp = t.substr(x.first, x.second);
        if (subArr.find(tmp) != subArr.end())
        {
            if (x.first > preEnd)
            {
                count++;
                preEnd = x.second;
            }
        }
    }
    return count;
}

int main() 
{
    int m;
    cin >> m;
    vector<string> strArr;
    while (m--) 
    {
        string str;
        cin >> str;
        strArr.push_back(str);
    }
    string t;
    cin >> t;

    set<string> subArr;
    getAllSubStr(subArr, strArr);   //找出m个字符串的所有子串

    set<pair<int, int> > subT;
    getAllSubStr(subT, t); //找T的所有子串

    cout << sFunc(t, subArr, subT) << endl;
}