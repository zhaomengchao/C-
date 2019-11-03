//��һ���Ź�������飬����n����������������������������һ�����ȵ���λ��
//���磬ԭ����Ϊ[1,2,3,4,5,6]��������λ5��λ�ü������[6,1,2,3,4,5],
//���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������

class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
    int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            if(A[mid] == x)
                return mid;
            if(A[left] < A[mid])
            {
	//�ж�x�Ƿ����������
                if(A[left] <= x && x < A[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(A[mid] < x && x <= A[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        
        return -1;
    }
};