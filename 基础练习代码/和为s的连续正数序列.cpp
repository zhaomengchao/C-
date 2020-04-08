/*输入一个正整数 target ，
输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列
输入：target = 9
输出：[[2,3,4],[4,5]]
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int i = 1;//左边界
        int j = 1;//右边界
        int sum = 0;
        while(i < target)
        {
            if(sum < target)//右边界移动
            {
                sum += j;
                j++;
            }
            else if(sum > target)//左边界移动
            {
                sum -= i;
                i++;
            }
            else
            {
                vector<int> tmp;
                for(int e = i; e < j;e++)
                {
                    tmp.push_back(e);
                }
                res.push_back(tmp);
                //左边界向右移动
                sum -= i;
                i++;
                
            }


        }
        return res;
    }
};