/*
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��
ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
*/
class Solution {
public:
//����amp��
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> m;
        
        for(int i = 0; i < nums.size();i++)
        {
            if(m.find(nums[i]) != m.end())
            {
                return nums[i];//��������
            }
            m[nums[i]] = 1;
        }
        return 0;
    }
};