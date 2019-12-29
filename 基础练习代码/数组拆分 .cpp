//��������Ϊ2n������, ��������ǽ���Щ���ֳ�n ��,
//���� (a1, b1), (a2, b2), ..., (an, bn) ��ʹ�ô�1 ��n �� min(ai, bi) �ܺ����

//����: [1,4,3,2]

//���: 4
//����: n ���� 2, ����ܺ�Ϊ 4 = min(1, 2) + min(3, 4).

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1;i += 2)
        {
            if(nums[i] < nums[i + 1])
            {
                sum += nums[i];
            }
            else
            {
                sum += nums[i+1];
            }
        }
        return sum;
    }
};