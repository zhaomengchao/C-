
/*
���룺words = ["mass","as","hero","superhero"]
�����["as","hero"]
���ͣ�"as" �� "mass" �����ַ�����"hero" �� "superhero" �����ַ�����
["hero","as"] Ҳ����Ч�Ĵ𰸡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/string-matching-in-an-array
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