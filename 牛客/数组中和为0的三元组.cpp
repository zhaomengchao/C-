/*
��Ŀ������
��������Ӻ�Ϊ0����Ԫ��
����һ����n��Ԫ�ص�����S��S���Ƿ���Ԫ��a,b,c����a+b+c=0���ҳ�����S������������������Ԫ�顣
ע�⣺
��Ԫ�飨a��b��c���е�Ԫ�ر��밴�ǽ������С�����a��b��c��
�⼯�в��ܰ����ظ�����Ԫ�顣
���磬���������� S = {-1 0 1 2 -1 -4},�⼯Ϊ(-1, 0, 1) (-1, -1, 2)
https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711?tpId=188&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fjob-code-high-week%2Fquestion-ranking


����˼·��˫ָ��
���ȶ����������������ȡ����i���������в���ѡȡ�ظ������֣�����������left,right����ת��Ϊ��left + right ��ֵ����num[i]����ʽ
��������ָ����ƶ�������
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        //ת���Ϊ��һ��ֵ��ȥ����������ֵ�ĺ�
        sort(num.begin(),num.end());
        //�洢���Ľ��
        vector<vector<int>> ans;
        
        for(int i = 0; i < num.size();i++)
        {
            if(i == 0 || num[i] != num[i-1])//��ֹ�ظ�
            {
                int left = i +1;
                int right = num.size()-1;
                
                while(left < right)
                {
                    //�ж�����Ƿ���ȣ��������ȵĻ���right--
                    while(left < right && num[i] + num[left] + num[right] > 0)
                    {
                        right--;
                    }
                    vector<int>tmp(3);
                    //��������洢����ʱ���鵱�У����б���
                    if(left < right && num[i] + num[left] +num[right] == 0)
                    {
                        tmp[0] = num[i];
                        tmp[1] = num[left];
                        tmp[2] = num[right];
                        //�洢���������
                        ans.push_back(tmp);
                        //����ɹ������left�жϣ�����ظ��������ͬ�Ķ�Ԫ��
                        while(left < right && num[left] == tmp[1])
                        {
                            left++;
                        }
                        
                    }
                    else
                    {
                        left++;
                    }
                  
                    
                    
                }
            }
        }
        return ans;
    }
};