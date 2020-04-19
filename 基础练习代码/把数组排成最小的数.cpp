/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。*/
class Solution {
public:
    static bool myfun(string a, string b)
    {
        string newab = a + b;
        string newba = b + a;
        if (newab < newba) {
            return true;
        }

        return false;
    }
    string minNumber(vector<int> &nums)
    {
        vector<string> numstr;
        string result;

        for (auto num : nums) {
            numstr.push_back(to_string(num));
        }

        sort(numstr.begin(), numstr.end(), myfun);

        for (auto s : numstr) {
            result.append(s);
        }

        return result;
    }
};
