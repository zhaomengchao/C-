//有序数组，找出两个数之和等于目标值，找到了返回对应数的下标，找不到返回-1；

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0,right = numbers.size() - 1;

        while(left < right)
        {
            int tmp = numbers[left] + numbers[right];

            if(target == tmp)
            {
                return {left + 1, right + 1};
            }
            else if(target < tmp)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {-1, -1};
    }
};