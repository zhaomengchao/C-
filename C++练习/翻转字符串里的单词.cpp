/*
 ��ת�ַ�����ĵ���
����һ���ַ����������ת�ַ����е�ÿ�����ʡ�
�⺯��+�ַ���
https://leetcode-cn.com/problems/reverse-words-in-a-string/
*/
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int pos = 0;
        for (int begin = 0; begin < n; ++begin) {
            if (s[begin] != ' ') {//�ҵ�����һ���ַ��������
                if (pos != 0) { //��һ���ո������
                    s[pos++] = ' ';
                }
                int end = begin;
                while (end < n && s[end] != ' ') {//ǰ��
                    s[pos++] = s[end++];
                }
                reverse(s.begin() + pos - (end - begin), s.begin() + pos); //�ֲ���ת
                begin = end;
            }
        }
        s.erase(s.begin() + pos, s.end());//ĩβ�����ж���ո�
        return s;
    }
};
