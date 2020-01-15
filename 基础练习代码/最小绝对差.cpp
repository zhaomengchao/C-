//给你个整数数组 arr，其中每个元素都 不相同。

//请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        //将原数组按照升序排序
        sort(arr.begin(),arr.end());
        //找出最小差值是多少
        int grater=arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;++i){
            int x=arr[i+1]-arr[i];
            if(x<grater)
                grater = x;
        }
        //将最小差值的放入couple数组中
        //再将couple放入output中
        vector<int> couple;
        vector<vector<int>> output;
        for(int i=0;i<arr.size()-1;++i){
            couple.clear();
            int x=arr[i+1]-arr[i];
            if(x==grater){
                couple.push_back(arr[i]);
                couple.push_back(arr[i+1]);
                output.push_back(couple);
            }   
        }
        return output;
    }
};
