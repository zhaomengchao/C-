//���룺["h","e","l","l","o"]
//�����["o","l","l","e","h"]
//��Ҫ�����������������Ŀռ䣬
//�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
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