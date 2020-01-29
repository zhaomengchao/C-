//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
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