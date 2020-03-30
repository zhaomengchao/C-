//һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sign = 0;
        for(int n : nums) sign ^= n;
        //sign��-sign������֮�󣬻���������ڶ�λ��������Ϊ1������Ϊ0
        sign &= -sign;
        int n1 = 0, n2 = 0;
        //����sign����
        for(int n : nums){
            if(n & sign) n1 ^= n;
            else n2 ^= n;
        }
        return {n1, n2};
    }
};
