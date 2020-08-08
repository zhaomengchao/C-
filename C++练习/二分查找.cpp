/*
����һ��?n?��Ԫ������ģ�������������?nums ��һ��Ŀ��ֵ?target ?��
дһ����������?nums?�е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1

���ӣ�https://leetcode-cn.com/problems/binary-search
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