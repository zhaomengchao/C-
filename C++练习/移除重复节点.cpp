/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
*/
ListNode *Solution::removeDuplicateNodes(ListNode *head) {
    if (!head) return head;      // 链表为空
    unordered_set<int> existed;  // 临时缓冲区
    ListNode *last;              // 存储上一个节点
    auto ans = head;             // 存储头结点
    while (head) {
        // 如果节点值重复
        if (existed.count(head->val)) {
            auto tmp = head;
            head = head->next;
            last->next = head;
            tmp->next = nullptr;
            delete tmp;
        } else {
            existed.insert(head->val);
            last = head;
            head = head->next;
        }
    }
    return ans;
}

 