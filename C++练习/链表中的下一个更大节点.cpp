  /*链表中的下一个更大节点
  https://leetcode-cn.com/problems/next-greater-node-in-linked-list/
  */
  vector<int> nextLargerNodes(ListNode* head) {

        //将链表放入结果数组
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }

        stack<int> stack;

        //从右往左遍历
        for (int i = (int)res.size() - 1; i >= 0; --i)
        {
            int cur = res.at(i); //先暂存当前元素

            while (!stack.empty() && cur >= stack.top()) //注意: 等于号不能少 等于时也需要出栈 这里是找严格大于的数
            {
                stack.pop();  //淘汰小的 留下更大的
            }
            
            res.at(i) = (stack.empty() ? 0 : stack.top()); //栈空 右边没有更大的

            stack.push(cur);
        }

        return res;
    }
};
//单调栈，不使用辅助数组，直接修改结果数组 时间复杂度O(N) 空间复杂度O(N)
