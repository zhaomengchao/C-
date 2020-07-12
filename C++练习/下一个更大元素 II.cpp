/*

����һ��ѭ�����飨���һ��Ԫ�ص���һ��Ԫ��������ĵ�һ��Ԫ�أ������ÿ��Ԫ�ص���һ������Ԫ�ء����� x ����һ�������Ԫ���ǰ��������˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ��������������һ�������������������ڣ������ -1��

ʾ�� 1:

����: [1,2,1]
���: [2,-1,2]
����: ��һ�� 1 ����һ����������� 2��
���� 2 �Ҳ�����һ����������� 
�ڶ��� 1 ����һ����������Ҫѭ�����������Ҳ�� 2��
https://leetcode-cn.com/problems/next-greater-element-ii/
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n,-1);
        
        stack<int> small;
        int index;
        for(int i=2*n-2;i>=0;i--){
            
            if(i>=n) index=i-n;
            else index=i;
            while(!small.empty()&&small.top()<=nums[index]){
                small.pop();
            }
            if(!small.empty() && i<n) out[index] = small.top();
            small.push(nums[index]);
        }
        
        return out;
    }
};