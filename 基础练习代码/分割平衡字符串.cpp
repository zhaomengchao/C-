//���룺s = "RLRRLLRLRL"
//�����4
//���ͣ�s ���Էָ�Ϊ "RL", "RRLL", "RL", "RL", ÿ�����ַ����ж�������ͬ������ 'L' �� 'R'

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int num1 = 0, num2 = 0;//�ֱ�ͳ��RL���ֵĴ���
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