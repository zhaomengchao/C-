class Solution {
//����һ������������?nums��
//�ҳ��������ڳ˻�С��?k?��������������ĸ�����
//ʾ�� 1:
//����: nums = [10,5,2,6], k = 100
//���: 8
//����: 8���˻�С��100��������ֱ�Ϊ: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]��
//��Ҫע����� [10,5,2] �����ǳ˻�С��100�������顣


public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0,right = left;
        int size = nums.size();
        int tmp = 1, res = 0;
        //10 5 2 6  100
        while(right < size)
        {
            tmp *= nums[right];
            while(tmp >= k && left <= right)
            {
                tmp /= nums[left++];
            }
            res = res + right - left + 1;
            right++;
        }
        return res;
    }
};