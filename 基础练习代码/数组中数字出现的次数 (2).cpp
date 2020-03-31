class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // λ���㡣�������Ϊ�������֡�ÿһ����ֻ����һ������һ�ε����֣����ಿ��Ϊ�ظ����֡�
        // ���������һ��������㡣���ݽ���г���1��λ�ã����Խ������Ϊ������
        int len = nums.size();
        vector<int> res(2,0);
      
        
        int temp = 0; // ���ڶ�nums�������һ���������
        for(int i=0;i<len;i++){
            temp = temp^nums[i];
        }
        // Ѱ��temp�����Ƶ�һ��Ϊ1��λ��
        int pos = 0; //��¼Ҫ���Ƶ�λ��
        while((temp&1)!=1){
            pos++;
            temp = temp>>1;
        }
        // cout<<pos<<endl;
        //���ݸ�posλ�ý�nums��Ϊ�����֣�ֱ�ӽ���λ����
        for(int i=0;i<len;i++){
            if((nums[i]>>pos)&1==1){
                res[0] = res[0]^nums[i];
            }
            else res[1] = res[1]^nums[i];
        }
        return res;
    }
};