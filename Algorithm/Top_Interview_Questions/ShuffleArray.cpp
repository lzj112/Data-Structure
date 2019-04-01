/*
洗牌一组没有重复的数字。
Example:
例子:
//初始化一个集合为1、2和3的数组
int[] nums = {1,2,3};
Solution solution = new Solution(nums);
//洗牌数组[1,2,3]并返回其结果。任何[1,2,3]的排列都必须具有相同的返回概率。
solution.shuffle ();
//将数组重置为其原始配置[1,2,3]。
solution.reset ();
//返回数组的随机打乱[1,2,3]。
solution.shuffle();
*/

#include <stdlib.h>

#include <vector>
using namespace std;

class Solution
{
  public:
    Solution(vector<int> nums)
    {
        backUp = nums;
    }

    /*将数组重置为其原始配置并返回它。*/
    vector<int> reset()
    {
        return backUp;
    }

    /*返回数组的随机打乱*/
    vector<int> shuffle()
    {
        vector<int> a(backUp.begin(), backUp.end());
        int len = static_cast<int> (backUp.size());
        for (int i = 0; i < len; i++) 
        {
            int t = rand() % (len - i);
            swap(a[i], a[t]);
        }
        return a;
    }
private:
    vector<int> backUp;
};

/*
您的解决方案对象将被实例化并调用如下:
Solution obj = new Solution(nums);
vector<int> param_1 = obj.reset();
vector<int> param_2 = obj.shuffle();
 */