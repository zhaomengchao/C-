//���������ַ��� s �� t������ֻ����Сд��ĸ��

//�ַ��� t ���ַ��� s ������ţ�Ȼ�������λ�����һ����ĸ��

//���ҳ��� t �б���ӵ���ĸ��
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (auto i = 0; i < s.size(); ++i) {
            if (t[i] != s[i]) {
                return t[i];
            }
        }
        return t.back();
    }
};
