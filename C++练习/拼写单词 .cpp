/*
拼写单词

给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

思路：
对于一个单词 word，只要其中的每个字母的数量都不大于 chars 中对应的字母的数量，
那么就可以用 chars 中的字母拼写出 word。所以我们只需要用一个哈希表存储 chars 中每个字母的数量，
再用一个哈希表存储 word 中每个字母的数量，最后将这两个哈希表的键值对逐一进行比较即可。

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