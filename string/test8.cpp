//把字符串转化成为整数
输入：+2147483647
1a33

输出：2147483647
    0


class Solution {
public:
    int StrToInt(string str) {
        int tmp = 0;
        int flag = 1;
        
        int len = str.size();
        for(int i = 0; i < len;i++)
        {
            if(str[i] < '0' || str[i] > '9')
            {
                if(str[i] == '+')
                {
                    flag = 1;
                }
                else if(str[i] == '-')
                {
                    flag = -1;
                }
                else
                    return 0;
            }
            else
            {
                tmp =tmp*10 + (str[i] - '0');
            }
            
        }
        return flag*tmp;
    }
};