/*
给定一个无序数组arr，找到数组中未出现的最小正整数
例如arr = [-1, 2, 3, 4]。返回1
arr = [1, 2, 3, 4]。返回5
[要求]
时间复杂度为O(n)O(n)，空间复杂度为O(1)O(1)
*/
class Solution {
public:
    /**
     * return the min number
     * @param arr int整型vector the array
     * @return int整型
     */
    int minNumberdisappered(vector<int>& arr) {
        // write code here
        int len = arr.size();
        int res = 1;
        int count = 0;
        while(count <= len)
        {
            if(arr[count] == res)
            {
                count = 0;
                res++;
            }
            count++;
        }
        return res;
    }
};