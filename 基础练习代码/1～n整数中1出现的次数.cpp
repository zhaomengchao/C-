/*
����һ������ n ����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����

���磬����12��1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�

*/
class Solution {
public:
    int countDigitOne(int n) {
       int count = 0;
       long i = 1;//ָ�������λ������i=1����λ��i=10��ʮλ��...����Ϊn������31λ������10^31��long�洢
       while(n/i!=0){
           //n/i���Ʊ����Ĵ����������е�λ�����������
            long high = n/(10*i);//����ǰλ֮ǰ�����и�λ������high��
            long cur = (n/i)%10;//����ǰλ��¼��cur�У�������ÿ�ζ���Ҫͳ�Ƶ�ǰλ��1���ֵĴ���
            long low = n-(n/i)*i;
            if(cur == 0){
                count += high * i;
            } else if(cur == 1){
                count += high * i + low + 1;
            } else {
                count += high * i + i;
            }
            i = i * 10;//׼��������һλ
       }
       return count;
    }
};
