/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
输入: [3,30,34,5,9]
输出: "3033459"
*/
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        string s;//数组转化为字符串
        for(int i = 0; i < nums.size();i++)
        {
            for(int j = 0; j < nums.size()-i-1; j++)
            {
                if(help(nums[j],nums[j+1]))
                {
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                }
            }
        }

        for(int i = 0; i < nums.size();i++)
        {
            s += to_string(nums[i]);
        }
        return s;

    }

    int help(int n1,int n2)
    {
        string tmpa = to_string(n1);
        string tmpb = to_string(n2);
        
        string res1 = tmpa + tmpb;
        string res2 = tmpb + tmpa;

        for(int i = 0; i < res1.size();i++)
        {
            if(res1[i] > res2[i])
            {
                return 1;
            }

            else
            {
                return 0;
            }
        }

        return 0;
    }
};