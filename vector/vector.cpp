

����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�

����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
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

����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�



ʾ�� 1:

����: [2,2,1]
���: 1


ʾ�� 2:

����: [4,1,2,1,2]
���: 4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/single-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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