
//����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1����
//ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m]������k[0]xk[1]x...xk[m]���ܵ����˻��Ƕ��٣�
//���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18
class Solution {
public:
    int cutRope(int number) {
        if(number < 2)
        {
            return 0;
        }
        if(number == 2)
        {
            return 1;
        }
        if(number == 3)
        {
            return 2;
        }
        int len = number / 3;
        if(number - len * 3 == 1)
            len -= 1;
        int len2 = (number - len *3)/2;
         
        return (int)pow(3,len)*pow(2,len2);
    }
};