//��дһ�������������ַ��������е������ǰ׺��
//��������ڹ���ǰ׺�����ؿ��ַ���?""��

//����: ["flower","flow","flight"]
//���: "fl"

//����: ["dog","racecar","car"]
//���: ""
//����: ���벻���ڹ���ǰ׺��

class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) 
            return "";//strs���ַ�������Ϊ��
		string prefix = strs[0];//�����һ���ַ���Ϊ����ǰ׺
		for (int i=1;i<strs.size();i++)//�ж�ÿһ���ַ������Ƿ���prefix��
		{
			while (strs[i].find(prefix)!=0)//���������prefix����prefix���ȼ�1���ٴ��ж�prefix-1�Ƿ�Ϊ���Ӵ���==0��ʾ���и��ִ�����ֱ��prefixΪ�գ�
			{
				if (prefix == "") return "";//���prefixΪ�մ�����˵������ǰ׺Ϊ��
				prefix = prefix.substr(0, prefix.length() - 1);
			}
		}
		return prefix;
	}
};