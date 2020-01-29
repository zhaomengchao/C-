//三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int len = nums.size();
        if(len < 3)
            return ans;
        sort(nums.begin(), nums.end());
        int i, left, right;
        for(i = 0; i < len - 2; i++){
            if(nums[i] > 0){  //后面都大于0，无解
                return ans;
            }
            if(i > 0 && nums[i] == nums[i-1]){   //重复解
                continue;
            }
            left = i + 1;
            right = len - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back( nums[right]);
                    ans.push_back(v);
                    v.clear();
                    /*以下为去掉左右两端的重复解*/
                    while(left < right && nums[left] == nums[left+1])
                        left++;  
                    while(left < right && nums[right] == nums[right-1])
                        right--;
                left++;
                right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};