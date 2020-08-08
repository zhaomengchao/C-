/*
给定一个?n?个元素有序的（升序）整型数组?nums 和一个目标值?target ?，
写一个函数搜索?nums?中的 target，如果目标值存在返回下标，否则返回 -1

链接：https://leetcode-cn.com/problems/binary-search
*/
class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return -1;
  }
};