/*
�ַ��� t ���ַ��� s ������ţ�Ȼ�������λ�����һ����ĸ��

���ҳ��� t �б���ӵ���ĸ��
���룺
s = "abcd"
t = "abcde"

�����
e

���ͣ�
'e' ���Ǹ�����ӵ���ĸ��
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(int i = 0; i < s.size();i++)
        {
            res ^= s[i];
        }
        for(int j = 0; j < t.size();j++)
        {
            res ^= t[j];
        }
    return res;
    }
};