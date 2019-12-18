//给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
//所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."
//输入：address = "1.1.1.1"
//输出："1[.]1[.]1[.]1"
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