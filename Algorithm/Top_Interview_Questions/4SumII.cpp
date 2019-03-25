/*
579/5000  
给出四个整数值的列表A、B、C、D，计算有多少元组(i、j、k、l)
使得A[i] + B[j] + C[k] + D[l]为零。
为了使问题简单一点，所有的a, B, C, D都有相同的长度N，
其中0≤N≤500。所有整数的范围都在-228到228 - 1之间，结果保证不超过231 - 1。
例子:
输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:
2
解释:
这两个元组是:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

#include <map>
#include <vector>
using namespace std;

/*
将A B中的数两两相加利用map存储,和相同的次数++
然后C D中两数相加,如果map中有相反数的,次数累加

*/
class Solution
{
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        map<int, int> count;
        int len = static_cast<int> (A.size());

        for (int i = 0; i < len; ++i) 
        {
            for (int j = 0; j < len; ++j) 
            {
                auto it  = count.find(A[i] + B[j]);
                if (it != count.end())
                    it->second++;
                else 
                    count.insert(make_pair(A[i] + B[j], 1));
            }
        }

        int ret = 0;
        for (int i = 0; i < len; ++i) 
        {
            for (int j = 0; j < len; ++j) 
            {
                auto it = count.find(-(C[i] + D[j]));
                if (it != count.end())
                    ret += it->second;
            }
        }
        return ret;
    }   
};