/*
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
*/


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        
        string ret;
        for(int i = n ; i < s.size();i++)
        {
            ret.push_back(s[i]);
        }
        for(int i =0; i < n; i++)
        {
             ret.push_back(s[i]);
        }
        return ret;
    }
};