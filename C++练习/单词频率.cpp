/*设计一个方法，找出任意指定单词在一本书中的出现频率。

你的实现应该支持如下操作：

WordsFrequency(book)构造函数，参数为字符串数组构成的一本书
get(word)查询指定单词在数中出现的频率
*/

class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        for(auto word : book)
        {
            res[word]++;
        }
    }
    
    int get(string word) {
        return res[word];
    }
private:
    unordered_map<string,int> res;

};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */