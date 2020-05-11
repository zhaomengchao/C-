/*
�����ĸ����������������б�?A , B , C , D ,
�����ж��ٸ�Ԫ�� (i, j, k, l)?��ʹ��?A[i] + B[j] + C[k] + D[l] = 0��
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int,int> ab;
        for(auto a : A){
            for(auto b : B){
                int sum = a + b;
                if(!ab.count(sum))  ab[sum] = 1;
                else    ab[sum] += 1;
            }
        }
        for(auto c : C){
            for(auto d : D){
                int need = -(c + d);
                if(ab.count(need))  ans = ans + ab[need];
            }
        }
        return ans;
    }
};
