
//你和你的朋友，两个人一起玩 Nim 游戏：
//桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。
//输入: 4
//输出: false 
//解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
//?因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
class Solution {
public:
    bool canWinNim(int n) {
        
        if(n % 4 != 0)
        {
            return true;
        }
        return false;
    }
};