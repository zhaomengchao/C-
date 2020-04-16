/*�������ڵ����ֵ*/
/*˼·��ջ��������м��㣬ͨ��ջ���ҳ����ֵ������洢�������ڵ����ֵ*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        stack<int> s;
        if(nums.empty() || k == 0)
        {
            return{};
        }
        if(k== 1)
        {
            return nums;
        }
        int right;
        int left = 0;
        if(nums.size() < k)
        {
            right = nums.size() - 1;    
        }
        else
        {
            right = k - 1;
        }
        while(right <= nums.size()-1)
        {
            for(int i = left; i < right; i++)
            {
                if(s.empty())
                {
                    s.push(nums[i]);
                }
                if(!s.empty() && s.top() < nums[i+1])
                {
                    s.pop();
                    s.push(nums[i+1]);
                }
            }
            res.push_back(s.top());
            s.pop();
            left++;
            right++;
            
        }
        return res;
    }
};