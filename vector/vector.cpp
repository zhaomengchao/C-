

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows,vector<int>());
        for(size_t i =0;i < numRows;i++)
        {
            vv[i].resize(i+1,0);
            vv[i][0] = 1;
            vv[i][vv[i].size()-1] = 1;
        }
        for(size_t i = 0;i < vv.size();i++)
        {
            for(size_t j = 0;j <vv[i].size();j++)
            {
                if(vv[i][j] == 0)
                {
                    vv[i][j] = vv[i-1][j-1]+vv[i-1][j];
                }
            }
        }
        return vv;
    }
};

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。



示例 1:

输入: [2,2,1]
输出: 1


示例 2:

输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(size_t i = 0;i < nums.size();++i)
        {
            val ^= nums[i];
        }
        return val;
    }
};