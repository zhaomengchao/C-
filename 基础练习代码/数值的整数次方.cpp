/*ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η���
����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long N = n;
        if (n < 0) {
            x = 1/x;
            N = -N;
        }
        double res = 1;
       
        while (N > 0) {
            if ((N & 1) == 1) {
                res = res * x;
            }
            x *= x;
            N >>= 1;
        }
        return res;
    }
};

