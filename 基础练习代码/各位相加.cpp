//����: 38
//���: 2 
//����: ��λ��ӵĹ���Ϊ��3 + 8 = 11, 1 + 1 = 2�� ����?2 ��һλ�������Է��� 2��
//����:
//��ʹ��ѭ�����ߵݹ飬���� O(1) ʱ�临�Ӷ��ڽ���������



class Solution {
public:
    int addDigits(int num) {
       if(num>9)
        {
            num=num%9;
            if(num==0)
                return 9;
        }
        return num;
    }
};