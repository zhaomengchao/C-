/*
�߶ȼ����
https://leetcode-cn.com/problems/height-checker/
˼·��
����ֻ��Ը���������зǵݼ�����Ȼ��Ƚ�ͬһλ�õ������Ƿ���ͬ 
��ͬ��num ++ ����ʱ������ͳ�Ƴ���num���� �� ԭ���� ����� �ǵݼ����� ����С�ƶ�������

*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;//���鸳ֵ
        sort(heights.begin(),heights.end());
        int num = 0;
        for(int i = 0;i < heights.size();i++)
        {
            if(tmp[i] != heights[i])
                num++;
        }
        return num;
    }
};