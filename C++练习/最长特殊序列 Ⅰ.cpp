/*
��������� ��
https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/
���������ַ�����������������ַ������ҳ�����������С�

����������С��������£�������Ϊĳ�ַ������е�������У��������������ַ����������У���
*/
class Solution {
public:
    int findLUSlength(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();

        if(len1 == len2)
        {
            if(a == b)
            {
                return -1;
            }
            else
            {
                return len1;
            }
        }
        else
        {
            return len1 > len2 ? len1 : len2;
        }
    }
};