//输入：s = "RLRRLLRLRL"
//输出：4
//解释：s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int num1 = 0, num2 = 0;//分别统计RL出现的次数
        char tmp = s[0];
        for(int i = 0; i < s.size();i++)
        {
            if(s[i] == tmp)
            {
                num1++;
            }
            else
            {
                num2++;
            }
            if(num1 == num2)
            {
                count++;
                num1 = 0;
                num2 = 0;
            }
        }
        return count;
    }
};