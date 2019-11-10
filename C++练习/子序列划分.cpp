//一个序列可以划分多少个子序列
//1 2 3 2 2 1
//1 2 3   2 2 1
//有两个子序列，所以输出2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find(const vector<int> & v,int index)
{
    int size = v.size();
    if((int)index < 0 || (int)index >= size)
    {
        return 0;
    }
    else if((int)index > size - 2)
    {
        return 1;
    }
    //找数据的拐点
    
    if(v[index + 1] == v[index])
    {
        index++;
        if((int)index > size - 2)
        {
            return -1;
        }
    }
    if( v[index + 1] > v[index])//如果后者大于前者，找下一个小于的结点
        while(++index < size && v[index] >= v[index - 1])
        {
            
        }
    
    else
        while(++index < size && v[index] <= v[index - 1])
        {
            
        }
            
    return 1 + find(v,index);
}