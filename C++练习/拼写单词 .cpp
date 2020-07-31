/*
ƴд����

����һ�ݡ��ʻ�����ַ������飩 words ��һ�š���ĸ�����ַ����� chars��

����������� chars �еġ���ĸ�����ַ���ƴд�� words �е�ĳ�������ʡ����ַ���������ô���Ǿ���Ϊ��������������ʡ�

ע�⣺ÿ��ƴд��ָƴд�ʻ���е�һ�����ʣ�ʱ��chars �е�ÿ����ĸ��ֻ����һ�Ρ�

���شʻ�� words �������յ����е��ʵ� ����֮�͡�

˼·��
����һ������ word��ֻҪ���е�ÿ����ĸ�������������� chars �ж�Ӧ����ĸ��������
��ô�Ϳ����� chars �е���ĸƴд�� word����������ֻ��Ҫ��һ����ϣ��洢 chars ��ÿ����ĸ��������
����һ����ϣ��洢 word ��ÿ����ĸ�������������������ϣ��ļ�ֵ����һ���бȽϼ��ɡ�

*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> cha_num;
        for(auto i : chars)
        {
            ++cha_num[i];
        }
        int count = 0;
        for(auto word : words)
        {
            unordered_map<char, int> word_num;
            for(auto j : word)
            {
                ++word_num[j];
            }
            bool flag = true;
            
            for(auto c : word)
            {
                if(cha_num[c] < word_num[c])
                {
                    flag=false;
                    break;
                }
            }
            if(flag )
            {
                count += word.size();
            }

        }
        return count;
    }
};