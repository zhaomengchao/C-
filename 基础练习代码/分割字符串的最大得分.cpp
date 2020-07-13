/*
����һ�������� 0 �� 1 ��ɵ��ַ��� s ��������㲢���ؽ����ַ����ָ������ �ǿ� ���ַ�������?�� ���ַ����� �� ���ַ��������ܻ�õ����÷֡�

���ָ��ַ����ĵ÷֡�Ϊ �� ���ַ����� 0 ���������� �� ���ַ����� 1 ��������
���룺s = "00111"
�����5
���ͣ��� �����ַ��� = "00" �� �����ַ��� = "111" ʱ�����ǵõ����÷� = 2 + 3 = 5

���ӣ�https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string
*/
class Solution {
public:
    int maxScore(string s) {

        int n = s.size();
        int left = 0;
        int right = 0;
        
        for(int i = 0; i < n;i++)
        {
            if(s[i] == '1')
            {
                right++;
            }
        }
        //�ж���Ԫ��
        if(s[0] == '1')
        {
            right--;
        }
        else
        {
            left++;
        }
        int maxsum = 0;
        for(int i = 1; i < s.size();i++)
        {
            maxsum = max(maxsum, right+left);

            if(s[i]=='1')
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return maxsum;
    }
};