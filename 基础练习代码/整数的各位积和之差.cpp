//输入：n = 234
//输出：15 
/解释：
//各位数之积 = 2 * 3 * 4 = 24 
//各位数之和 = 2 + 3 + 4 = 9 
//结果 = 24 - 9 = 15
class Solution {
public:
    int subtractProductAndSum(int n) {
        int ama = 1;
        int add = 0;
        int dif = 0;
        while(n)
        {
            ama *=  n % 10;
            add += n % 10;
            n = n / 10;
        }
        dif = ama - add;
        return dif;
        
    }
};