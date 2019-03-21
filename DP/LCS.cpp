/*
求最长公共子序列
*/

#include <string>
#include <iostream>
using namespace std;


int findLongest(string s1, string s2) 
{
    int maxLen[1000][1000];
    int len1 = s1.size(), 
    len2 = s2.size();
    for (int i = 0; i < len2; i++)  
    maxLen[0][i] = 0;
    for (int i = 0; i < len1; i++)  
    maxLen[i][0] = 0;

    for (int i = 1; i <= len1; i++) 
    for (int j = 1; j <= len2; j++) 
    {
        if (s1[i-1] == s2[j-1]) 
            maxLen[i][j] = maxLen[i-1][j-1] + 1;
        else 
            maxLen[i][j] = max(maxLen[i][j - 1], 
                               maxLen[i - 1][j]);
    }
    return maxLen[len1][len2];
}


int main() 
{
    string s1, s2;
    while (cin >> s1    
               >> s2) 
    {
        cout << s1 << ' ' << s2 
             << " 的最长公共子序列长度为 = " 
             << findLongest(s1, s2) 
             << endl;
    }
    return 0;
}