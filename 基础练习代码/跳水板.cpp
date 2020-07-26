/*
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，
长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

链接：https://leetcode-cn.com/problems/diving-board-lcci


*/
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        //k==0 
        if(k==0) return{};
        //shorter==longer 只有一种可能 k*longer
        if(longer==shorter) return {k*longer};
        vector<int> res;
        //longer>shorter 先找出上下界,每次都变化longer-shorter
        for(int i = shorter*k;i<=longer*k;i+=longer-shorter){
            res.push_back(i);
        }
        return res;
    }
};
