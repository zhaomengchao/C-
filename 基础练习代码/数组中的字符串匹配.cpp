
/*
输入：words = ["mass","as","hero","superhero"]
输出：["as","hero"]
解释："as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
["hero","as"] 也是有效的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-matching-in-an-array
*/
class Solution {
public:
     static bool lengthcompare(string& a, string& b){
        if(a.length()<b.length()){
            return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
         vector<string> result;
         bool flag;
         sort(words.begin(),words.end(),lengthcompare);
         for(int i = 0;i < words.size()-1;i++)
         {
             for(int j = i+1;j < words.size();j++)
             {
                 flag = false;
                 if(-1 != words[j].find(words[i]))
                 {
                     flag = true;
                     break;
                 }
             }
             if(flag)
             {
                 result.push_back(words[i]);
             }
         }
         return result;
    }
};