//һ�����п��Ի��ֶ��ٸ�������
//1 2 3 2 2 1
//1 2 3   2 2 1
//�����������У��������2
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
    //�����ݵĹյ�
    
    if(v[index + 1] == v[index])
    {
        index++;
        if((int)index > size - 2)
        {
            return -1;
        }
    }
    if( v[index + 1] > v[index])//������ߴ���ǰ�ߣ�����һ��С�ڵĽ��
        while(++index < size && v[index] >= v[index - 1])
        {
            
        }
    
    else
        while(++index < size && v[index] <= v[index - 1])
        {
            
        }
            
    return 1 + find(v,index);
}