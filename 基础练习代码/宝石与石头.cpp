 //给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。
 //S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
 //输入: J = "aA", S = "aAAbbbb"
 //输出: 3
 class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for(int i = 0; i <J.size();i++)
        {
            for(int j = 0;j < S.size();j++)
            {
                if(J[i] == S[j])
                    count++;
            }
        }
        return count;
    }
};