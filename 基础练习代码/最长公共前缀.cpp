//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串?""。

//输入: ["flower","flow","flight"]
//输出: "fl"

//输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。

class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) 
            return "";//strs无字符串，则为空
		string prefix = strs[0];//假设第一个字符串为公共前缀
		for (int i=1;i<strs.size();i++)//判断每一个字符串中是否含有prefix，
		{
			while (strs[i].find(prefix)!=0)//如果不含有prefix，则将prefix长度减1，再次判断prefix-1是否为其子串（==0表示含有该字串），直到prefix为空，
			{
				if (prefix == "") return "";//如果prefix为空串，则说明公共前缀为空
				prefix = prefix.substr(0, prefix.length() - 1);
			}
		}
		return prefix;
	}
};