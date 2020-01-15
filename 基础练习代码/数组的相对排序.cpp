//给你两个数组，arr1 和?arr2，

//arr2?中的元素各不相同
//arr2 中的每个元素都出现在?arr1?中
//对 arr1?中的元素进行排序，使 arr1 中项的相对顺序和?arr2?中的相对顺序相同
//未在?arr2?中出现过的元素需要按照升序放在?arr1?的末尾。


class Solution {
public:
     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int tmp = 0;
        for(int i = 0;i<arr2.size();++i)
           for(int j = 0;j<arr1.size();++j){
               if(arr1[j] == arr2[i]){
                   swap(arr1[j],arr1[tmp]); ++tmp;
               }
           }
           sort(arr1.begin()+tmp,arr1.end());
           return arr1;
    }
};