/*
����һ����������arr���ҵ�������δ���ֵ���С������
����arr = [-1, 2, 3, 4]������1
arr = [1, 2, 3, 4]������5
[Ҫ��]
ʱ�临�Ӷ�ΪO(n)O(n)���ռ临�Ӷ�ΪO(1)O(1)
*/
class Solution {
public:
    /**
     * return the min number
     * @param arr int����vector the array
     * @return int����
     */
    int minNumberdisappered(vector<int>& arr) {
        // write code here
        int len = arr.size();
        int res = 1;
        int count = 0;
        while(count <= len)
        {
            if(arr[count] == res)
            {
                count = 0;
                res++;
            }
            count++;
        }
        return res;
    }
};