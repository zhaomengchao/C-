/*
https://leetcode-cn.com/problems/custom-sort-string/solution/chao-ji-xiao-bai-jie-fa-by-pearl-u/
�ַ���S�� T ֻ����Сд�ַ�����S�У������ַ�ֻ�����һ�Ρ�

S �Ѿ�����ĳ�ֹ����������������Ҫ����S�е��ַ�˳���T�������򡣸������˵�����S��x��y֮ǰ���֣���ô���ص��ַ�����xҲӦ������y֮ǰ��

��������һ�ַ����������ַ���T��

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
