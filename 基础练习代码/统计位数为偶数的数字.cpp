//���룺nums = [12,345,2,6,7896]
//�����2
//���ͣ�
//12 �� 2 λ���֣�λ��Ϊż����?
//345 �� 3 λ���֣�λ��Ϊ������??
//2 �� 1 λ���֣�λ��Ϊ������?
//6 �� 1 λ���� λ��Ϊ������?
//7896 �� 4 λ���֣�λ��Ϊż����??
//���ֻ�� 12 �� 7896 ��λ��Ϊż��������


class Solution {
public:
    int judge(int n)
    {
        int count = 0;
        while(n)
            {
                count++;
                n = n / 10;
            }
            if(count % 2 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }
    int findNumbers(vector<int>& nums) {
        
        int num = 0;
        for(int i = 0; i < nums.size();i++)
        {
            num += judge(nums[i]);
        }
        return num;
    }
};