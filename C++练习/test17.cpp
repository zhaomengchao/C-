//һֻ����һ�ο�������1��̨�ף�Ҳ����һ����2��̨�ף�
//��������һ��n��̨�ף��ж����ְ취

class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 1)
        {
            return 1;
        }
        if(number == 2)
        {
            return 2;
        }
        else
        {
            return jumpFloorII(number-1)*2;
        }
    }
};