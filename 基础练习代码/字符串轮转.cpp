/*
字符串轮转
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

示例1:

 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-rotation-lcci
*/
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if(m == 0)
        {
            return true;
        }
        if(n != m)
        {

            return false;
        }
        for(int i = 0; i < m;i++)
        {
            if(s1[i] == s2[0]){
                if(s1.substr(0, i) == s2.substr(m - i) && s1.substr(i) == s2.substr(0, m - i))
                    return true;
            }
        }
        return false;
    }
};