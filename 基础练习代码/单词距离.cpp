/*
�и��ں����ʵĳ����ı��ļ������������������ʣ��ҳ�������ļ������������ʵ���̾���(���������)��
���룺words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
�����1
*/

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int count1 = -1,count2 = -1;
        int res = words.size();
        int i;
        for(i = 0; i <  words.size();i++)
        {
            if(words[i] == word1)
            {
                count1 = i;
            }
            else if(words[i] == word2)
            {
                count2 = i;
            }
            if(count1 != -1 && count2 != -1)
            {
                res = min(res,abs(count1-count2));
            }
            if(res == 1)
            {
                break;
            }
            
        }
        return res;
    }
};