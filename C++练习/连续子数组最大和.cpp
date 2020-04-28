/*输入一个整形数组（可能有正数和负数），求数组中连续子数组（最少有一个元素）的最大和。要求时间复杂度为O(n)*/
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