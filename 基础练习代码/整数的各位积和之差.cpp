//���룺n = 234
//�����15 
/���ͣ�
//��λ��֮�� = 2 * 3 * 4 = 24 
//��λ��֮�� = 2 + 3 + 4 = 9 
//��� = 24 - 9 = 15
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