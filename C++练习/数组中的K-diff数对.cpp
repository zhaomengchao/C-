/*
����һ�����������һ������?k, ����Ҫ���������ҵ���ͬ��?k-diff ���ԡ�
���ｫ?k-diff?���Զ���Ϊһ�������� (i, j), ���� i �� j ���������е����֣�������֮��ľ���ֵ��?k.

����: [3, 1, 4, 1, 5], k = 2
���: 2
����: ������������ 2-diff ����, (1, 3) �� (3, 5)��
����������������1��������ֻӦ���ز�ͬ�����Ե�������
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;

        if(k < 0)//�ÿӲ�ֹ��-1?����-157
            return 0;

        if(k == 0) {
        //��k=0ʱ����ʵ��������������û���ظ�Ԫ��?���ظ�Ԫ�ظ������ڵ���2ʱ?���Ƕ���Ϊֻ��1��K-diff
            for(int i = 0; i < nums.size(); i++) {
            ++map[nums[i]];
            if(map[nums[i]] == 2)
                count++;
            }
            return count;
        }
        //kΪ��������ʱ���ȹ���hash����value��ʼ��Ϊ0.
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = 0;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i] - k) != map.end()) {
            //��nums[i]-k�����������С�ע��nums[i]-k��ȻС��nums[i]?diff����Ϊ{num[i],?nums[i]-k}
                if(map[nums[i]] == 0 ) {//�Ѿ����ڵ�diff�����л�û�г��ֹ�nums[i]Ϊ��һ����
                    count++;//��������+1
                    map[nums[i]] = 1;//��nums[i]��ǣ���ʾ�Ѿ���nums[i]��ͷ�������ˣ����治�ٿ���
                }
            }
        }
        return count;
    }
};

