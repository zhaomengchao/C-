//�������г��ִ����������鳤��һ����ַ�
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len=numbers.size();
        if(len==0)
        {
            return 0;
        }
        if(len==1)
        {
            return numbers[0];
        }
        for(int i=0;i<len-1;i++)
        {
            if(numbers[i]>numbers[i+1])
            {
                swap(numbers[i],numbers[i+1]);
            }
        }
        int HashLen=numbers[len-1];
        int *Hash = new int[HashLen];//�������ֳ��ֵĴ���
	    for (int i=0; i < HashLen; i++)
		    Hash[i] = 0;
        for(int i=0;i<len;i++)
        {
            Hash[numbers[i]]++;
            if(Hash[numbers[i]]>(len/2))//�����������������һ��
                return numbers[i];
        }
        return 0;
    }
};