//不用加减法求和

class Solution {
public:
    int Add(int num1, int num2)
    {
        int c = num1 ^ num2;
        int d = num1 & num2;
        if(d!=0)
        {
            return Add(d << 1,c);
        }
        return c;
    }
};