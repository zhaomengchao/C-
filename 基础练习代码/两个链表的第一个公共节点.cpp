//����������ĵ�һ�������ڵ㡶˫ָ�롷

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* l1 = headA, * l2 = headB;
		//��l1�ĳ���
		int countL1 = 0;
		while (l1 != nullptr)
		{
			countL1++;
			l1 = l1->next;
		}
		//��l2�ĳ���
		int countL2 = 0;
		while (l2 != nullptr)
		{
			countL2++;
			l2 = l2->next;
		}
		//��l1��l2�Ĳ�ֵ,l1ָ������l2ָ�������
		l1 = headA;
		l2 = headB;
		int diff = countL1 - countL2;
		//�ж�����˭����
		if (countL1 < countL2)
		{
			l1 = headB;
			l2 = headA;
			diff = countL2 - countL1;
		}
		//l1����diff��
		while (diff--)
		{
			l1 = l1->next;
		}
		//�ҹ�ͬ�ڵ�
		while (l1 != nullptr && l2 != nullptr && l1 != l2)
		{
			l1 = l1->next;
			l2 = l2->next;
		}
		return l1;
	}
};
