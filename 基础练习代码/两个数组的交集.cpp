//����: nums1 = [1,2,2,1], nums2 = [2,2]
//���: [2]


//����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//���: [9,4]


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>perseve;
        for(auto v:nums1)    //���� v����
        {
		//��nums2�в���������ͬ
            vector<int>::iterator it = find(nums2.begin(),nums2.end(),v); 
			//û�鵽�ͷ��ص����� nums2.end�������鵽�ͷ���ָ��vԪ�صĵ�����
            if(it!=nums2.end())        
            perseve.insert(*it);
        }
        vector<int>arr(perseve.begin(),perseve.end());    //�õ�������Χ��ʼ��vector����
        return arr;
    }
};