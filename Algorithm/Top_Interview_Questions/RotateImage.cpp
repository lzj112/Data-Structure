/*
你有一个n x n二维矩阵表示一个图像。
将图像旋转90度(顺时针方向)。
注意:
你必须原地旋转图像，这意味着你必须直接修改输入2D矩阵。不要分配另一个2D矩阵，做旋转。
Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include <vector>
using namespace std;

//先以对角线为轴翻转,再以中线为轴上下翻转
class Solution
{
  public:
    void rotate(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i; ++j)
            {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};