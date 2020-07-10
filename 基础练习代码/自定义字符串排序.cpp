/*
https://leetcode-cn.com/problems/custom-sort-string/solution/chao-ji-xiao-bai-jie-fa-by-pearl-u/
字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。

S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。

返回任意一种符合条件的字符串T。

*/
class Solution {
public:
    string customSortString(string S, string T) {
        int s=S.size();
        int t=T.size();
        int i=0,j=0;
        int flag=0;

        for(i=0;i<s;i++)
            for(j=flag;j<t;j++){
                if(S[i]==T[j]){
                    char a=T[j];
                    T[j]=T[flag];
                    T[flag++]=a;
                }
            }
        
       return T;
    }
};
