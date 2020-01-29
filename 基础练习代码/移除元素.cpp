//����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin=0,end=nums.size()-1;
        while(begin<=end){
            if(nums[begin]==val && nums[end]!=val){
                nums[begin]=nums[end];
                begin++;
                end--;
            }else if(nums[begin]!=val && nums[end]==val){
                begin++;
                end--;
            }else if(nums[begin]==val && nums[end]==val){
                end--;
            }else{
                begin++;
            }
        }
        return begin;
    }
};