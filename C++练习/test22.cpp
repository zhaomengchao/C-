class Solution {
public:
    /**
     *  ����λ�϶�����������ż��λ�϶���ż��
     *  ���룺����arr�����ȴ���2
     *  len��arr�ĳ���
     *  ��arr����������λ�϶�����������ż��λ�϶���ż��
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        size_t i = 0,j = 1;
        while(i < len && j < len)
        {
            if(arr[len-1] % 2 == 0)
            {
                swap(arr[len-1] , arr[i]);
                i+=2;
            }
            else
            {
                swap(arr[len-1] , arr[j]);
                j+=2;
            }
        }
    }
};