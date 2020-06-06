/*
搜索旋转数组 https://leetcode-cn.com/problems/search-rotate-array-lcci/
*/

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0, right = arr.size()-1;      // 先用二分查找找到转折点
        while (left < right) {
            int mid = (left +right) / 2;
            if (arr[mid] <= arr[right]) {
                right = mid;
            } else if (arr[mid] >= arr[left]) {
                left = mid+1;
            }
        }
        if (target >= arr[0]) {                  // 优先先用前半段
            left = 0, right = right - 1;
        } else {
            right = arr.size()-1;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {            
                right = mid;                     
            } else if (arr[mid] < target) {
                left = mid+1;
            }
        }
        if (arr[right] != target) return -1;
        return right;
    }
};
