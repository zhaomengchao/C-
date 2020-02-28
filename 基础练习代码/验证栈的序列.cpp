/*输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/
//验证栈的序列
//思想：建栈，入栈比对与popped每个元素，相同出栈，不相同继续比较，最后如果栈为空，则序列正确

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int size = pushed.size();
        int k = 0;
        
        for(int i = 0; i < size; i++)
        {
            s.push(pushed[i]);//push进第一个数

            //判断第一个是否与popped中第一个数是否相等
            while((!s.empty()) && (k < size) && s.top() == popped[k])
            {
                s.pop();
                k++;
            }
        }
        if(!s.empty())
        {
            return false;
        }
        return true;
    }
};