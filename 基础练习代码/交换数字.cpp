/*
��������
��дһ��������������ʱ������ֱ�ӽ���numbers = [a, b]��a��b��ֵ��

ʾ����

����: numbers = [1,2]
���: [2,1]
*/
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        if(numbers[0]>0 && numbers[1]>0 || numbers[0]<0 && numbers[1]<0)
        {
            numbers[0]=-numbers[0];
            numbers[0]=numbers[0]+numbers[1];
            numbers[1]=numbers[1]-numbers[0];
            numbers[0]=numbers[0]+numbers[1];
        }
        else{
            numbers[0]=numbers[0]+numbers[1];
            numbers[1]=numbers[0]-numbers[1];
            numbers[0]=numbers[0]-numbers[1];
        }
        return numbers;
    }
};
