/*����һ���������飨�����������͸������������������������飨������һ��Ԫ�أ������͡�Ҫ��ʱ�临�Ӷ�ΪO(n)*/
#include<iostream>
#include<vector>

using namespace std;
int main(){
    int N;
    vector<int> vec;
    cin>>N;
    for(int i=0;i<N;i++){
        int input;
        cin>>input;
        vec.push_back(input);
    }
   int max = vec[0];
    int sum = 0;
    for(int i=0;i<N;i++){
        if(sum < 0)
        {
            sum = vec[i]; 
        }
        else
        {
            sum += vec[i];
        }
        if(sum > max)
        {
            max = sum;
        }
    }
    cout<<max;
    return 0;
}