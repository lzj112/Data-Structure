#include <vector>
#include <iostream>
using namespace std;

int main() 
{
    vector<long> fight, v;
    int number;
    cin >> number;
    int t = number;
    while (t--) 
    {
        int tmp;
        cin >> tmp;
        fight.push_back(tmp);//武力值
    }
    t = number;
    while (t--) 
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp); //金钱
    }

    vector<long> dp(number, 0);
    dp[0] = v[0];
    
    int maxFight = fight[0];
    for (int i = 1; i < number; i++) 
    {
        //武力够了但是买下来划算
        if (maxFight > fight[i] &&  
            (fight[i] + maxFight > fight[i + 1]) &&
            dp[i - 1] + v[i] < v[i + 1]) 
        {
            maxFight += fight[i];
            dp[i] += v[i];
        }
        else if (maxFight < fight[i])   //武力不够,必须买下来
        {
            dp[i] = dp[i - 1] + v[i];
            maxFight += fight[i];
        }
        
    }
    cout << dp[number - 1] << endl;
}
