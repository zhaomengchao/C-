//输入：["h","e","l","l","o"]
//输出：["o","l","l","e","h"]
//不要给另外的数组分配额外的空间，
//你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }

    }
};