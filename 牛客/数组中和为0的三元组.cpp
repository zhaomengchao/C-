/*
题目描述：
数组中相加和为0的三元组
给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。
注意：
三元组（a、b、c）中的元素必须按非降序排列。（即a≤b≤c）
解集中不能包含重复的三元组。
例如，给定的数组 S = {-1 0 1 2 -1 -4},解集为(-1, 0, 1) (-1, -1, 2)
https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711?tpId=188&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fjob-code-high-week%2Fquestion-ranking


解题思路：双指针
首先对数组进行排序，依次取出第i个数，并切不能选取重复的数字，接下来定义left,right将其转化为，left + right 的值等于num[i]的形式
进行左右指针的移动来进行
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        //转变成为定一个值，去找另外两个值的和
        sort(num.begin(),num.end());
        //存储最后的结果
        vector<vector<int>> ans;
        
        for(int i = 0; i < num.size();i++)
        {
            if(i == 0 || num[i] != num[i-1])//防止重复
            {
                int left = i +1;
                int right = num.size()-1;
                
                while(left < right)
                {
                    //判断相加是否相等，如果不相等的话，right--
                    while(left < right && num[i] + num[left] + num[right] > 0)
                    {
                        right--;
                    }
                    vector<int>tmp(3);
                    //如果相等则存储到临时数组当中，进行保存
                    if(left < right && num[i] + num[left] +num[right] == 0)
                    {
                        tmp[0] = num[i];
                        tmp[1] = num[left];
                        tmp[2] = num[right];
                        //存储到结果数组
                        ans.push_back(tmp);
                        //保存成功后进行left判断，如果重复会出现相同的二元组
                        while(left < right && num[left] == tmp[1])
                        {
                            left++;
                        }
                        
                    }
                    else
                    {
                        left++;
                    }
                  
                    
                    
                }
            }
        }
        return ans;
    }
};