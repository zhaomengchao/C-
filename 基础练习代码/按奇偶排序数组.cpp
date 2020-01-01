
//给定一个非负整数数组 A，
//返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
//输入：[3,1,2,4]
//输出：[2,4,3,1]一种情况
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size()-1;

        while(left < right)
        {
            if(A[left] % 2 != 0 && A[right] % 2 == 0)
            {
                int tmp = A[left];
                A[left] = A[right];
                A[right] = tmp;
            }
            if(A[left] % 2 == 0 )
            {
                left++;
            }
            if(A[right] % 2 != 0)
            {
                right--;
            }
        }
        return A;
    }

};