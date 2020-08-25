
/*
��Ŀ����https://www.nowcoder.com/practice/7bc4a1c7c371425d9faa9d1b511fe193?tpId=188&&tqId=35175&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
��ʵ�����ظ����ֵ���������Ķ��ֲ��ҡ�
����������е�һ�����ڵ��ڲ���ֵ��λ�ã���������в�����������������������鳤�ȼ�һ��
*/
class Solution {
public:
    /**
     * ���ֲ���
     * @param n int���� ���鳤��
     * @param v int���� ����ֵ
     * @param a int����vector ��������
     * @return int����
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        int left  = 0,right = n -1;
        
        while(left < right)
        {
            int mid = left + (right -  left)/2;
            if(a[mid] >= v)
            {
                //�ж�mid�Ƿ�Ϊ0������mid-1С��v
                 if (mid == 0 || a[mid - 1] < v) return mid + 1;
                else
                    right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return n+1;
    }
};