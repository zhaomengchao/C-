//����һ������������ý�� head��������ÿ������ֵ���� 0 ���� 1����֪��������һ���������ֵĶ����Ʊ�ʾ��ʽ��

//���㷵�ظ���������ʾ���ֵ� ʮ����ֵ 
//���룺head = [1,0,1]
/�����5
//���ͣ��������� (101) ת��Ϊʮ������ (5)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        int tmp = 0;
        while(cur != nullptr)
        {
            tmp = tmp * 2 + cur->val;
            cur=cur->next;
        }
        return tmp;
    }
};