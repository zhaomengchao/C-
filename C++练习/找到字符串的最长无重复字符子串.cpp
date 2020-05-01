//给定一个数组arr，返回arr的最长无的重复子串的长度(无重复指的是所有字母都不相同)。
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int >dp(n, 1);
    int max = 0;
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])           
            continue;
        dp[i]++;
        int j = i-1;
        for (int k = dp[i - 1]; k > 1; k--) {
            if (dp[j--] == 1)
                break;
            if (arr[i] != arr[j])
                dp[i]++;
            else {
                break;
            }
        }
        if (dp[i] > max)
            max = dp[i];
    }
    cout << max << endl;
    return 0;
}