//��ת����123 321 
//-123  -321
class Solution {
public:
    /**
     * 
     * @param x int���� 
     * @return int����
     */
    int reverse(int x) {
        // write code here
        long long str  = 0;
        while(x)
        {
            str = str*10 + x % 10;;
            x = x / 10;
        }
        return str;
        
    }
};