/*
二维数组的查找
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序
每一列都按照从上到下递增的顺序排序。
请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <vector>
using namespace std;

class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        int colCount = array[0].size(); //列
        int rowCount = array.size();    //行
        int col = colCount - 1;
        // int row = rowCount - 1;
        int row = 0;

        for (int i = col; i >= 0 && row < rowCount;)
        {
            if (array[row][i] == target)
            {
                return true;
            }
            else if (array[row][i] < target)
            {
                row++;
            }
            else if (array[row][i] > target) 
            {
                i--;
            }
        }

        return false;
    }
};

/*
矩阵有序,所以选择从右上角的元素开始查找,
如果大于target,证明要左移,如果小于target证明要下移
*/