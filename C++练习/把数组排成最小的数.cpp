/*
 �������ų���С����
����: [10,2]
���: "102"
ʾ�� 2:

����: [3,30,34,5,9]
���: "3033459"
*/
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

