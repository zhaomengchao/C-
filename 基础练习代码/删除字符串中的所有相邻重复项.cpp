//例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，
//这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，
//其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for(char c: S)
            if(res.size() && res.back() == c)
                res.pop_back();
            else
                res += c;
        return res;
    }
};