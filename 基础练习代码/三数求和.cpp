//����֮��
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
            if(nums[i] > 0){  //���涼����0���޽�
                return ans;
            }
            if(i > 0 && nums[i] == nums[i-1]){   //�ظ���
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
                    /*����Ϊȥ���������˵��ظ���*/
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