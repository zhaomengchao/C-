//����һ����Ч�� IPv4 ��ַ address��������� IP ��ַ����Ч���汾��
//��ν��Ч�� IP ��ַ����ʵ������ "[.]" ������ÿ�� "."
//���룺address = "1.1.1.1"
//�����"1[.]1[.]1[.]1"
class Solution {
public:
    string defangIPaddr(string address) {
        string tmp;
        for(int i = 0; i < address.size();i++)
        {
            if(address[i] == '.')
            {
                tmp.push_back('[');
                tmp.push_back('.');
                tmp.push_back(']');
            }
            else
            {
                tmp.push_back(address[i]);
            }
        }
        return tmp;
    }
};