//给你一个整数 n，请你返回一个 由两个整数组成的列表 [A, B]，满足：

//A 和 B 都是无零整数
//A + B = n
class Solution {
public:
    bool check(int x)
    {
        if (!x) return false;
        while(x)
        {
           if (0 == (x%10)) return false;
           x/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i<=n/2; i++)
        {
            if (check(i) && check(n-i)) return vector<int>({i,n-i});
        }

        return vector<int>({-1,-1});
    }
};
