//����һ�����ǵݼ�˳��������������� A��
//����ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������
//ʾ�� 1��

//���룺[-4,-1,0,3,10]
//�����[0,1,9,16,100]

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> tmp;
        for(int i = 0; i < A.size();i++)
        {
            tmp.push_back(A[i]*A[i]);
        }
        sort(tmp.begin(),tmp.end());
        return tmp;
    }
};