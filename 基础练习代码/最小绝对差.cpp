//������������� arr������ÿ��Ԫ�ض� ����ͬ��

//�����ҵ����о�����С���Բ��Ԫ�ضԣ����Ұ������˳�򷵻ء�
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        //��ԭ���鰴����������
        sort(arr.begin(),arr.end());
        //�ҳ���С��ֵ�Ƕ���
        int grater=arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;++i){
            int x=arr[i+1]-arr[i];
            if(x<grater)
                grater = x;
        }
        //����С��ֵ�ķ���couple������
        //�ٽ�couple����output��
        vector<int> couple;
        vector<vector<int>> output;
        for(int i=0;i<arr.size()-1;++i){
            couple.clear();
            int x=arr[i+1]-arr[i];
            if(x==grater){
                couple.push_back(arr[i]);
                couple.push_back(arr[i+1]);
                output.push_back(couple);
            }   
        }
        return output;
    }
};
