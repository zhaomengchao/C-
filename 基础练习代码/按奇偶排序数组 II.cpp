//给定一个非负整数数组?A， A 中一半整数是奇数，一半整数是偶数。

//对数组进行排序，以便当?A[i] 为奇数时，i?也是奇数；当?A[i]?为偶数时， i 也是偶数。


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len_A = A.size();
        int t = 0;
        int i=0,j=1;
        while(i<len_A&&j<len_A){
            if(A[i]%2==1&&A[j]%2==0){
                t = A[i];
                A[i]=A[j];
                A[j]=t;
                i = i+2;
                j = j+2;
            }else if(A[i]%2==0) i=i+2;
            else if(A[j]%2==1) j = j+2;
            if(i>=len_A||j>=len_A) break;
        }
        return A;
    }
};
