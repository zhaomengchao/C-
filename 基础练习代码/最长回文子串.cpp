//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��
class Solution {
public:
    string longestPalindrome(string s) {
        string res="";//��Ž��
        string temp="";//����Ӵ�
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                string tem=temp;//tem����Ӵ���ת���
                std::reverse(tem.begin(),tem.end());//��ת
                if(temp==tem)
                    res=res.length()>temp.length()?res:temp;
            }
            temp="";
        }
        return res;
    }
};