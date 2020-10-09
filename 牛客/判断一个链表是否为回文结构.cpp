/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
//����һ���������жϸ������Ƿ�Ϊ���Ľṹ��
class Solution {
public:
    /**
     * 
     * @param head ListNode�� the head
     * @return bool������
     */
    bool isPail(ListNode* head) {
        // write code here
        vector<int> res;
        ListNode* cur = head;
        while(cur)
        {
            res.push_back(cur->val);
            cur = cur->next;
        }
        int i = 0; 
        int j = res.size()-1;
        
        while( i < j)
        {
            if(res[i] == res[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};